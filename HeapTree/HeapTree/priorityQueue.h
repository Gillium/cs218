#include <cstdlib>
#include <sys/stat.h>
#ifndef MYPRIORITYQUEUE
#define MYPRIORITYQUEUE

using namespace std;

template <class T>
struct NodeTypeP
{
	T data;
	NodeTypeP<T>* next;
};

template <class T>
class PriorityQueueType
{
public:
	PriorityQueueType();
	// Constructor
	// Pre:  None
	// Post: PriorityQueue is initialized

	~PriorityQueueType();
	// Deconstrutor
	// Pre:	 PriorityQueue is initialized
	// Post: PriorityQueue is empty, nodes are freed

	PriorityQueueType(const PriorityQueueType<T>& acopy);
	// Copy constructor
	// Pre:  acopy is a valid PriorityQueueType 
	// Post: PriorityQueue is initialized with values from acopy

	void operator=(const PriorityQueueType<T>& acopy);
	// Assignment operator
	// Function: Overwrites queue with values from acopy
	// Pre:		 PriorityQueue is initialized
	// Post:	 PriorityQueue has values from acopy

	bool IsFull()const;
	// Function: To check to see if the queue is full
	// Pre:		 PriorityQueue is initialized
	// Post:	 Function value = (queue is full)
	
	bool IsEmpty();
	// Function: To check to see if the queue is empty
	// Pre:		 PriorityQueue is initialized
	// Post:	 Function value = (queue is empty)

	void MakeEmpty();
	// Function: Initializes the queue to an empty state
	// Pre:		 None
	// Post:	 PriorityQueue is empty

	void EnQueue(T newItem);
	// Function: Adds newItem to the queue
	// Pre:		 PriorityQueue is initialized
	// Post:	 If (the priority queue is full), exception FullPQ is thrown; else
	//			 newItem is in the queue

	void DeQueue(T &item);
	// Function: Removes front item from the queue and returns it in item
	// Pre:		 PriorityQueue is initialized
	// Post:	 if (queue is empty), EmptyQueue exception is thrown and item is undefined,
	//			 else front element is removed from queue and item is a copy of removed
	//			 element

	void Print(std::ostream& outStream);
	// Function: PriorityQueue is printed
	// Pre:		 PriorityQueue is initialized, outFile is open for writing
	// Post:	 elements are streamed to outStream

	unsigned int Length()const;
	// Function: Returns length of queue
	// Pre:		 PriorityQueue is initialized
	// Post:	 function value = (length)

private:
	NodeTypeP<T>* rearPTR;
	unsigned int length;
};

#include "priorityQueue.template"
#endif