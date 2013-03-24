#include <cstdlib>
#include <sys/stat.h>
#ifndef MYPRIORITYQUEUE
#define MYPRIORITYQUEUE

using namespace std;

template <class ItemType>
struct NodeType
{
	ItemType data;
	NodeType<ItemType>* next;
};

template <class ItemType>
class PriorityQueueType
{
public:
	PriorityQueueType();
	// Constructor
	// Pre:  None
	// Post: PriorityQueue is initialized

	~PriorityQueueType();
	// Deconstructor
	// Pre:  PriorityQueue is initialized
	// Post: PriorityQueue is empty, nodes are freed

	PriorityQueueType(const PriorityQueueType<ItemType>& acopy);
	// Copy constructor
	// Pre:  acopy is a valid PriorityQueue
	// Post: PriorityQueue is initialized with values from acopy

	void operator=(const PriorityQueueType<ItemType>& acopy);
	// Assignment operator
	// Function: Overwrites PriorityQueue with values from acopy
	// Pre:		 PriorityQueue is initialized
	// Post:	 PriorityQueue has values from a copy

	void MakeEmpty();
	// Function: Initializes the PriorityQueue to an empty state
	// Pre:		 None
	// Post:	 PriorityQueue is empty

	bool IsEmpty()const;
	// Function: Tests whether the queue is empty
	// Pre:		 PriorityQueue is initialized
	// Post:	 Function value = (queue is empty)

	bool IsFull()const;
	// Function: Tests whether the queue is full
	// Pre:		 PriorityQueue is initialized
	// Post:	 Function value = (queue is full)

	void Enqueue(ItemType newItem);
	// Function: Adds newItem to the queue
	// Pre:		 PriorityQueue is initialized
	// Post:	 If (the priority queue is full), exception FullPQ is thrown; else newItem is in the queue

	void Dequeue(ItemType& item);
	// Function: Removes element with highest priority and returns it in item
	// Pre:		 PriorityQueue is initialized
	// Post:	 If (PriorityQueue is empty), exception EmptyPQ is thrown; else highest priority element is removed from PriorityQueue, item is a copy of removed element

	unsigned int Length()const;
	// Function: Returns length of PriorityQueue
	// Pre:		 PriorityQueue is initialized
	// Post:	 Function value = (length)

private:
	NodeType<ItemType>* rearPTR;
	unsigned int length;
};

#include "priorityQueue.template"
#endif