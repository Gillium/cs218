#include <cstdlib>
#ifndef MYQUEUE
#define MYQUEUE
#include <sys/stat.h>

using namespace std;

class EmptyQueue
// Exception class used by DeQueue when queue is empty
{
};

#ifndef NODE_TYPE
#define NODE_TYPE
template <class T>
struct NodeType
{
	T data;
	NodeType<T>* next;
};
#endif

template <class T>
class QueueType
{
public:
	QueueType();
	// Pre: None
	// Post: Queue is initialized

	~QueueType();
	// Pre: Queue has been initialized
	// Post: Queue is empty, nodes are freed

	QueueType(const QueueType<T>& acopy);
	// Pre: acopy is a valid QueueType 
	// Post: Queue is initialized with values from acopy

	bool IsFull()const;
	// Function: To check to see if the queue is full
	// Pre: Queue has been initialized
	// Post: Function value = (queue is full)

	bool IsEmpty()const;
	// Function: To check to see if the queue is empty
	// Pre: Queue has been initialized
	// Post: Function value = (queue is empty)

	void MakeEmpty();
	// Function: Initializes the queue to an empty state
	// Pre: None
	// Post: Queue is empty

	void EnQueue(T item);
	// Function: Adds item to the rear of the queue
	// Pre: Queue has been initilized
	// Post: if (queue is full), FullQueue exception is thrown, else item is a rear of
	//		 queue

	void DeQueue(T &item);
	// Function: Removes front item from the queue and returns it in item
	// Pre: Queue has been initialized
	// Post: if (queue is empty), EmptyQueue exception is thrown and item is undefined,
	//		 else front element has been removed from queue and item is a copy of removed
	//		 element

	unsigned int Length()const;
	// Function: Returns length of queue
	// Pre: Queue has been initialized
	// Post: function value = (length)

	void operator=(const QueueType<T>&acopy);
	// Function: overwrites queue with values from acopy
	// Pre: Queue has been initialized
	// Post: Queue has values from acopy

private:
	NodeType<T>* rearPTR;
	unsigned int length;
};

#include "queue.template"
#endif