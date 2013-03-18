#include <iomanip>
#include <iostream>
#include <string>
#include "avlt.h"
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

int main()
{
	char command;
	my_variant_t input;
	char choice;
	string temp;

	QueueType<my_variant_t> queueType;
	AVLT<my_variant_t> avlt = AVLT<my_variant_t>();

	do
	{
		cout << "What type of tree would you like to build today, (L)etters, (N)umbers or (Q)uit?" << endl;
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
				cout << "(S)earch for node" << endl;
				cout << "(G)et root" << endl;
				cout << "(D)isplay tree" << endl;
				cout << "(F)ull tree test" << endl;
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
							try
							{
								avlt.PutItem(input);
								cout << input << " is inputed!" << endl << endl;
							}
							catch(DuplicateItem)
							{
								cout << input << " already exists!" << endl << endl;
							}
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
					try
					{
						avlt.PutItem(input);
						cout << input << " is inputed!" << endl << endl;
					}
					catch(DuplicateItem)
					{
						cout << input << " already exists!" << endl << endl;
					}
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
					try
					{
						avlt.DeleteItem(input);
						cout << endl << input << " is removed!" << endl << endl;
					}
					catch(NotFound)
					{
						cout << endl << "Number was not found!" << endl << endl;
					}
				}
				else
				{
					cout << "What is the string you would like to remove?" << endl;
					cin.ignore();
					getline(cin, temp);
					input = (char*)temp.c_str();
					try
					{
						avlt.DeleteItem(input);
						cout << endl << input << " is removed!" << endl << endl;
					}
					catch(NotFound)
					{
						cout << endl << "String was not found!" << endl << endl;
					}
				}

				command = 'M';
			}
			else if (command == 'D' || command == 'd')
			{
				if (!avlt.IsEmpty())
				{
					cout << endl << "Displaying..." << endl;
					avlt.Print(cout);
					cout << endl << endl;
				
					bool finished = false;
					avlt.ResetTree(IN_ORDER);
					cout << "InOrder: ";
					while(!finished)
						cout << avlt.GetNextItem(IN_ORDER, finished) << " ";
				
					finished = false;
					avlt.ResetTree(PRE_ORDER);
					cout << endl << "PreOrder: ";
					while(!finished)
						cout << avlt.GetNextItem(PRE_ORDER, finished) << " ";
				
					finished = false;
					avlt.ResetTree(POST_ORDER);
					cout << endl << "PostOrder: ";
					while(!finished)
						cout << avlt.GetNextItem(POST_ORDER, finished) << " ";

					cout << endl << endl;
				}
				else
					cout << "The tree is empty!" << endl << endl;

				command = 'M';
			}
			else if (command == 'C' || command == 'c')
			{
				cout << endl << "Chopping...Timber!" << endl;
				avlt.MakeEmpty();
				cout << "Tree is empty!" << endl << endl;

				command = 'M';
			}
			else if (command == 'Q' || command == 'q')
			{
				continue;
			}
			else if (command == 'N' || command == 'n')
			{
				avlt.MakeEmpty();
				break;
			}
			else if (command == 'S' || command == 's')
			{
				if (choice == 'N' || choice == 'n')
				{
					cin.ignore();
					bool isNumber;
					do
					{
						cout << "What number would you like to find?" << endl;
						getline(cin, temp);

						isNumber = true;
						if (temp.length() == 0)
							isNumber = false;

						for (unsigned int i = 0; i < temp.length(); i ++)
						{
							if(!isdigit(temp[i]))
								isNumber = false;
						}

						if (isNumber)
						{
							input = atoi(temp.c_str());
							cout << endl;
							
							bool found;
							avlt.GetItem(input, found);

							if (found)
								cout << input << " was found!" << endl << endl;
							else
								cout << input << " was not found!" << endl << endl;
						}
						else
							cout << temp << "is not a valid number!" << endl << endl;
					}while(!isNumber);
				}
				else
				{
					cin.ignore();
					bool isEmptyString;
					do
					{
						isEmptyString = false;
						cout << "What is the string you would like to find?" << endl;
						getline(cin, temp);

						if (temp == "")
						{
							isEmptyString = true;
							cout << temp << " is not a valid string!" << endl << endl;
						}
					}while(isEmptyString);

					input = (char*)temp.c_str();
					cout << endl;
					bool found;
					avlt.GetItem(input, found);
					
					if (found)
						cout << input << " was found!" << endl << endl;
					else
						cout << input << " was not found!" << endl << endl;
				}

				command = 'M';
			}
			else if (command == 'G' || command == 'g')
			{
				try
				{
					cout << "The root item is : " << avlt.RetrieveRoot() << endl << endl;
				}
				catch(EmptyTree)
				{
					cout << "The root does not exist!" << endl << endl;
				}

				command = 'M';
			}
			else if (command == 'F' || command == 'f')
			{
				cout << "Checking..." << endl;
	
				if (avlt.IsFullTree())
					cout << "The tree is full!" << endl << endl;
				else
					cout << "The tree is not full!" << endl << endl;

				command = 'M';
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