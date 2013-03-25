#include <cstdlib>
#include <sys/stat.h>
#include "heap.h"
#ifndef MYPRIORITYHEAPQUEUE
#define MYPRIORITYHEAPQUEUE

using namespace std;

class FullPQ
{
};

class EmptyPQ
{
};

template <class ItemType>
class PriorityHeapQueueType
{
public:
	PriorityHeapQueueType();
	// Constructor
	// Pre:  None
	// Post: PriorityHeapQueue is initialized

	~PriorityHeapQueueType();
	// Deconstructor
	// Pre:  PriorityHeapQueue is initialized
	// Post: PriorityHeapQueue is empty, nodes are freed

	PriorityHeapQueueType(const PriorityHeapQueueType<ItemType>& acopy);
	// Copy constructor
	// Pre:  acopy is a valid PriorityHeapQueue
	// Post: PriorityHeapQueue is initialized with values from acopy

	void operator=(const PriorityHeapQueueType<ItemType>& acopy);
	// Assignment operator
	// Function: Overwrites PriorityHeapQueue with values from acopy
	// Pre:		 PriorityHeapQueue is initialized
	// Post:	 PriorityHeapQueue has values from a copy

	void MakeEmpty();
	// Function: Initializes the PriorityHeapQueue to an empty state
	// Pre:		 None
	// Post:	 PriorityHeapQueue is empty

	bool IsEmpty()const;
	// Function: Tests whether the queue is empty
	// Pre:		 PriorityHeapQueue is initialized
	// Post:	 Function value = (queue is empty)

	bool IsFull()const;
	// Function: Tests whether the queue is full
	// Pre:		 PriorityHeapQueue is initialized
	// Post:	 Function value = (queue is full)

	void Enqueue(ItemType newItem);
	// Function: Adds newItem to the queue
	// Pre:		 PriorityHeapQueue is initialized
	// Post:	 If (the priority queue is full), exception FullPQ is thrown; else newItem is in the queue

	void Dequeue(ItemType& item);
	// Function: Removes element with highest priority and returns it in item
	// Pre:		 PriorityHeapQueue is initialized
	// Post:	 If (PriorityHeapQueue is empty), exception EmptyPQ is thrown; else highest priority element is removed from PriorityHeapQueue, item is a copy of removed element

	unsigned int Length()const;
	// Function: Returns length of PriorityHeapQueue
	// Pre:		 PriorityHeapQueue is initialized
	// Post:	 Function value = (length)

	void Print(std::ostream& outStream);
	// Function: PriorityHeapQueue is printed
	// Pre:		 PriorityHeapQueue is initialized, outFile is open for writing
	// Post:	 elements are streamed to outStream

private:
	Heap<ItemType> elements;
	unsigned int length;
};

#include "priorityHeapQueue.template"
#endif