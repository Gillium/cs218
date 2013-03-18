#include <cstdlib>
#include <ostream>
#include <sys/stat.h>
#include "queue.h"
#ifndef MYAVLT
#define MYAVLT

using namespace std;

// Exception classes
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
struct AVLTNode
{
	int bfactor;
	ItemType info;
	AVLTNode<ItemType>* left;
	AVLTNode<ItemType>* right;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class AVLT
{
public:
	AVLT();
	// Constructor
	// Pre:  None
	// Post: AVLT is initialized

	~AVLT();
	// Destructor
	// Function: Calls recursive function Destroy to destroy the tree
	// Pre:		 AVLT has been initialized
	// Post:	 Nodes of tree are recursively deleted and root is set to null

	AVLT(const AVLT& originalTree);
	// Copy constructor
	// Function: Calls the recursive function CopyTree to copy originalTree into root
	// Pre:		 orginalTree is a valid AVLT
	// Post:	 AVLT is initialized with values from originalTree

	void operator=(AVLT& originalTree);
	// Assignment operator
	// Function: Calls recursive function Destroy to destroy the tree, then calls then
	//			 recursive function CopyTree to copy originalTree into root
	// Pre:		 AVLT has been initialized, originalTree is a valid AVLT
	// Post:	 AVLT has values from originalTree

	void MakeEmpty();
	// Function: Initializes tree to empty state
	// Pre:		 AVLT has been initialized
	// Post:	 tree is empty, root is null

	bool IsEmpty() const;
	// Function: Returns true if the tree is empty and false otherwise
	// Pre:		 AVLT has been initialized
	// Post:	 Function value = (tree is empty)

	bool IsFull() const;
	// Function: Returns true if the free store has no room for another node and false
	//			 otherwise
	// Pre:		 AVLT has been initialized
	// Post:	 Function Value = (memory unavailable to create new nodes)
	
	int GetLength() const;
	// Function: Calls the recursive function CountNodes to count the nodes in root
	// Pre:		 AVLT has been initialized
	// Post:	 Function value = number of nodes in root

	ItemType GetItem(ItemType item, bool& found);
	// Function: Calls recursive function Retrieve to search the tree for item
	// Pre:		 AVLT has been initialized, key member of item is initalized
	// Post:	 If there is an element someItem whose key matches item's key, then
	//			 found = true and a copy of someItem is returned; otherwise, found =
	//			 false and item is returned

	void PutItem(ItemType item);
	// Function: Calls the recursive function Insert to insert item into tree
	// Pre:		 AVLT has been initialized, tree is not full, item is not in tree
	// Post:	 item is in tree, binary search property is maintained

	void DeleteItem(ItemType item);
	// Function: Calls the recursive function Delete to delete item from tree
	// Pre:		 AVLT has been intialized, key member of item is initialized, one and only
	//			 one element in tree has a key matching item's key
	// Post:	 No element in tree has a key matching item's key

	void ResetTree(OrderType order);
	// Function: Calls a function to create a queue of the tree elements in the desired
	//			 order
	// Pre:		 AVLT has been initialized
	// Post:	 Current position is prior to root of tree

	ItemType GetNextItem(OrderType order, bool& finished);
	// Function: Gets the next element in tree
	// Pre:		 AVLT has been initialized, current position is defined, element at
	//			 current position is not last in tree
	// Post:	 Current position is one position beyond current position at entry to
	//			 GetNextItem, finished = (current position is last in tree), a copy of
	//			 element at current position is returned

	void Print(std::ostream& outFile);
	// Function: Calls recursive function PrintTree to print item in the tree
	// Pre:		 AVLT has been initialized, outFile has been opened for writing
	// Post:	 Items in the tree have been printed in ascending key order, outFile is
	//			 still open

	ItemType RetrieveRoot();
	// Function: Returns root info
	// Pre:		 AVLT has been initialized
	// Post:	 Data in root node is returned, throws TreeEmpty exception if root is
	//			 null

	bool IsFullTree();
	// Function: Calls recursive function IsFullTreeHelper to check tree to see if full
	//			 (all nodes have zero or two children)
	// Pre:		 AVLT has been intialized
	// Post:	 Returns bool value if all nodes of tree have either zero or two children

	void RotateToLeft(AVLTNode<ItemType>*& tree);
	// Function: Rotates nodes left
	// Pre:		 tree is initialized
	// Post:	 tree nodes are rotated to left

	void RotateToRight(AVLTNode<ItemType>*& tree);
	// Function: Rotates nodes right
	// Pre:		 tree is initialized
	// Post:	 tree nodes are rotated to right

	void BalanceFromLeft(AVLTNode<ItemType>*& tree);
	// Function: Rotates nodes from left child of tree
	// Pre:		 tree is initialized
	// Post:	 tree is balanced

	void BalanceFromRight(AVLTNode<ItemType>*& tree);
	// Function: Rotates nodes from right child of tree
	// Pre:		 tree is initialized
	// Post:	 tree is balanced

private:
	AVLTNode<ItemType>* root;
	QueueType<ItemType> preQue;
	QueueType<ItemType> inQue;
	QueueType<ItemType> postQue;
	QueueType<AVLTNode<ItemType>*>* rows;

	void Destroy(AVLTNode<ItemType>*& tree);
	// Function: Recursively frees the nodes in tree
	// Pre:		 tree is null or valid AVLT
	// Post:	 tree is empty, nodes have been deallocated

	void CopyTree(AVLTNode<ItemType>*& copy, const AVLTNode<ItemType>* originalTree);
	// Function: Recursively copies the nodes of originalTree into copy
	// Pre:		 none
	// Post:	 copy is the root of a tree that is a duplicate of originalTree

	int CountNodes(AVLTNode<ItemType>* tree);
	// Function: Recursively counts the nodes in tree
	// Pre:		 tree is initialized
	// Post:	 Returns the number of nodes in tree

	void Retrieve(AVLTNode<ItemType>* tree, ItemType& item, bool& found);
	// Function: Recursively searches tree for item
	// Pre:		 tree is initialized
	// Post:	 If there is an element someItem whose key matches item's, found is true
	//			 and item is set to a copy of someItem; otherwise, found is false and
	//			 item is unchanged

	void Insert(const ItemType item);
	// Function: Inserts item into tree.
	// Pre:		 tree is initialized, item is initialized
	// Post:	 item is in tree; search property is maintained; throws DuplicateItem
	//			 exception

	void DeleteNode(AVLTNode<ItemType>*& tree);
	// Function: Deletes the node pointed to by tree
	// Pre:		 tree is initialized
	// Post:	 The user's data in the node pointed to by tree is no longer in the tree,
	//			 if tree is a leaf node or has only one non-NULL child pointer, the node
	//			 pointed to by tree is deleted; otherwise, the user's data is replaced by
	//			 its logical predecessor and the predecessor's node is deleted

	void Delete(AVLTNode<ItemType>*& tree, ItemType item);
	// Function: Deletes item from tree
	// Pre:		 tree is initialized, key member of item is initalized
	// Post:	 Item is not in tree

	void GetPredecessor(AVLTNode<ItemType>* tree, ItemType& data);
	// Function: Sets data to the info member of the rightmost node in tree
	// Pre:		 tree is initialized
	// Post:	 data contains rightmost node in tree

	void PreOrder(AVLTNode<ItemType>*, QueueType<ItemType>&);
	// Function: Enqueues tree items in preorder
	// Pre:		 tree is initialized
	// Post:	 preQue contains tree items in preorder

	void InOrder(AVLTNode<ItemType>*, QueueType<ItemType>&);
	// Function: Enqueues tree items in inorder
	// Pre:		 tree is initialized
	// Post:	 inQue contains tree items in inorder

	void PostOrder(AVLTNode<ItemType>*, QueueType<ItemType>&);
	// Function: Enqueues tree items in postorder
	// Pre:		 tree is initialized
	// Post:	 postQue contains tree items in postorder

	void PrintTree(std::ostream& outStream, int& height) const;
	// Function: Prints tree diagram on outStream
	// Pre:		 AVLT has been initialized
	// Post:	 tree diagram is streamed to outStream

	void GetHeight(AVLTNode<ItemType>* tree, int level, int& height);
	// Function: Gets height of tree
	// Pre:		 tree is initialized
	// Post:	 height contains height of tree

	void EnqueueRows(AVLTNode<ItemType>* tree, int level, int height);
	// Function: EnQueues tree nodes by row
	// Pre:		 tree is initialized, height contains height of tree
	// Post:	 rows contains queues of tree nodes

	void IsFullTreeHelper(AVLTNode<ItemType>*& tree, bool& full);
	// Function: Recursively checks to see if tree node has either zero or two children
	// Pre:		 tree is initialized
	// Post:	 the value of full is set to false if the tree node has only one child

	void InsertIntoAVL(AVLTNode<ItemType>*& tree, AVLTNode<ItemType>* newNode, bool& isTaller);
	// Function: Recursively inserts newNode into tree
	// Pre:		 tree is initialized, newNode is a valid tree node, isTaller is initialized
	// Post:	 tree contains newNode, tree is balanced

	void ReBalanceNode(AVLTNode<ItemType>*& tree);
	// Function: Recalculates the bfactor of the root node of tree and balances if necessary
	// Pre:		 tree is initialized
	// Post:	 tree is balanced, tree node has correct bfactor


};

#include "avlt.template"
#endif