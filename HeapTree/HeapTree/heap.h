#include <cstdlib>
#include <sys/stat.h>
#ifndef MYHEAP
#define MYHEAP

class EmptyTree
{
};

class DuplicateItem
{
};

class NotFound
{
};

template <class ItemType>
class Heap
{
public:
	Heap();
	// Constructor
	// Pre:  None
	// Post: Heap is initialized

	~Heap();
	// Destructor
	// Function: Destroys the heap
	// Pre:		 Heap has been initialized
	// Post:	 elements array is deleted

	Heap(const Heap<ItemType>& orginalHeap);
	// Copy constructor
	// Function: Creates a new heap that is a copy of orginalHeap
	// Pre:		 orginalHeap is a valid Heap
	// Post:	 elements is initialized with values from originalHeap

	void operator=(const Heap<ItemType>& orginalHeap);
	// Assignment operator
	// Function: Replaces the elements of Heap with the contents of originalHeap
	// Pre:		 Heap has been initialized, originalHeap is a valid Heap
	// Post:	 elements has values from originalHeap

	void MakeEmpty();
	// Function: Initializes heap to empty state
	// Pre:		 Heap has been initialized
	// Post:	 elements is empty

	bool IsEmpty() const;
	// Function: Returns true if the heap is empty and false otherwise
	// Pre:		 Heap has been initialized
	// Post:	 Function value = (elements is empty)

	bool IsFull() const;
	// Function: Returns true if the free store has no room for another element and false
	//			 otherwise
	// Pre:		 Heap has been initialized
	// Post:	 Function Value = (memory unavailable to create new element)

	int GetLength() const;
	// Function: Gets the number of elements in the heap
	// Pre:		 Heap has been initialized
	// Post:	 Function value = length of elements array

	ItemType GetItem(ItemType item);
	// Function: Gets item from heap or raises not found exception 
	// Pre:		 Heap has been initialized
	// Post:	 Function value = (item) or throws exception if not found

	void HeapInsert(ItemType item);
	// Function: Inserts item into heap
	// Pre:		 Heap has been initialized, heap is not full, item is not in heap
	// Post:	 item is inserted in heap, elements array is reheaped

	ItemType HeapDelete(ItemType item);
	// Function: Deletes item from heap
	// Pre:		 Heap has been intialized, heap is not empty
	// Post:	 item is removed from heap, elements array is reheaped

	void Print(std::ostream& outStream);
	// Function: Heap is printed
	// Pre:		 Heap has been initialized, outFile has been opened for writing
	// Post:	 elements are streamed to outStream

private:
	ItemType* elements;
	size_t array_size;
	size_t length;
	void resize();

	void ReheapUp();
	// Function: Restores the order property to the heap between root and bottom
	// Pre:		 The order property is satisfied from the root of the heap through the next-to-last element; the (bottom) element may violate the order property
	// Post:	 The order property applies to all elements of the heap from root through bottom

	void ReheapDown();
	// Function: Restores the order property of heaps to the tree between root and bottom
	// Pre:		 The order property of heaps may be violated only by the root element of the tree
	// Post:	 The order property applies to all elements of the heap
};

#include "heap.template"
#endif