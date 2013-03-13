#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include "queue.h"

#ifndef MYRADIXSORTTEMPLATE
#define MYRADIXSORTTEMPLATE

using namespace std;

#ifndef MYDATATYPEENUM
#define MYDATATYPEENUM
enum dataType{STR, INT};
#endif

template<class ItemType>
class RadixSorter
{
public:
	// Constructor
	RadixSorter(ItemType* items, int size, char dType);

	void Sort();
	// Function: Calls function RadixSort
	// Pre:		 data array is initialized
	// Post:	 data is sorted

	ItemType* GetData();
	// Function: Returns a copy of data
	// Pre:		 data array is initialized
	// Post:	 Copy data is returned

private:
	int arraySize;
	unsigned int positions;
	ItemType* data;
	dataType dt;
	static const int NUMBER_OF_QUEUES = 128;
	QueueType<string>* queues[NUMBER_OF_QUEUES];

	void RadixSort();
	// Function: Sorts data array
	// Pre:		 data array is initialized
	// Post:	 data array is sorted

	void CollectQueues();
	// Function: Partially sorts the data array by position by collecting items stored in
	//			 queues array
	// Pre:		 data array is initialized, queues array is initialized
	// Post:	 data array is partially sorted by position
};

#include "radixsorter.template"
#endif