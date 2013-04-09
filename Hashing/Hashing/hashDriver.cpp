#include <conio.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include "hash.h"

using namespace std;

enum Roles {USER, ADMIN};

struct user {
	string email;
	string password;
	Roles role;
};

bool operator!= (user u1, user u2) {
	return (u1.email != u2.email);
}

bool operator== (user u1, user u2) {
	return ((u1.email == u2.email) && (u1.password == u2.password));
}

ostream& operator<< (ostream& os, user& u) {
	os << u.email;
	return os;
}

// Exception classes
class AuthenticationError {
};

class DuplicateAccount {
};

class AccountNotFound {
};

class ConfirmationError {
};

class PermissionError {
};

const string PASSWORD_FILENAME = "password.txt"; // Should be put in protected directory

void CreateAccount(Hash<user> &users, Roles role);
void RemoveAccount(Hash<user> &users, user adminUser);
void UpdatePasswordFile(Hash<user> &users);
void ImportPasswordFile(Hash<user> &users);
user AuthenticateUser(Hash<user> &users, string address, string password);
void DisplayMenu(Roles role);
void ChangePassword(Hash<user> &users, user &u);
string InputPassword(string prompt);
void ShowUsers(Hash<user> users); // does not change users
void AddUser(Hash<user> &users);
void DeleteUser(Hash<user> &users, user adminUser);
void PerformanceTest();

int main() {
	user emptyUser;
	emptyUser.email = "empty";
	emptyUser.password = "";

	user deletedUser;
	deletedUser.email = "deleted";
	deletedUser.password = "";

	Hash<user> users = Hash<user>(emptyUser, deletedUser, LINEAR);
	user loggedInUser = emptyUser;

	// check to see if password file exists
	struct stat buf;
	ofstream outFile;

	// if does not exist, create admin account
	if(stat(PASSWORD_FILENAME.c_str(), &buf) == -1) {
		bool isCreated = false;
		do {
			try {
				CreateAccount(users, ADMIN);
				cout << "Admin account created" << endl << endl;
				UpdatePasswordFile(users);
				isCreated = true;
			} catch (ConfirmationError) {
				cout << "Password and confirmation do not match. Account not created."  << endl << endl;
			}
		} while (!isCreated);
	} else
		ImportPasswordFile(users);

	do
	{
		cout << "Please Login" << endl;
		// read in address and password
	
		do
		{
			string address;
			string password;

			cout << "Enter email address: ";
			getline(cin, address);
	
			password = InputPassword("Enter password: ");
			
			try {
				loggedInUser = AuthenticateUser(users, address, password);
			} catch(AuthenticationError) {
				cout << "Incorrect username and password" << endl << endl;
			}

		} while (loggedInUser == emptyUser);

		system("CLS");
		cout << "Welcome back" << ((loggedInUser.role == ADMIN) ? " Admin" : "") << "!" << endl << endl;

		char command;
		do
		{
			DisplayMenu(loggedInUser.role);

			cin >> command;
			cout << endl;

			if (command == 'C' || command == 'c')
			{
				system("CLS");
				cin.ignore();
				ChangePassword(users, loggedInUser);
				system("Pause");
				system("CLS");
			}
			else if (command == 'L' || command == 'l')
			{
				system("CLS");
				loggedInUser = emptyUser;
				cout << "You have been logged out." << endl << endl;
				break;
			}
			else if (command == 'P' || command == 'p')
			{
				
				system("CLS");
				PerformanceTest();
				system("Pause");
				system("CLS");
			}
			else if ((command == 'S' || command == 's') && loggedInUser.role == ADMIN)
			{
				system("CLS");
				ShowUsers(users);
				system("Pause");
				system("CLS");
			}
			else if ((command == 'A' || command == 'a') && loggedInUser.role == ADMIN)
			{
				system("CLS");
				cin.ignore();
				AddUser(users);
				system("Pause");
				system("CLS");
			}
			else if ((command == 'D' || command == 'd') && loggedInUser.role == ADMIN)
			{
				system("CLS");
				cin.ignore();
				DeleteUser(users, loggedInUser);
				system("Pause");
				system("CLS");
			}
			else {
				cout << "Invalid command! Please try again.";
				system("Pause");
				system("CLS");
			}
		} while (command != 'L' || command != 'l');
		
		system("Pause");
		system("CLS");
		cin.ignore();
	} while (true);

	return 0;
}

