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

class AuthenticationError {
};

const string PASSWORD_FILENAME = "password.txt"; // Should be put in protected directory
void CreateAdminAccount(Hash<user> &users);
void UpdatePasswordFile(Hash<user> &users);
void ImportPasswordFile(Hash<user> &users);
user AuthenticateUser(Hash<user> &users, string address, string password);

int main() {
	user emptyUser;
	emptyUser.email = "empty";
	emptyUser.password = "";

	user deletedUser;
	deletedUser.email = "deleted";
	deletedUser.password = "";

	Hash<user> users = Hash<user>(emptyUser, deletedUser);
	user loggedInUser = emptyUser;

	// check to see if password file exists
	struct stat buf;
	ofstream outFile;

	// if does not exist, create admin account
	if(stat(PASSWORD_FILENAME.c_str(), &buf) == -1) {
		CreateAdminAccount(users);
		cout << "Admin account created" << endl;
		UpdatePasswordFile(users);
	} else
		ImportPasswordFile(users);

	cout << "Please Login" << endl;
	// read in address and password
	string address;
	string password;

	do
	{
		cout << "Enter email address: ";
		getline(cin, address);
	
		// currently displays in text format
		cout << "Enter password: ";
		getline(cin, password);

		try {
			loggedInUser = AuthenticateUser(users, address, password);
		} catch(AuthenticationError) {
			cout << "Incorrect username and password" << endl << endl;
		}

	} while (loggedInUser == emptyUser);

	cout << "Welcome back" << ((loggedInUser.role == ADMIN) ? " Admin" : "") << "!" << endl;
	
	system("Pause");
	return 0;
}

void CreateAdminAccount(Hash<user> &users)
// Function: Creates an admin account and stores in hash
// Pre:		 users is a valid hash
// Post:	 users contains new admin account
{
	// read in admin account and password
	string address;
	string password;

	cout << "Enter admin email address: ";
	getline(cin, address);
	
	// currently displays in text format
	cout << "Enter password: ";
	getline(cin, password);

	// create admin account
	user newUser;
	newUser.email = address;
	newUser.password = Hash<user>::GetMD5Hash(password);
	newUser.role = ADMIN;

	users.InsertItem(newUser);
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
		if (temp.Length() > 1)
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
// Pre:		 users is a valid hash, password is cleartext
// Post:	 returns user if found and encrypted password matches, else throws exception
{
	user tmpUser;
	tmpUser.email = address;
	tmpUser.password = Hash<user>::GetMD5Hash(password);

	try {
		return users.RetrieveItem(tmpUser);
	} catch (ItemNotFound) {
		throw AuthenticationError();
	}
}