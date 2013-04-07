#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include "hash.h"

using namespace std;

struct user {
	string email;
	string password;
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

const string PASSWORD_FILENAME = "password.txt"; // Should be put in protected directory
void UpdatePasswordFile(Hash<user> users);

int main() {
	user emptyUser;
	emptyUser.email = "empty";
	emptyUser.password = "";

	user deletedUser;
	deletedUser.email = "deleted";
	deletedUser.password = "";

	Hash<user> hash = Hash<user>(emptyUser, deletedUser);

	// check to see if password file exists
	struct stat buf;
	ofstream outFile;

	// if does not exist, create admin account
	if(stat(PASSWORD_FILENAME.c_str(), &buf) == -1) {
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

		hash.InsertItem(newUser);
		UpdatePasswordFile(hash);
	}

	// else import existing accounts 
	else{



	}

	system("Pause");
	return 0;
}

void UpdatePasswordFile(Hash<user> users)
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
		outFile << tempUser.email << ":" << tempUser.password << endl;
	}

	outFile.close();
}

void ImportPasswordFile(Hash<user> users)
// Function: Reads the password file and stores users in the hash
// Pre:		 password file exists, user is a valid hash
// Post:	 users in password file are stored in hash
{
	ofstream outFile;
	outFile.open(PASSWORD_FILENAME.c_str());


}