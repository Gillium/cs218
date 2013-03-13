#include"quicksorter.h"
#include"mergesorter.h"
#include"radixsorter.h"
#include<ctime>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

// Change for the amount of index's in array
const int SIZE = 5000;

double diffclock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2;
	double diffms = (diffticks * 1000) / CLOCKS_PER_SEC;
	return diffms;
} 

int main()
{
	string orginalTestArray[SIZE];
	string testArray[SIZE];
	srand((unsigned int)time(0));
	char arrayOption;
	char arrayOptionType;
	clock_t begin;
	clock_t end;
	string* sorted;
	int userIndex;

	do
	{
		string command = "Menu";

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
			cout << endl << "Would you like to input your <O>wn or <R>andom array? Type <Q> to quit program." << endl;
			cin  >> arrayOption;
			cout << endl;

			if (arrayOption == 'Q' || arrayOption == 'q')
				return 1;

			if (arrayOption != 'O' && arrayOption != 'o' && arrayOption != 'R' && arrayOption != 'r')
				cout << "You entered an incorrect option. Please try again." << endl << endl;
		}while(arrayOption != 'O' && arrayOption != 'o' && arrayOption != 'R' && arrayOption != 'r');

		// Sets values for a preconstructed array to user specification
		if (arrayOption == 'R' || arrayOption == 'r')
		{
			cout << "Would you like to create a <C>haracter, <I>nteger, <S>tring array or <Q>uit" << endl;
			cin  >> arrayOptionType;
			cout << endl;
		
			if (arrayOptionType == 'Q' || arrayOptionType == 'q')
				return 1;

			if (arrayOptionType == 'C' || arrayOptionType == 'c')
			{
				for (int i = 0; i < userIndex; i++)
				{
					char ch = 'a' + rand()%(('z'-'a') + 1);
					testArray[i] = ch;
				}
			}

			if (arrayOptionType == 'I' || arrayOptionType == 'i')
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
			cout << endl << "Would you like to create a <C>haracter, <I>nteger, <S>tring array or <Q>uit" << endl;
			cin  >> arrayOptionType;
			cout << endl;
		
			string choice;

			if (arrayOptionType == 'Q' || arrayOptionType == 'q')
				return 1;

			if (arrayOptionType == 'C' || arrayOptionType == 'c')
			{
				for (int index = 0; index < userIndex; index++)
				{
					cout << "What item do you want to input in index " << index << endl;
					cin  >> choice;
					testArray[index] = choice;
				}
			}

			if (arrayOptionType == 'I' || arrayOptionType == 'i')
			{
				for (int index = 0; index < userIndex; index++)
				{
					cout << "What item do you want to input in index " << index << endl;
					cin  >> choice;
					testArray[index] = choice;
				}
			}

			if (arrayOptionType == 'S' || arrayOptionType == 's')
			{
				for (int index = 0; index < userIndex; index++)
				{
					cout << "What item do you want to input in index " << index << endl;
					cin  >> choice;
					testArray[index] = choice;
				}

			}

			cout << endl;
		}

		// Capture the orginal array before sorting
		for (int i = 0; i < userIndex; i++)
			orginalTestArray[i] = testArray[i];

		// Main functions
		while (command != "Exit")
		{
			if (command == "Q" || command == "q")
			{
				cout << "Unsorted: ";
				for (int i = 0; i <userIndex; i++)
					cout << orginalTestArray[i] << " ";
				cout << endl << endl;

				QuickSorter<string> qs = QuickSorter<string>(testArray, userIndex, arrayOptionType);
				begin = clock();
				qs.Sort();
				end = clock();
				sorted = qs.GetData();

				cout << "Sorted: ";
				for (int i = 0; i < userIndex; i++)
					cout << sorted[i] << " ";
				cout << endl;
				cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
				cout << "Comparisons: " << qs.GetComparisons() << endl << endl;

				command = "Menu";
			}
			else if (command == "M" || command == "m")
			{
				cout << "Unsorted: ";
				for (int i = 0; i <userIndex; i++)
					cout << orginalTestArray[i] << " ";
				cout << endl << endl;

				MergeSorter<string> ms = MergeSorter<string>(testArray, userIndex, arrayOptionType);
				begin = clock();
				ms.Sort();
				end = clock();
				sorted = ms.GetData();

				cout << "Sorted: ";
				for (int i = 0; i < userIndex; i++)
					cout << sorted[i] << " ";
				cout << endl;
				cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
				cout << "Comparisons: " << ms.GetComparisons() << endl << endl;

				command = "Menu";
			}
			else if (command == "R" || command == "r")
			{
				cout << "Unsorted: ";
				for (int i = 0; i <userIndex; i++)
					cout << orginalTestArray[i] << " ";
				cout << endl << endl;

				RadixSorter<string> rs = RadixSorter<string>(testArray, userIndex, arrayOptionType);
				begin = clock();
				rs.Sort();
				end = clock();
				sorted = rs.GetData();

				cout << "Sorted: ";
				for (int i = 0; i < userIndex; i++)
					cout << sorted[i] << " ";
				cout << endl;
				cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
				cout << "Comparisons: Does not use comparisons to sort." << endl << endl;

				command = "Menu";
			}
			else if (command == "C" || command == "c")
			{
				cout << "Unsorted: ";
				for (int i = 0; i <userIndex; i++)
					cout << orginalTestArray[i] << " ";
				cout << endl << endl;

				QuickSorter<string> qs = QuickSorter<string>(testArray, userIndex, arrayOptionType);
				begin = clock();
				qs.Sort();
				end = clock();
				sorted = qs.GetData();

				cout << endl;
				cout << "Quicksort time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
				cout << "Quicksort comparisons: " << qs.GetComparisons() << endl << endl;

				MergeSorter<string> ms = MergeSorter<string>(testArray, userIndex, arrayOptionType);
				begin = clock();
				ms.Sort();
				end = clock();
				sorted = ms.GetData();

				cout << endl;
				cout << "Mergesort time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
				cout << "Mergesort comparisons: " << ms.GetComparisons() << endl << endl;

				RadixSorter<string> rs = RadixSorter<string>(testArray, userIndex, arrayOptionType);
				begin = clock();
				rs.Sort();
				end = clock();
				sorted = rs.GetData();

				cout << endl;
				cout << "Radixsort time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
				cout << "Radixsort comparisons: Does not use comparisons to sort." << endl << endl;

				cout << "Sorted: ";
				for (int i = 0; i < userIndex; i++)
					cout << sorted[i] << " ";
				cout << endl << endl;

				command = "Menu";
			}
			else if (command == "E" || command == "e")
			{
				return 1;
			}
			else if (command == "N" || command == "n")
			{
				break;
			}
			else if (command == "Menu")
			{
				do
				{
					cout << "What type of sort would you like to execute?" << endl;
					cout << "These will be sorted by ASCII values." << endl;
					cout << "<Q>uick Sort" << endl;
					cout << "<M>erge Sort" << endl;
					cout << "<R>adix Sort" << endl;
					cout << "<C>ompair Sorts" << endl;
					cout << "<N>ew Sort" << endl;
					cout << "<E>xit program" << endl;
					cin  >> command;
					cout << endl;

					if (command != "Q" && command != "q" && command != "M" && command != "m" &&
						command != "R" && command != "r" && command != "C" && command != "c" &&
						command != "E" && command != "e" && command != "N" && command != "n" &&
						command != "Menu")
						cout << "You entered an incorrect option. Please try again." << endl;

				}while (command != "Q" && command != "q" && command != "M" && command != "m" &&
						command != "R" && command != "r" && command != "C" && command != "c" &&
						command != "E" && command != "e" && command != "N" && command != "n" &&
						command != "Menu");
			}
		}
	}while(1);

	system("Pause");
	return 0;
}