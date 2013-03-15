#include <iomanip>
#include <iostream>
#include <string>
#include "bst.h"
#include "queue.h"

using namespace std;

enum types {VAR_INT, VAR_STR};

struct my_variant_t {
	int type;
	union {
		int int_val;
		char* str_val;
	};

	void operator= (int obj)
	{
		type = VAR_INT;
		int_val = obj;
	}
	
	void operator= (char* obj)
	{
		type = VAR_STR;
		str_val = _strdup(obj);
	}
};

ostream& operator<< (ostream& os, my_variant_t& obj)
{
	switch(obj.type)
	{
		case VAR_INT:
			os << obj.int_val;
			break;
		case VAR_STR:
			os << obj.str_val;
			break;
	}

	return os;
}

bool operator< (my_variant_t& obj1, my_variant_t& obj2)
{
	switch(obj1.type)
	{
		case VAR_INT:
			return (obj1.int_val < obj2.int_val);
		case VAR_STR:
			return (obj1.str_val < obj2.str_val);
		default:
			return false;
			// throw exception
	}
}

bool operator> (my_variant_t& obj1, my_variant_t& obj2)
{
	switch(obj1.type)
	{
		case VAR_INT:
			return (obj1.int_val > obj2.int_val);
		case VAR_STR:
			return (obj1.str_val > obj2.str_val);
		default:
			return false;
			// throw exception
	}
}

int main()
{
	char command;
	my_variant_t input;
	char choice;
	string temp;

	cout << "What type of tree would you like to build today, (S)trings or (N)umbers?" << endl;
	cin  >> choice;
	cout << endl;

	QueueType<my_variant_t> queueType;
	BST<my_variant_t> bst = BST<my_variant_t>();

	command = 'M';

	while (command != 'Q' && command != 'q')
	{
		if (command == 'M')
		{
			cout << "What would you like to do:" <<endl;
			cout << "(I)nput node" << endl;
			cout << "(R)emove node" << endl;
			cout << "(D)isplay tree" << endl;
			cout << "(C)hop tree down" << endl;
			cout << "(Q)uit program" << endl;
			cout << "? ";
			cin  >> command;
			cout << endl;
		}
		else if (command == 'I' || command == 'i')
		{
			if (choice == 'N' || choice == 'n')
			{
				cout << "What number would you like to input?" << endl;
				cin.ignore();
				getline(cin, temp);
				input = atoi(temp.c_str());
				cout << endl;
				bst.PutItem(input);
				cout << input << " is inputed!" << endl << endl;
			}
			else
			{
				cout << "What is the string you would like to input?" << endl;
				cin.ignore();
				getline(cin, temp);
				input = (char*)temp.c_str();
				cout << endl;
				bst.PutItem(input);
				cout << input << " is inputed!" << endl << endl;
			}

			command = 'M';
		}
		else if (command == 'R' || command == 'r')
		{
			if (choice == 'N' || choice == 'n')
			{
				cout << "What number would you like to remove?" << endl;
				cin.ignore();
				getline(cin, temp);
				input = atoi(temp.c_str());
				bst.DeleteItem(input);
				cout << endl << input << " is removed!" << endl << endl;
			}
			else
			{
				cout << "What is the string you would like to remove?" << endl;
				cin.ignore();
				getline(cin, temp);
				input = (char*)temp.c_str();
				bst.DeleteItem(input);
				cout << endl << input << " is removed!" << endl << endl;
			}

			command = 'M';
		}
		else if (command == 'D' || command == 'd')
		{
			cout << endl << "Displaying..." << endl;
			bst.Print(cout);
			cout << endl << endl;

			command = 'M';
		}
		else if (command == 'C' || command == 'c')
		{
			cout << endl << "Chopping...Timber!" << endl;
			bst.MakeEmpty();
			cout << endl << endl;
			cout << "Tree is empty!" << endl << endl;

			command = 'M';
		}
		else 
		{
			cout << "Sorry the option you entered is invalid! Please try again." << endl << endl;
			command = 'M';
			cout << endl;
		}
	}

	system("Pause");
	return 0;
}