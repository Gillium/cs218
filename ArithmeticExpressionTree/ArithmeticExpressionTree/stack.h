#include <string>
#include <cstdlib>
#ifndef MYSTACK
#define MYSTACK
#include <sys/stat.h>

using namespace std;

class FullStack
// Exception class used by Push when stack is full
{
};

class EmptyStack
// Exception class used by Pop and Top when stack is empty
{
};

#ifndef NODE_TYPE
#define NODE_TYPE
template<class T>
struct NodeType
{
	T data;
	NodeType* next;
};
#endif

template<class T>
class Stack
{
public:
	Stack();
	// Pre: None
	// Post: Stack has been initialized

	~Stack();
	// Pre: stack is initialized
	// Post: stack is empty

	void Push(T newItem);
	// Function: Adds item to the top of the stack
	// Pre: Stack has been initialized
	// Post: If (stack is full), exception FullStack is thrown, else item is at the top
	//		 of the stack
	
	void Pop();
	// Function: Removes top item from the stack
	// Pre: Stack has been initialized
	// Post: If (stack is empty), exception EmptyStack is thrown, else top item has been
	//		 removed from the stack
	
	T Top() const;
	// Function: Returns a copy of the top item on the stack
	// Pre: Stack has been initialized
	// Post: If (stack is empty), exception EmptyStack is thrown, else a copy of the top
	//		 element is returned.

	bool IsEmpty () const;
	// Function: Determines whether the stack is empty
	// Pre: Stack has been initialized
	// Post: None

	bool IsFull() const;
	// Function: Determines whether the stack is full
	// Pre: Stack has been initialized
	// Post: None

private:
	NodeType<T>* topPtr;
};

#include "stack.template"
#endif