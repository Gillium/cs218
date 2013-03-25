#include <iomanip>
#include <iostream>
#include <string>
#include "heap.h"

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
			return (strcmp(obj1.str_val, obj2.str_val) < 0);
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
			return (strcmp(obj1.str_val, obj2.str_val) > 0);
		default:
			return false;
			// throw exception
	}
}

bool operator== (my_variant_t& obj1, my_variant_t& obj2)
{
	switch(obj1.type)
	{
		case VAR_INT:
			return (obj1.int_val == obj2.int_val);
		case VAR_STR:
			return (strcmp(obj1.str_val, obj2.str_val) == 0);
		default:
			return false;
			// throw exception
	}
}

bool operator>= (my_variant_t& obj1, my_variant_t& obj2)
{
	switch(obj1.type)
	{
		case VAR_INT:
			return (obj1.int_val >= obj2.int_val);
		case VAR_STR:
			return (strcmp(obj1.str_val, obj2.str_val) >= 0);
		default:
			return false;
			// throw exception
	}
}

bool operator<= (my_variant_t& obj1, my_variant_t& obj2)
{
	switch(obj1.type)
	{
		case VAR_INT:
			return (obj1.int_val <= obj2.int_val);
		case VAR_STR:
			return (strcmp(obj1.str_val, obj2.str_val) <= 0);
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
	
	Heap<my_variant_t> heap = Heap<my_variant_t>();

	do
	{
		cout << "What type of tree would you like to build, (S)trings, (N)umbers, or (Q)uit?" << endl;
		cin  >> choice;
		cout << endl;

		if (choice == 'Q' || choice == 'q')
			return 1;

		command = 'M';

		while (command != 'Q' && command != 'q')
		{
			if (command == 'M')
			{
				cout << "What would you like to do:" <<endl;
				cout << "(I)sert node" << endl;
				cout << "(R)emove node" << endl;
				cout << "(D)isplay tree" << endl;
				cout << "(C)hop tree down" << endl;
				cout << "(N)ew tree" << endl;
				cout << "(Q)uit program" << endl;
				cout << "? ";
				cin  >> command;
				cout << endl;
			}
			else if (command == 'I' || command == 'i')
			{
				if (choice == 'N' || choice == 'n')
				{
					cin.ignore();
					bool isNumber;
					do
					{
						cout << "What number would you like to input?" << endl;
						getline(cin, temp);

						isNumber = true;
						if (temp.length() == 0)
							isNumber = false;

						for (unsigned int i = 0; i < temp.length(); i++)
						{
							if(!isdigit(temp[i]))
								isNumber = false;
						}

						if (isNumber)
						{
							input = atoi(temp.c_str());
							cout << endl;

							heap.HeapInsert(input);
							cout << input << " is inputed!" << endl << endl;
							
						}
						else
							cout << temp << " is not a valid number!" << endl << endl;

					}while(!isNumber);
				}
				else
				{
					cin.ignore();
					bool isEmptyString;
					do
					{
						isEmptyString = false;
						cout << "What is the string you would like to input?" << endl;
						getline(cin, temp);

						if (temp == "")
						{
							isEmptyString = true;
							cout << temp << " is not a valid string!" << endl << endl;
						}

					}while(isEmptyString);

					input = (char*)temp.c_str();
					cout << endl;
					
					heap.HeapInsert(input);
					cout << input << " is inputed!" << endl << endl;
				}

				command = 'M';
			}
			else if (command == 'R' || command == 'r')
			{
				if (choice == 'N' || choice == 'n')
				{
					cout << "Removing root..." << endl;
					try
					{
						cout << endl << heap.HeapDelete() << " is removed!" << endl << endl;
					}
					catch(HeapEmpty)
					{
						cout << endl << "Heap is empty!" << endl << endl;
					}
				}
				else
				{
					cout << "Removing root..." << endl;
					try
					{
						cout << endl << heap.HeapDelete() << " is removed!" << endl << endl;
					}
					catch(HeapEmpty)
					{
						cout << endl << "Heap is empty!" << endl << endl;
					}
				}

				command = 'M';
			}
			else if (command == 'D' || command == 'd')
			{
				if (!heap.IsEmpty())
				{
					cout << endl << "Displaying..." << endl;
					heap.Print(cout);
					cout << endl << endl;
				}
				else
					cout << "Heap is empty!" << endl << endl;

				command = 'M';
			}
			else if (command == 'C' || command == 'c')
			{
				cout << endl << "Chopping...Timber!" << endl;
				heap.MakeEmpty();
				cout << "Tree is empty!" << endl << endl;

				command = 'M';
			}
			else if (command == 'Q' || command == 'q')
			{
				continue;
			}
			else if (command == 'N' || command == 'n')
			{
				heap.MakeEmpty();
				break;
			}
			else 
			{
				cout << "Sorry the option you entered is invalid! Please try again." << endl << endl;
				command = 'M';
				cout << endl;
			}
		}

	}while(command != 'Q' && command != 'q');

	system("Pause");
	return 0;
}