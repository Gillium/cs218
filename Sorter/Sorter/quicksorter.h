#include <cstdlib>
#ifndef MYQUICKSORTTEMPLATE
#define MYQUICKSORTTEMPLATE
#include <sys/stat.h>

using namespace std;

template<class ItemType>
class QuickSorter
{
public:
	// Constructor
	QuickSorter(ItemType* items, int size);

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

	ItemType* data;
};

#include "quicksorter.template"
#endif