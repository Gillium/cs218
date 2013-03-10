#include <cstdlib>
#ifndef MYMERGESORTTEMPLATE
#define MYMERGESORTTEMPLATE
#include <sys/stat.h>

using namespace std;

template<class ItemType>
class MergeSorter
{
public:
	MergeSorter(ItemType* items, int length);
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

	int Comparisons();
	// Function:
	// Pre:
	// Post:

private:
	void MergeSort(int first, int last);
	// Function:
	// Pre:
	// Post:

	void Merge(int leftFirst, int leftLast, int rightFirst, int rightLast);
	// Function:
	// Pre:
	// Post:

	ItemType* data;
	int size;
};

#include "mergesorter.template"
#endif