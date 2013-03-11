#include <cstdlib>
#include <string>
#ifndef MYQUICKSORTTEMPLATE
#define MYQUICKSORTTEMPLATE
#include <sys/stat.h>

using namespace std;

enum compType{GT, GTEQ, EQ, LT, LTEQ};
enum dataType{STR, INT};

template<class ItemType>
class QuickSorter
{
public:
	// Constructor
	QuickSorter(ItemType* items, int size, char dType);

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

	void Split(int first, int last, int& splitPoint);
	// Function:
	// Pre:
	// Post:

	void Swap(int index1, int index2);
	// Function:
	// Pre:
	// Post:

	void QuickSort(int first, int last);
	// Function:
	// Pre:
	// Post:

	bool CompareValues(string v1, string v2, compType cType);
	// Function:
	// Pre:
	// Post:
};

#include "quicksorter.template"
#endif