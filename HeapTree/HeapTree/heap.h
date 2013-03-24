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
	// Pre:		 Heap is initialized
	// Post:	 elements array is deleted, and length and array_size are set to zero

	Heap(const Heap<ItemType>& orginalHeap);
	// Copy constructor
	// Function: Creates a new heap that is a copy of orginalHeap
	// Pre:		 orginalHeap is a valid Heap
	// Post:	 elements is initialized with values from originalHeap, length and
	//			 array_size are set to orginalHeap values

	void operator=(const Heap<ItemType>& orginalHeap);
	// Assignment operator
	// Function: Replaces the elements of Heap with the contents of originalHeap
	// Pre:		 Heap is initialized, originalHeap is a valid Heap
	// Post:	 elements is initialized with values from originalHeap, length and
	//			 array_size are set to orginalHeap values

	void MakeEmpty();
	// Function: Initializes heap to empty state
	// Pre:		 Heap is initialized
	// Post:	 elements is empty

	bool IsEmpty() const;
	// Function: Returns true if the heap is empty and false otherwise
	// Pre:		 Heap is initialized
	// Post:	 Function value = (elements is empty)

	bool IsFull() const;
	// Function: Returns true if the free store has no room for another element and false
	//			 otherwise
	// Pre:		 Heap is initialized
	// Post:	 Function Value = (memory unavailable to create new element)

	unsigned int GetLength() const;
	// Function: Gets the number of elements in the heap
	// Pre:		 Heap is initialized
	// Post:	 Function value = length of elements array

	ItemType GetItem(ItemType item);
	// Function: Gets item from heap or raises not found exception 
	// Pre:		 Heap is initialized
	// Post:	 Function value = (item) or throws exception if not found

	void HeapInsert(ItemType item);
	// Function: Inserts item into heap
	// Pre:		 Heap is initialized, heap is not full, item is not in heap
	// Post:	 item is inserted in heap, elements array is reheaped

	ItemType HeapDelete(ItemType item);
	// Function: Deletes item from heap
	// Pre:		 Heap is intialized, heap is not empty
	// Post:	 item is removed from heap, elements array is reheaped

	void Print(std::ostream& outStream);
	// Function: Heap is printed
	// Pre:		 Heap is initialized, outFile is opened for writing
	// Post:	 elements are streamed to outStream

private:
	ItemType* elements;
	size_t array_size;
	size_t length;
	static const size_t DEFAULT_SIZE = 5;

	void Resize();
	// Function: Resized dynamic heap array
	// Pre:		 Heap array is intialized
	// Post:	 Heap array is resized

	void ReheapUp();
	// Function: Restores the order property to the heap between root and bottom
	// Pre:		 The order property is satisfied from the root of the heap through the
	//			 next-to-last element; the (bottom) element may violate the order property
	// Post:	 The order property applies to all elements of the heap from root through
	//			 bottom

	void ReheapDown();
	// Function: Restores the order property of heaps to the tree between root and bottom
	// Pre:		 The order property of heaps may be violated only by the root element of
	//			 the tree
	// Post:	 The order property applies to all elements of the heap

	size_t GetLeftChildIndex(size_t index);
	// Function: Gets index of left child
	// Pre:		 Heap is initialized
	// Post:	 Returns left child index, might not reference valid element

	size_t GetRightChildIndex(size_t index);
	// Function: Gets index of right child
	// Pre:		 Heap is initialized
	// Post:	 Returns right child index, might not reference valid element

	void SearchHeap(int elementIndex, ItemType& item, bool& isFound);
	// Function: Recursive function that searches the heap for an item, if found it
	//			 returns the item otherwise sets isFound to false;
	// Pre:		 Heap is initialized, elementIndex is a valid index
	// Post:	 If found the item contains the element and isFound is set to true,
	//			 otherwise isFound is set to false
};

#include "heap.template"
#endif