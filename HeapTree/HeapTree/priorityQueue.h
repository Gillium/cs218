#include <cstdlib>
#include <sys/stat.h>
#include "queue.h"
#ifndef MYPRIORITYQUEUE
#define MYPRIORITYQUEUE

using namespace std;

template <class T>
class PriorityQueueType:QueueType<T>
{
public:
	void Enqueue(T newItem);
	// Function: Adds newItem to the queue
	// Pre:		 PriorityQueue is initialized
	// Post:	 If (the priority queue is full), exception FullPQ is thrown; else
	//			 newItem is in the queue

	void Print(std::ostream& outStream);
	// Function: PriorityQueue is printed
	// Pre:		 PriorityQueue is initialized, outFile is open for writing
	// Post:	 elements are streamed to outStream

	bool IsEmpty();

	void DeQueue(T &item);

private:
	NodeType<T>* rearPTR;
	unsigned int length;
};

#include "priorityQueue.template"
#endif