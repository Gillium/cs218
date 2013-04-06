#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include "hashDriverFunctions.h"

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

int main() {
	user emptyUser;
	emptyUser.email = "empty";
	emptyUser.password = "";

	user deletedUser;
	deletedUser.email = "deleted";
	deletedUser.password = "";

	Hash<user> hash = Hash<user>(emptyUser, deletedUser);

	
	cout << hash.GetMD5Hash("Hello") << endl;

	// Creates new outfile or validates existing one for override
	ofstream outFile;
	string outFileName;

	cout << "Enter name of output file or return to exit program." << endl;
	getline(cin, outFileName);

	if (outFileName == "")
		exit(0);

	struct stat buf;
    while(stat(outFileName.c_str(), &buf) != -1) {
		char choice;

		cout << "The file already exists. Would you like to overwrite? (Y or N)" << endl;
		cin  >> choice;

		if (choice == 'Y' || choice == 'y') {
			cin.ignore();
			outFile.open(outFileName.c_str());
			break;
		} else {
			cout << endl << "Enter different name for output file or return to exit program." << endl;
			cin.ignore();
			getline(cin, outFileName);

			if (outFileName == "")
				exit(0);
		}
	}

	if (stat(outFileName.c_str(), &buf) == -1)
		outFile.open(outFileName.c_str());

	// read in user and password
	string address;
	string password;

	cout << "Enter user email address: ";
	getline(cin, address);
	outFile << address << ":";
	
	// currently displays in text format
	cout << "Enter password: ";
	getline(cin, password);
	outFile << password << endl;

	// create user
	user newUser;
	newUser.email = address;
	newUser.password = password;

	hash.InsertItem(newUser);
	hash.Display(cout);
/*
	As default, write a driver program that reads a collection of computer user IDs and passwords and stores them in a hash table.
Your program should support a list of options including logging on to the system, adding new user, deleting an existing user, and displaying all the existing users in a readable format, etc. For instance, if user wants to log on the system, your program should then read two strings representing a user’s ID and password and then check whether this is a valid user of the computer system by searching the hash table for this ID and password.
You may choose to have your own application instead, as long as it is good for demonstrating the usage of hash table.
Use at least two different hash functions. Do not use simple modulus function by the table size only, but it may be combined. Note that hash function for this system should convert strings (key) to an integer (index). Be sure to include detailed descriptions of your choices of hash functions in your document for submission.
CS218 KIM
Use at least two different methods for collision resolution. You may use the following:
1. Chaining
2. Quadratic probing
3. Linear probing
4. Double hashing
You may implement all combinations of hashing and collision resolution methods – such as random hashing function with chaining, random hashing function with quadratic probing, etc. Be sure to provide descriptions on every method that you implement.
There are many rooms for improvement if you like to challenge. They include encoding passwords, using graphical user interface, and improving hashing function to reduce collision, or creating a good hashing function for string, doing comparison analysis on the performance data using various hashing functions (in terms of the number of collisions).
Again, your driver program should be interactive and demonstrative.
Provide a complete package for each program that you submit. It includes a description, design document, test plan, source code, sample outputs and analysis.
Sample outputs should demonstrate all the features of your Hash Table. For insertion, consider all the scenarios, such as inserting new item to the location that has never been allocated, or that was previously allocated and released, and inserting with a collision, or with multiple collisions, etc. Try with different sizes for your hash table.
Also, compute the average number of probes for a typical successful search, unsuccessful search, insert, and delete.
*/

	system("Pause");
	return 0;
}