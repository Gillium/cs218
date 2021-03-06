#include <cstdlib>
#include <sys/stat.h>
#ifndef MYQUEUE
#define MYQUEUE

using namespace std;

class EmptyQueue
// Exception class used by DeQueue when queue is empty
{
};

template <class T>
struct NodeType {
	T data;
	NodeType<T>* next;
};

template <class T>
class QueueType {
public:
	QueueType();
	// Constructor
	// Pre:  None
	// Post: Queue is initialized

	~QueueType();
	// Deconstructor
	// Pre:  Queue is initialized
	// Post: Queue is empty, nodes are freed

	QueueType(const QueueType<T>& acopy);
	// Copy constructor
	// Pre: acopy is a valid QueueType 
	// Post: Queue is initialized with values from acopy

	void operator=(const QueueType<T>&acopy);
	// Assignment operator
	// Function: Overwrites queue with values from acopy
	// Pre:		 Queue is initialized
	// Post:	 Queue has values from acopy

	bool IsFull()const;
	// Function: To check to see if the queue is full
	// Pre:		 Queue is initialized
	// Post:	 Function value = (queue is full)

	bool IsEmpty()const;
	// Function: To check to see if the queue is empty
	// Pre:		 Queue is initialized
	// Post:	 Function value = (queue is empty)

	void MakeEmpty();
	// Function: Initializes the queue to an empty state
	// Pre:		 None
	// Post:	 Queue is empty

	void EnQueue(T item);
	// Function: Adds item to the rear of the queue
	// Pre:		 Queue is initilized
	// Post:	 if (queue is full), FullQueue exception is thrown, else item is a rear of
	//			 queue

	void DeQueue(T &item);
	// Function: Removes front item from the queue and returns it in item
	// Pre:		 Queue is initialized
	// Post:	 If (queue is empty), EmptyQueue exception is thrown and item is undefined,
	//			 else front element is removed from queue and item is a copy of removed
	//			 element

	unsigned int Length()const;
	// Function: Returns length of queue
	// Pre:		 Queue is initialized
	// Post:	 Function value = (length)

private:
	NodeType<T>* rearPTR;
	unsigned int length;
};

#include "queue.template"
#endif