void CreateAccount(Hash<user> &users, Roles role)
// Function: Creates an account and stores in hash
// Pre:		 users is a valid hash
// Post:	 users contains new account, throws exception if account already exists
{
	// read in account and password
	string address;
	string password;
	string confirmation;

	cout << "Enter " << ((role == ADMIN) ? "Admin " : "") << "email address: ";
	getline(cin, address);
	
	password = InputPassword("Enter password: ");
	confirmation = InputPassword("Re-enter password: ");

	if (strcmp(password.c_str(), confirmation.c_str()) != 0) {
		throw ConfirmationError();
	}

	// create new account
	user newUser;
	newUser.email = address;
	newUser.password = password;
	newUser.role = role;

	QueueType<user> items = QueueType<user>(users.RetrieveAllItems());
	while (!items.IsEmpty())
	{
		user u;
		items.DeQueue(u);
		if (strcmp(newUser.email.c_str(), u.email.c_str()) == 0)
			throw DuplicateAccount();
	}

	users.InsertItem(newUser);
}

void RemoveAccount(Hash<user> &users, user adminUser)
// Function: Removes account from users
// Pre:		 users is a valid hash
// Post:	 users does not contain account, throws exception if account is not found
{
	// read in account
	string address;
	string adminPassword;

	cout << "Enter email address: ";
	getline(cin, address);

	if (strcmp(address.c_str(), adminUser.email.c_str()) == 0)
		throw PermissionError();
	
	adminPassword = InputPassword("Enter admin password to confirm removal: ");

	if (strcmp(adminPassword.c_str(), adminUser.password.c_str()) != 0) {
		throw ConfirmationError();
	}

	// create temp account
	user tempUser;
	tempUser.email = address;
	
	QueueType<user> items = QueueType<user>(users.RetrieveAllItems());
	
	bool isFound = false;
	while (!items.IsEmpty())
	{
		user u;
		items.DeQueue(u);
		if (strcmp(tempUser.email.c_str(), u.email.c_str()) == 0) {
			tempUser.password = u.password;
			tempUser.role = u.role;
			isFound = true;
		}
	}

	if (!isFound)
		throw AccountNotFound();

	users.DeleteItem(tempUser);
}

void UpdatePasswordFile(Hash<user> &users)
// Function: Updates the password file with content of users
// Pre:		 users is a valid hash
// Post:	 password file exists with updated content of users
{
	ofstream outFile;
	outFile.open(PASSWORD_FILENAME.c_str(), ios::trunc);
	
	QueueType<user> temp = QueueType<user>(users.RetrieveAllItems());

	while (!temp.IsEmpty()) {
		user tempUser;
		temp.DeQueue(tempUser);
		outFile << tempUser.email << ":" << tempUser.role << ":" << tempUser.password;
		if (temp.Length() > 0)
			outFile << endl;
	}

	outFile.close();
}

