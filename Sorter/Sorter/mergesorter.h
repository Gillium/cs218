#include <cstdlib>
#include <string>
#include <sys/stat.h>

#ifndef MYMERGESORTTEMPLATE
#define MYMERGESORTTEMPLATE

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
class MergeSorter
{
public:
	// Constructor
	MergeSorter(ItemType* items, int userIndex, char dType);

	void Sort();
	// Function: Calls recursive function MergeSort
	// Pre:		 data array is initialized
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

	void MergeSort(int first, int last);
	// Function: recusively sorts data array
	// Pre:		 data array is initialized
	// Post:	 data array is sorted

	void Merge(int leftFirst, int leftLast, int rightFirst, int rightLast);
	// Function: Merges two sub-arrays of data
	// Pre:		 data array is initialized
	// Post:	 data array values between leftFirst and rightLast are sorted

	bool CompareValues(string v1, string v2, compType cType);
	// Function: Compares two values using a string or integer comparison
	// Pre:		 data array is initialized
	// Post:	 returns bool value of comparison
};

#include "mergesorter.template"
#endif