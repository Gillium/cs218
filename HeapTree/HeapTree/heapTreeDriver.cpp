#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "heap.h"
#include "priorityQueue.h"
#include "priorityHeapQueue.h"

using namespace std;

// Change for the amount of index's in array
const int SIZE = 5000;

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

double diffclock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2;
	double diffms = (diffticks * 1000) / CLOCKS_PER_SEC;
	return diffms;
}

void heapSorterUI(char choice);

int main()
{
	char command;
	my_variant_t input;
	char choice;
	string temp;
	srand((unsigned int)time(0));

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
				cout << "(E)mpty data" << endl;
				cout << "(S)ort performance test" << endl;
				cout << "(N)ew Heap/Queue type" << endl;
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
							pq.EnQueue(input);
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
					pq.EnQueue(input);
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
						cout << temp << " is dequeued from PriorityQueue!" << endl;
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
					cout << "PriorityQueue is empty!" << endl << endl;

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
			else if (command == 'E' || command == 'e')
			{
				cout << endl << "Emptying Heap!" << endl;
				heap.MakeEmpty();
				cout << "Heap is empty!" << endl;

				cout << endl << "Emptying PriorityQueue!" << endl;
				pq.MakeEmpty();
				cout << "PriorityQueue is empty!" << endl;

				cout << endl << "Emptying PriorityHeapQueue!" << endl;
				phq.MakeEmpty();
				cout << "PriorityHeapQueue is empty!" << endl << endl;

				command = 'M';
			}
			else if (command == 'S' || command == 's')
			{
				heapSorterUI(choice);

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

void heapSorterUI(char arrayOptionType)
{
	string orginalTestArray[SIZE];
	string testArray[SIZE];
	char arrayOption;
	string sorted[SIZE];
	int userIndex;

	do
	{
		cout << "How many values do you want to use? (MAX 5000)" << endl;
		cin  >> userIndex;
		if (userIndex > 5000)
			cout << "You entered an incorrect ammount. Please try again." << endl << endl;
	}while(userIndex > 5000);

	// Asks user if they want a preconstructed array or an inputed array
	do
	{
		cout << endl << "Would you like to input your <O>wn or <R>andom array? Type <Q> to go back to main menu." << endl;
		cin  >> arrayOption;
		cout << endl;

		if (arrayOption == 'Q' || arrayOption == 'q')
			return;

		if (arrayOption != 'O' && arrayOption != 'o' && arrayOption != 'R' && arrayOption != 'r')
			cout << "You entered an incorrect option. Please try again." << endl << endl;
	}while(arrayOption != 'O' && arrayOption != 'o' && arrayOption != 'R' && arrayOption != 'r');

	// Sets values for a preconstructed array to user specification
	if (arrayOption == 'R' || arrayOption == 'r')
	{
		if (arrayOptionType == 'N' || arrayOptionType == 'n')
		{
			for (int i = 0; i < userIndex; i++)
			{
				int num = rand() % 1000;
				// Cast num to a string
				stringstream ss;
				ss << num;
				testArray[i] = ss.str(); 
			}
		}

		if (arrayOptionType == 'S' || arrayOptionType == 's')
		{
			char temp[10];
			for (int i = 0; i < userIndex; i++)
			{
				int run = rand() % 7 + 3;
				for (int j = 0; j < run; j++)
				{
					temp[j] = rand() % 26 + 'a';
				}
				temp[run] = '\0';
				testArray[i] = temp;
			}

		}
	}

	// Sets values of array as user inputs
	else
	{
		string choice;

		for (int index = 0; index < userIndex; index++)
		{
			cout << "What item do you want to input in index " << index << endl;
			cin  >> choice;
			testArray[index] = choice;
		}

		cout << endl;
	}

	// Capture the orginal array before sorting
	for (int i = 0; i < userIndex; i++)
		orginalTestArray[i] = testArray[i];

	Heap<string> heap = Heap<string>();
	PriorityQueueType<string> pq = PriorityQueueType<string>();
	PriorityHeapQueueType<string> phq = PriorityHeapQueueType<string>();
	clock_t begin;
	clock_t end;

	cout << "Sort performance test:" << endl << endl;

	cout << "Heap" << endl;

	begin = clock();

	for (int i = 0; i < userIndex; i++)
	{
		heap.HeapInsert(testArray[i]);
	}

	int index = 0;
	while (!heap.IsEmpty())
	{
		sorted[index] = heap.HeapDelete();
		++index;
	}

	end = clock();

	if (userIndex <= 100)
	{
		cout << "unsorted array: ";
		for (int i = 0; i < userIndex; i++)
			cout << testArray[i] << " ";

		cout << endl << "sorted array: ";
		for (int i = 0; i < userIndex; i++)
			cout << sorted[i] << " ";
	}
	else
      cout << "output supressed" << endl;

    cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl << endl;

	cout << "PriorityQueue" << endl;

	begin = clock();

	for (int i = 0; i < userIndex; i++)
	{
		pq.EnQueue(testArray[i]);
	}

	index = 0;
	while (!pq.IsEmpty())
	{
		string temp;
		pq.DeQueue(temp);
		sorted[index] = temp;
		++index;
	}

	end = clock();

	if (userIndex <= 100)
	{
		cout << "unsorted array: ";
		for (int i = 0; i < userIndex; i++)
			cout << testArray[i] << " ";

		cout << endl << "sorted array: ";
		for (int i = 0; i < userIndex; i++)
			cout << sorted[i] << " ";
	} 
	else
      cout << "output supressed" << endl;

    cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl << endl;

	cout << "PriorityHeapQueue" << endl;

    begin = clock();

	for (int i = 0; i < userIndex; i++)
	{
		phq.Enqueue(testArray[i]);
	}

	index = 0;
	while (!phq.IsEmpty())
	{
		string temp;
		phq.Dequeue(temp);
		sorted[index] = temp;
		++index;
	}

	end = clock();

	if (userIndex <= 100)
	{
		cout << "unsorted array: ";
		for (int i = 0; i < userIndex; i++)
			cout << testArray[i] << " ";

		cout << endl << "sorted array: ";
		for (int i = 0; i < userIndex; i++)
			cout << sorted[i] << " ";
	}
	else
      cout << "output supressed" << endl;

    cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;

	cout << endl << endl;
}