void ImportPasswordFile(Hash<user> &users)
// Function: Reads the password file and stores users in the hash
// Pre:		 password file exists, user is a valid hash
// Post:	 users in password file are stored in hash
{
	ifstream inFile;
	inFile.open(PASSWORD_FILENAME.c_str());

	while(!inFile.eof())
	{
		user newUser;
		string account, name, role, passwrd;
		getline(inFile, account);

		// parse account
		unsigned int roleSeparatorIndex;
		for (unsigned int i = 0; i < account.size(); i++) {
			if (account[i] == ':') {
				roleSeparatorIndex = i;
				break;
			}
		}

		// get name
		name = "";
		name.append(account, 0, roleSeparatorIndex);

		unsigned int pwdSeparatorIndex;
		for (unsigned int i = roleSeparatorIndex + 1; i < account.size(); i++) {
			if (account[i] == ':') {
				pwdSeparatorIndex = i;
				break;
			}
		}

		// get role
		role = "";
		role.append(account, roleSeparatorIndex + 1, pwdSeparatorIndex - roleSeparatorIndex - 1);

		// get password
		passwrd = "";
		passwrd.append(account, pwdSeparatorIndex + 1, account.length() - pwdSeparatorIndex - 1);

		newUser.email = name;
		newUser.password = passwrd;
		newUser.role = (Roles)atoi(role.c_str());

		users.InsertItem(newUser);
	}
}

user AuthenticateUser(Hash<user> &users, string address, string password)
// Function: Finds the user in hash and checks the encrypted password
// Pre:		 users is a valid hash, password is encrypted
// Post:	 returns user if found and encrypted password matches, else throws exception
{
	user tmpUser;
	tmpUser.email = address;
	tmpUser.password = password;

	try {
		return users.RetrieveItem(tmpUser);
	} catch (ItemNotFound) {
		throw AuthenticationError();
	}
}

void DisplayMenu(Roles role)
// Function: Displays menu for a user or admin
// Pre:		 None 
// Post:	 Menu will be displayed on cout
{
	cout << "Menu" << endl;
	cout << "<C>hange password" << endl;
	cout << "<P>erformance test" << endl;
	if (role == ADMIN)
	{
		cout << "<S>how users" << endl;
		cout << "<A>dd user" << endl;
		cout << "<D>elete user" << endl;
	}
	cout << "<L>og out" << endl;
}

void ChangePassword(Hash<user> &users, user &u)
// Function: Changes user password
// Pre:		 users is a valid hash, u is a valid user
// Post:	 user u in users contain new password if old password is valid and new password and confirmation match
{
	string oldPassword, newPassword, confirmation;

	oldPassword = InputPassword("Please enter old password: ");
	newPassword = InputPassword("Please enter new password: ");
	confirmation = InputPassword("Please re-enter new password: ");

	// authenticate old password
	if (strcmp(oldPassword.c_str(), u.password.c_str()) == 0) {
		// confirm new password
		if (strcmp(newPassword.c_str(), confirmation.c_str()) == 0) {
			users.DeleteItem(u);
			u.password = newPassword;
			users.InsertItem(u);
			UpdatePasswordFile(users);
			cout << "Password has been changed." << endl << endl;
		}
		else
			cout << "New password and confirmation do not match. Password not changed." << endl << endl;
	}
	else
		cout << "Old password incorrect. Password not changed." << endl << endl; 
}

string InputPassword(string prompt)
// Function: Returns encrypted password string from hidden user input
// Pre:		 None
// Post:	 function value = (encrypted password string)
{
	cout << prompt;
	string password = "";
	char c = ' ';
	while (c != 13)
	{
		c = _getch();
		if (c != 13)
		{
			password += c;
			cout << "*";
		}
	}
	cout << endl;

	return Hash<user>::GetMD5Hash(password);
}

void ShowUsers(Hash<user> users)
// Function: Shows all users and roles in hash table
// Pre:		 users is a valid hash
// Post:	 users displayed on cout
{
	QueueType<user> items = QueueType<user>(users.RetrieveAllItems());

	while (!items.IsEmpty())
	{
		user u;
		items.DeQueue(u);
		cout << ((u.role == ADMIN) ? 'A' : 'U') << ":" << u.email << endl;
	}

	cout << endl;
}

