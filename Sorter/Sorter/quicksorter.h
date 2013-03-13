#include <cstdlib>
#include <string>
#ifndef MYQUICKSORTTEMPLATE
#define MYQUICKSORTTEMPLATE
#include <sys/stat.h>

using namespace std;

#ifndef MYCOMPTYPEENUM
#define MYCOMPTYPEENUM
enum compType{GT, GTEQ, EQ, LT, LTEQ};
#endif

#ifndef MYDATATYPEENUM
#define MYDATATYPEENUM
enum dataType{STR, INT};
#endif

template<class ItemType>
class QuickSorter
{
public:
	// Constructor
	QuickSorter(ItemType* items, int userIndex, char dType);

	void Sort();
	// Function: Calls recursive function QuickSort
	// Pre:		 data is unsorted
	// Post:	 data is sorted

	ItemType* GetData();
	// Function: Returns a copy of data
	// Pre:		 data array is initialized
	// Post:	 Copy data is returned

	int GetComparisons();
	// Function: Returns the number of comparisons while executing Sort
	// Pre:		 data array is initialized
	// Post:	 comparisons is returned

private:
	int arraySize;
	int comparisons;
	ItemType* data;
	dataType dt;

	void Split(int first, int last, int& splitPoint);
	// Function: Swaps elements of data within first and last so that elements before
	//			 splitPoint are less than or equal to elements after splitPoint
	// Pre:		 data array is initialized
	// Post:	 The elements of data before splitPoint are less than or equal to the elements
	//			 after splitPoint

	void Swap(int index1, int index2);
	// Function: Swaps the value of data at index1 with data at index2
	// Pre:		 data array is initialized
	// Post:	 The value of data at index1 is swapped with the data at index 2

	void QuickSort(int first, int last);
	// Function: Recursively sorts data array
	// Pre:		 data array is initialized
	// Post:	 data array is sorted

	bool CompareValues(string v1, string v2, compType cType);
	// Function: Compares two values using a string or integer comparison
	// Pre:		 data array is initialized
	// Post:	 Returns bool value of comparison
};

#include "quicksorter.template"
#endif