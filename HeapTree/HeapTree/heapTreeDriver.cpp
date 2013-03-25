#include <iomanip>
#include <iostream>
#include <string>
#include "heap.h"
#include "priorityQueue.h"
#include "priorityHeapQueue.h"

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

	void operator= (my_variant_t obj)
	{
		type = obj.type;
		int_val = obj.int_val;
		str_val = obj.str_val;
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
	PriorityQueueType<my_variant_t> pq = PriorityQueueType<my_variant_t>();
	PriorityHeapQueueType<my_variant_t> phq = PriorityHeapQueueType<my_variant_t>();

	do
	{
		cout << "What type of heap would you like to build, (S)trings, (N)umbers, or (Q)uit?" << endl;
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
				cout << "(I)nsert/Enqueue node" << endl;
				cout << "(R)emove/Dequeue node" << endl;
				cout << "(D)isplay Heap/Queue" << endl;
				cout << "(C)hop Heaps down" << endl;
				cout << "(N)ew Heaps" << endl;
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
						cout << "What number would you like to insert?" << endl;
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
							cout << input << " is inserted in Heap!" << endl;
							pq.Enqueue(input);
							cout << input << " is enqueued in PriorityQueue!" << endl;
							phq.Enqueue(input);
							cout << input << " is enqueued in PriorityHeapQueue!" << endl << endl;
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
						cout << "What is the string you would like to insert?" << endl;
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
					cout << input << " is inserted in Heap!" << endl;
					pq.Enqueue(input);
					cout << input << " is enqueued in PriorityQueue!" << endl;
					phq.Enqueue(input);
					cout << input << " is enqueued in PriorityHeapQueue!" << endl << endl;
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
						cout << endl << heap.HeapDelete() << " is deleted from Heap!" << endl;
						my_variant_t temp;
						pq.DeQueue(temp);
						cout << endl << temp << " is dequeued from PriorityQueue!" << endl << endl;
						phq.Dequeue(temp);
						cout << temp << " is dequeued from PriorityHeapQueue!" << endl << endl;
					}
					catch(HeapEmpty)
					{
						cout << endl << "Heap is empty!" << endl;
						cout << endl << "PriorityQueue is empty!" << endl;
						cout << endl << "PriorityHeapQueue is empty!" << endl << endl;
					}
				}
				else
				{
					cout << "Removing root..." << endl;
					try
					{
						cout << endl << heap.HeapDelete() << " is deleted from Heap!" << endl;
						my_variant_t temp;
						pq.DeQueue(temp);
						cout << endl << temp << " is dequeued from PriorityQueue!" << endl << endl;
						phq.Dequeue(temp);
						cout << temp << " is dequeued from PriorityHeapQueue!" << endl << endl;
						
					}
					catch(HeapEmpty)
					{
						cout << endl << "Heap is empty!" << endl;
						cout << endl << "PriorityQueue is empty!" << endl;
						cout << endl << "PriorityHeapQueue is empty!" << endl << endl;
					}
				}

				command = 'M';
			}
			else if (command == 'D' || command == 'd')
			{
				if (!heap.IsEmpty())
				{
					cout << endl << "Displaying...Heap!" << endl;
					heap.Print(cout);
					cout << endl << endl;
				}
				else
					cout << "Heap is empty!" << endl << endl;

				if (!pq.IsEmpty())
				{
					cout << endl << "Displaying...PriorityQueue!" << endl;
					pq.Print(cout);
					cout << endl << endl;
				}
				else
					cout << "Heap is empty!" << endl << endl;

				if (!phq.IsEmpty())
				{
					cout << endl << "Displaying...PriorityHeapQueue!" << endl;
					phq.Print(cout);
					cout << endl << endl;
				}
				else
					cout << "Heap is empty!" << endl << endl;



				command = 'M';
			}
			else if (command == 'C' || command == 'c')
			{
				cout << endl << "Chopping...Heap!" << endl;
				heap.MakeEmpty();
				cout << "Heap is empty!" << endl << endl;

				cout << endl << "Chopping...PriorityHeapQueue!" << endl;
				phq.MakeEmpty();
				cout << "PriorityHeapQueue is empty!" << endl << endl;

				command = 'M';
			}
			else if (command == 'Q' || command == 'q')
			{
				continue;
			}
			else if (command == 'N' || command == 'n')
			{
				heap.MakeEmpty();
				phq.MakeEmpty();
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