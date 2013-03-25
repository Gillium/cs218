#include <cstdlib>
#include <ostream>
#include <sys/stat.h>
#ifndef MYHEAP
#define MYHEAP

class HeapEmpty
{
};

class HeapFull
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

	void HeapInsert(ItemType item);
	// Function: Inserts item into heap, if necessary resize array
	// Pre:		 Heap is initialized
	// Post:	 If full throws exception, otherwise item is inserted in heap, elements
	//			 array is reheaped upward, length is increased by 1, array_size is
	//			 increased if necessary

	ItemType HeapDelete();
	// Function: Deletes and returns root element from heap
	// Pre:		 Heap is intialized
	// Post:	 If empty throws HeapEmpty exception, otherwise item is removed from
	//			 heap, elements array is reheaped downward, length is decreased by 1

	void Print(std::ostream& outStream);
	// Function: Heap is printed
	// Pre:		 Heap is initialized, outFile is opened for writing
	// Post:	 elements are streamed to outStream

private:
	ItemType* elements;
	size_t array_size;
	size_t length;
	static const size_t DEFAULT_SIZE = 5;
	static const size_t ADD_SIZE = 5;

	void Resize();
	// Function: Resized dynamic heap array
	// Pre:		 Heap array is intialized
	// Post:	 Heap array is resized, array_size is set to new array size

	void ReheapUp(int rootIndex, int bottomIndex);
	// Function: Recursively restores the order property to the heap between root and bottom
	// Pre:		 The order property is satisfied from the root of the heap through the
	//			 next-to-last element; the (bottom) element may violate the order property
	// Post:	 The order property applies to all elements of the heap from root through
	//			 bottom

	void ReheapDown(int rootIndex, int bottomIndex);
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

	size_t GetParentIndex(size_t index);
	// Function: Gets parent of index
	// Pre:		 Heap is initialized, index must be greater then zero
	// Post:	 Returns index of parent element
};

#include "heap.template"
#endif