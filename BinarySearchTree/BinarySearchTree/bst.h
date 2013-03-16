#include <cstdlib>
#include <ostream>
#include <sys/stat.h>
#include "queue.h"
#ifndef MYBST
#define MYBST

using namespace std;

class EmptyTree
{
};

class DuplicateItem
{
};

template <class ItemType>
struct TreeNode
{
	ItemType info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class BST
{
public:
	// Constructor
	BST();

	// Destructor
	~BST();
	// Function: Calls recursive function Destroy to destroy the tree.

	// Copy constructor
	BST(const BST& originalTree);
	// Function:

	// Assignment operator
	void operator=(BST& originalTree);

	void MakeEmpty();
	// Function: Initializes tree to empty state.
	// Pre:
	// Post:	 Tree exists and is empty.	 

	bool IsEmpty() const;
	// Function: Returns true if the tree is empty and false otherwise.
	// Pre:
	// Post:	 Function value = (tree is empty).

	bool IsFull() const;
	// Function: Returns true if the free store has no room for another node and false otherwise.
	// Pre:
	// Post:	 Function Value = (tree is full).
	
	int GetLength() const;
	// Function: Calls the recurisive function CountNodes to count the nodes in the tree.
	// Pre:
	// Post:	 Function value = number of elements in tree.

	ItemType GetItem(ItemType item, bool& found);
	// Function: Calls recursive function Retrieve to search the tree for item.
	// Pre:		 Key member of item is initalized.
	// Post:	 If there is an element someItem whose key matches item's key, then
	//			 found = true and a copy of someItem is returned; otherwise, found = false
	//			 and item is returned. Tree is unchanged.

	void PutItem(ItemType item);
	// Function: Calls the recursive function Insert to insert item into tree.
	// Pre:		 Tree is not full. Item is not in tree.
	// Post:	 Item is in tree. Binary search property is maintained.

	void DeleteItem(ItemType item);
	// Function: Calls the recursive function Delete to delete item from tree.
	// Pre:		 Key member of item is initialized. One and only one element in tree has
	//			 a key matching item's key.
	// Post:	 No element in tree has a key matching item's key.

	void ResetTree(OrderType order);
	// Function: Calls a function to create a queue of the tree elements in the desired order
	// Pre:
	// Post:	 Current position is prior to root of tree.

	ItemType GetNextItem(OrderType order, bool& finished);
	// Function: Gets the next element in tree.
	// Pre:		 Curent position is defined. Element at current position is not last in tree.
	// Post:	 Current position is one position beyond current position at entry to
	//			 GetNextItem. finished = (current position is last in tree). A copy of
	//			 element at current position is returned.

	void Print(std::ostream& outFile);
	// Function: Calls recursive function PrintTree to print item in the tree.
	// Pre:		 outFile has been opened for writing.
	// Post:	 Items in the tree have been printed in ascending key order. outFile is still open.

	ItemType RetrieveRoot();
	// Function: Returns root info
	// Pre:		 Tree is initialized
	// Post:	 Data in root node is returned, throws TreeEmpty exception

	bool IsFullTree();
	// Function: Calls recursive function IsFullTreeHelper to check tree to see if full
	// Pre:		 Tree is intialized
	// Post:	 returns bool value if all nodes of tree have either zero or two children

private:
	TreeNode<ItemType>* root;
	QueueType<ItemType> preQue;
	QueueType<ItemType> inQue;
	QueueType<ItemType> postQue;
	unsigned int height;
	QueueType<TreeNode<ItemType>*>* rows;

	void Destroy(TreeNode<ItemType>*& tree);
	// Function:
	// Pre:
	// Post:	tree is empty; nodes have been deallocated.

	void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree);
	// Function:
	// Pre:
	// Post:	copy is the root of a tree that is a duplicate of originalTree.

	int CountNodes(TreeNode<ItemType>* tree);
	// Function:
	// Pre:
	// Post:	Returns the number of nodes in the tree.

	void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found);
	// Function: Recursively searches tree for item
	// Pre:
	// Post:	 If there is an element someItem whose key matches item's, found is true
	//			 and item is set to a copyu of someItem; otherwise, found is false and
	//			 item is unchanged

	void Insert(TreeNode<ItemType>*& tree, ItemType item);
	// Function: Inserts item into tree.
	// Pre:
	// Post:	 item is in tree; search property is maintained.

	void DeleteNode(TreeNode<ItemType>*& tree);
	// Function: Deletes the node pointed to by tree.
	// Pre:
	// Post:	 The user's data in the node pointed to by tree is no longer in the tree. If
	//			 tree is a leaf node or has only one non-NULL child pointer, the node pointed
	//			 to by tree is deleted; otherwise, the user's data is replaced by its logical
	//			 predecessor and the predecessor's node is deleted.

	void Delete(TreeNode<ItemType>*& tree, ItemType item);
	// Function: Deletes item from tree
	// Pre:
	// Post:	 Item is not in tree

	void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);
	// Function: Sets data to the info member of the rightmost node in tree.
	// Pre:
	// Post:

	void PrintTree(std::ostream& outFile) const;
	// Function: Prints info member of items in tree in sorted order on outFile.
	// Pre:
	// Post:

	void PreOrder(TreeNode<ItemType>*, QueueType<ItemType>&);
	// Function: Enqueues tree items in preorder
	// Pre:
	// Post:

	void InOrder(TreeNode<ItemType>*, QueueType<ItemType>&);
	// Function: Enqueues tree items in inorder
	// Pre:
	// Post:

	void PostOrder(TreeNode<ItemType>*, QueueType<ItemType>&);
	// Function: Enqueues tree items in postorder
	// Pre:
	// Post:

	void SetHeight(TreeNode<ItemType>* tree, unsigned int level);
	// Function:
	// Pre:
	// Post:

	void EnqueueRows(TreeNode<ItemType>* tree, unsigned int level);
	// Function:
	// Pre:
	// Post:

	void IsFullTreeHelper(TreeNode<ItemType>*& tree, bool& full);
	// Function:
	// Pre:
	// Post:
};

#include "bst.template"
#endif