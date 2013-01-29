#include <cstdlib>
#ifndef MYQUICKSORTTEMPLATE
#define MYQUICKSORTTEMPLATE
#include <sys/stat.h>

using namespace std;

template<class ItemType>
class QuickSorter
{
public:
	QuickSorter(ItemType* items);
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

private:
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