void AddUser(Hash<user> &users)
// Function: Adds new user to hash
// Pre:		 users is a valid hash
// Post:	 users contains new user
{
	try {
		CreateAccount(users, USER);
		cout << "User account created" << endl << endl;
		UpdatePasswordFile(users);
	} catch(DuplicateAccount) {
		cout << "Account already exists" << endl << endl;
	} catch (ConfirmationError) {
		cout << "Password and confirmation do not match. Account not created."  << endl << endl;
	}
}

void DeleteUser(Hash<user> &users, user adminUser)
// Function: Deletes user from hash
// Pre:		 users is a valid hash
// Post:	 users does not contain user
{
	try{
		RemoveAccount(users, adminUser);
		cout << "User account removed" << endl << endl;
		UpdatePasswordFile(users);
	} catch(AccountNotFound) {
		cout << "Account not found" << endl << endl;
	} catch(PermissionError) {
		cout << "You do not have permission to remove this account." << endl << endl;
	} catch(ConfirmationError) {
		cout << "Admin password invalid. Account not removed." << endl;
	}
}

void PerformanceTest()
// Function: Performance comparison of two hashes using different collision handling
// Pre:		 None
// Post:	 None
{
	Hash<int> hashL = Hash<int>(-1, -2, LINEAR);
	Hash<int> hashQ = Hash<int>(-1, -2, QUADRATIC);

	for (int i = 0; i < 50; i++)
	{
		hashL.InsertItem(i);
		hashQ.InsertItem(i);
	}

	cout << "Insert 50 consecutive integers" << endl;
	cout << "Total Linear Collisions: " << hashL.getCollisions() << endl;
	cout << "Total Quadratic Collisions: " << hashQ.getCollisions() << endl;
	cout << "Average Linear Collisions: " << (hashL.getCollisions() / 50) << endl;
	cout << "Average Quadratic Collisions: " << (hashQ.getCollisions() / 50) << endl << endl;

	hashL.resetCollisions();
	hashQ.resetCollisions();

	int searchSuccessCountL = 0;
	int searchSuccessCountQ = 0;
	for (int i = 0; i < 50; i++)
	{
		if (hashL.Search(i))
			searchSuccessCountL++;
		if (hashQ.Search(i))
			searchSuccessCountQ++;
	}

	cout << "Search 50 consecutive integers" << endl;
	cout << "Linear Searches successful: " << searchSuccessCountL << endl;
	cout << "Quadratic Searches successful: " << searchSuccessCountQ << endl;
	cout << "Total Linear Collisions: " << hashL.getCollisions() << endl;
	cout << "Total Quadratic Collisions: " << hashQ.getCollisions() << endl;
	cout << "Average Linear Collisions: " << (hashL.getCollisions() / 50) << endl;
	cout << "Average Quadratic Collisions: " << (hashQ.getCollisions() / 50) << endl << endl;

	hashL.resetCollisions();
	hashQ.resetCollisions();
	
	int searchUnsuccessCountL = 0;
	int searchUnsuccessCountQ = 0;
	for (int i = 50; i < 100; i++)
	{
		if (!hashL.Search(i))
			searchUnsuccessCountL++;
		if (!hashQ.Search(i))
			searchUnsuccessCountQ++;
	}

	cout << "Search 50 consecutive integers" << endl;
	cout << "Linear Searches unsuccessful: " << searchUnsuccessCountL << endl;
	cout << "Quadratic Searches unsuccessful: " << searchUnsuccessCountQ << endl;
	cout << "Total Linear Collisions: " << hashL.getCollisions() << endl;
	cout << "Total Quadratic Collisions: " << hashQ.getCollisions() << endl;
	cout << "Average Linear Collisions: " << (hashL.getCollisions() / 50) << endl;
	cout << "Average Quadratic Collisions: " << (hashQ.getCollisions() / 50) << endl << endl;
	
	cout << "Linear Hash contents:" << endl;
	hashL.Display(cout);
	cout << endl;
	cout << "Quadratic Hash contents:" << endl;
	hashQ.Display(cout);
	cout << endl;
}