#include"quicksorter.h"
#include"mergesorter.h"
#include"radixsorter.h"
#include<ctime>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

// Change for the amount of index's in array
const int SIZE = 10;

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
	string command = "Menu";
	srand((unsigned int)time(0));
	char arrayOption;
	char arrayOptionType;

	// Asks user if they want a preconstructed array or an inputed array
	do
	{
		cout << "Would you like to input your <O>wn or <R>andom array? Type <Q> to quit program." << endl;
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
			for (int i = 0; i < SIZE; i++)
			{
				char ch = 'a' + rand()%(('z'-'a') + 1);
				testArray[i] = ch;
			}
		}

		if (arrayOptionType == 'I' || arrayOptionType == 'i')
		{
			for (int i = 0; i < SIZE; i++)
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
			for (int i = 0; i < SIZE; i++)
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
		cout << "User Input: The default size of array is " << SIZE << " index's" << endl;
		cout << "Would you like to create a <C>haracter, <I>nteger, <S>tring array or <Q>uit" << endl;
		cin  >> arrayOptionType;
		cout << endl;
		
		string choice;

		if (arrayOptionType == 'Q' || arrayOptionType == 'q')
			return 1;

		if (arrayOptionType == 'C' || arrayOptionType == 'c')
		{
			for (int index = 0; index < SIZE; index++)
			{
				cout << "What item do you want to input in index " << index << endl;
				cin  >> choice;
				testArray[index] = choice;
			}
		}

		if (arrayOptionType == 'I' || arrayOptionType == 'i')
		{
			for (int index = 0; index < SIZE; index++)
			{
				cout << "What item do you want to input in index " << index << endl;
				cin  >> choice;
				testArray[index] = choice;
			}
		}

		if (arrayOptionType == 'S' || arrayOptionType == 's')
		{
			for (int index = 0; index < SIZE; index++)
			{
				cout << "What item do you want to input in index " << index << endl;
				cin  >> choice;
				testArray[index] = choice;
			}

		}

		cout << endl;
	}

	// Capture the orginal array before sorting
	for (int i = 0; i < SIZE; i++)
		orginalTestArray[i] = testArray[i];

	// Main functions
	while (command != "Exit")
	{
		if (command == "Q" || command == "q")
		{
			cout << "Unsorted: ";
			for (int i = 0; i <SIZE; i++)
				cout << orginalTestArray[i] << " ";
			cout << endl << endl;

			QuickSorter<string> qs = QuickSorter<string>(testArray, SIZE, arrayOptionType);
			clock_t begin = clock();
			qs.Sort();
			clock_t end = clock();
			string* sorted = qs.GetData();

			cout << "Sorted: ";
			for (int i = 0; i < SIZE; i++)
				cout << sorted[i] << " ";
			cout << endl;
			cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
			cout << "Comparisons: " << qs.GetComparisons() << endl << endl;

			command = "Menu";
		}
		else if (command == "M" || command == "m")
		{
			cout << "Unsorted: ";
			for (int i = 0; i <SIZE; i++)
				cout << orginalTestArray[i] << " ";
			cout << endl << endl;

			MergeSorter<string> ms = MergeSorter<string>(testArray, SIZE, arrayOptionType);
			clock_t begin = clock();
			ms.Sort();
			clock_t end = clock();
			string* sorted = ms.GetData();

			cout << "Sorted: ";
			for (int i = 0; i < SIZE; i++)
				cout << sorted[i] << " ";
			cout << endl;
			cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
			cout << "Comparisons: " << ms.GetComparisons() << endl << endl;

			command = "Menu";
		}
		else if (command == "R" || command == "r")
		{
			cout << "Unsorted: ";
			for (int i = 0; i <SIZE; i++)
				cout << orginalTestArray[i] << " ";
			cout << endl << endl;

			RadixSorter<string> rs = RadixSorter<string>(testArray, SIZE, arrayOptionType);
			clock_t begin = clock();
			rs.Sort();
			clock_t end = clock();
			string* sorted = rs.GetData();

			cout << "Sorted: ";
			for (int i = 0; i < SIZE; i++)
				cout << sorted[i] << " ";
			cout << endl;
			cout << "Time elapsed: " << double(diffclock(end,begin)) << " ms"<< endl;
			cout << "Comparisons: Does not use comparisons to sort." << endl << endl;

			command = "Menu";
		}
		else if (command == "C" || command == "c")
		{

		}
		else if (command == "E" || command == "e")
		{
			return 1;
		}
		else if (command == "Menu")
		{
			do
			{
				cout << "What type of sort would you like to execute?" << endl;
				cout << "<Q>uick Sort" << endl;
				cout << "<M>erge Sort" << endl;
				cout << "<R>adix Sort" << endl;
				cout << "<C>ompair Sorts" << endl;
				cout << "<E>xit program" << endl;
				cin  >> command;
				cout << endl;

				if (command != "Q" && command != "q" && command != "M" && command != "m" &&
					command != "R" && command != "r" && command != "C" && command != "c" &&
					command != "E" && command != "e" && command != "Menu")
					cout << "You entered an incorrect option. Please try again." << endl;

			}while (command != "Q" && command != "q" && command != "M" && command != "m" &&
					command != "R" && command != "r" && command != "C" && command != "c" &&
					command != "E" && command != "e" && command != "Menu");
		}
	}

	system("Pause");
	return 0;
}