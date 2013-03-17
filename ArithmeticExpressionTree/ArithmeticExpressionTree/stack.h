#include <cstdlib>
#include <string>
#include <sys/stat.h>
#ifndef MYSTACK
#define MYSTACK

using namespace std;

class FullStack
// Exception class used by Push when stack is full
{
};

class EmptyStack
// Exception class used by Pop and Top when stack is empty
{
};

template<class T>
struct NodeTypeS
{
	T data;
	NodeTypeS<T>* next;
};


template<class T>
class Stack
{
public:
	Stack();
	// Constructor
	// Pre:  None
	// Post: Stack is initialized

	~Stack();
	// Deconstructor
	// Function: Deletes all pointers in the stack
	// Pre:		 Stack is initialized
	// Post:	 Stack is empty

	void Push(T newItem);
	// Function: Adds item to the top of the stack
	// Pre:		 Stack is initialized
	// Post:	 If (stack is full), exception FullStack is thrown, else item is at the top
	//			 of the stack
	
	void Pop();
	// Function: Removes top item from the stack
	// Pre:		 Stack is initialized
	// Post:	 If (stack is empty), exception EmptyStack is thrown, else top item has been
	//			 removed from the stack
	
	T Top() const;
	// Function: Returns a copy of the top item on the stack
	// Pre:		 Stack is initialized
	// Post:	 If (stack is empty), exception EmptyStack is thrown, else a copy of the top
	//			 element is returned.

	bool IsEmpty () const;
	// Function: Determines whether the stack is empty
	// Pre:		 Stack has been initialized
	// Post:	 None

	bool IsFull() const;
	// Function: Determines whether the stack is full
	// Pre:		 Stack is initialized
	// Post:	 None

private:
	NodeTypeS<T>* topPtr;
};

#include "stack.template"
#endif