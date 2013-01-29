#include"quicksorter.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string command = "Menu";

	while (command != "Quit")
	{
		if (command == "Quick")
		{
			char testArray[5] = {'A', 'E', 'D', 'C', 'B'};
			QuickSorter<char> qs = QuickSorter<char>(testArray);
			qs.Sort();
			char* sorted = qs.GetData();

			for (int i = 0; i < 5; i++)
				cout << sorted[i] << " ";

			cout << endl << endl;
			command = "Menu";
		}
		else if (command == "Merge")
		{

		}
		else if (command == "Radix")
		{

		}
		else if (command == "All")
		{

		}
		else if (command == "Menu")
		{
			do
			{
				cout << "Choose type of sort (Quick, Merge, Radix, All) or type Quit to exit program" << endl;
				cin  >> command;
				cout << endl;

				if (command != "Quick" && command != "Merge" && command != "Radix" && command != "All" && command != "Quit" && command != "Menu")
					cout << "Sorry, that command is not an offered" << endl;

			}while (command != "Quick" && command != "Merge" && command != "Radix" && command != "All" && command != "Quit" && command != "Menu");
		}
	}

	system("Pause");
	return 0;
}