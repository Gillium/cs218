#include <cstdlib>
#include <string>
#include <sys/stat.h>

#ifndef MYRADIXSORTTEMPLATE
#define MYRADIXSORTTEMPLATE

using namespace std;

template<class ItemType>
class RadixSorter
{
public:
	// Constructor
	RadixSorter(ItemType* items, int size);

	void Sort();
	// Function: 
	// Pre: 
	// Post:

	ItemType* GetData();
	// Function: 
	// Pre: 
	// Post:

private:
	int arraySize;
	ItemType* data;

	void RadixSort();
	// Function: 
	// Pre: 
	// Post:

	void CollectQueues();
	// Function: 
	// Pre: 
	// Post:
};

#include "radixsorter.template"
#endif