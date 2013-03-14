#include <iomanip>
#include <iostream>
#include <string>
#include "bst.h"
#include "queue.h"

using namespace std;

int main()
{
	char command;
	int number;
	char letter;
	char choice;

	cout << "What type of tree would you like to build today, (L)etters or (N)umbers?" << endl;
	cin  >> choice;
	cout << endl;

	QueueType<char> queueTypeC;
	BST<char> bstC = BST<char>();

	QueueType<int> queueTypeI;
	BST<int> bstI = BST<int>();

	command = 'M';

	while (command != 'Q')
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
				cin  >> number;
				cout << endl;
				bstI.PutItem(number);
				cout << number << " is inputed!" << endl << endl;
			}
			else
			{
				cout << "What letter would you like to input?" << endl;
				cin >> letter;
				cout << endl;
				bstC.PutItem(letter);
				cout << letter << " is inputed!" << endl << endl;
			}

			command = 'M';
		}
		else if (command == 'R' || command == 'r')
		{
			if (choice == 'N' || choice == 'n')
			{
				cout << "What number would you like to remove?" << endl;
				cin  >> number;
				bstI.DeleteItem(number);
				cout << endl << number << " is removed!" << endl << endl;
			}
			else
			{
				cout << "What letter would you like to remove?" << endl;
				cin >> letter;
				bstC.DeleteItem(letter);
				cout << endl << letter << " is removed!" << endl << endl;
			}

			command = 'M';
		}
		else if (command == 'D' || command == 'd')
		{
			if (choice == 'N' || choice == 'n')
			{
				cout << endl << "Displaying..." << endl;
				bstI.Print(cout);
				cout << endl << endl;
			}
			else
			{
				cout << endl << "Displaying..." << endl;
				bstC.Print(cout);
				cout << endl << endl;
			}

			command = 'M';
		}
		else if (command == 'C' || command == 'c')
		{
			if (choice == 'N' || choice == 'n')
			{
				cout << endl << "Chopping...Timber!" << endl;
				bstI.MakeEmpty();
				cout << endl << endl;
				cout << "Tree is empty!" << endl << endl;
			}
			else
			{
				cout << endl << "Chopping...Timber!" << endl;
				bstC.MakeEmpty();
				cout << endl << endl;
				cout << "Tree is empty!" << endl << endl;
			}

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