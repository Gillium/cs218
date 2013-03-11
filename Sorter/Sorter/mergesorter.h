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
	MergeSorter(ItemType* items, int size, char dType);
	// Pre:
	// Post:

	void Sort();
	// Function:
	// Pre:
	// Post:

	ItemType* GetData();
	// Function:
	// Pre:
	// Post:

	int GetComparisons();
	// Function:
	// Pre:
	// Post:

private:
	int arraySize;
	int comparisons;
	ItemType* data;
	dataType dt;

	void MergeSort(int first, int last);
	// Function:
	// Pre:
	// Post:

	void Merge(int leftFirst, int leftLast, int rightFirst, int rightLast);
	// Function:
	// Pre:
	// Post:

	bool CompareValues(string v1, string v2, compType cType);
	// Function: Compares two values using a string or integer comparison
	// Pre: data array is initialized
	// Post: returns bool value of comparison
};

#include "mergesorter.template"
#endif