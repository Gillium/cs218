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
	// Function: 
	// Pre: 
	// Post:

	ItemType* GetData();
	// Function: 
	// Pre: 
	// Post:

private:
	int arraySize;
	unsigned int positions;
	ItemType* data;
	dataType dt;
	static const int NUMBER_OF_QUEUES = 128;
	QueueType<string>* queues[NUMBER_OF_QUEUES];

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