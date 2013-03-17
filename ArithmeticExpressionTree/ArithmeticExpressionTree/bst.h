#include <cstdlib>
#include <ostream>
#include <sys/stat.h>
#include "queue.h"
#ifndef MYBST
#define MYBST

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
	BST();
	// Constructor
	// Pre:  None
	// Post: BST is initialized

	~BST();
	// Destructor
	// Function: Calls recursive function Destroy to destroy the tree
	// Pre:		 BST has been initialized
	// Post:	 Nodes of tree are recursively deleted and root is set to null

	BST(const BST& originalTree);
	// Copy constructor
	// Function: Calls the recursive function CopyTree to copy originalTree into root
	// Pre:		 orginalTree is a valid BST
	// Post:	 BST is initialized with values from originalTree

	void operator=(BST& originalTree);
	// Assignment operator
	// Function: Calls recursive function Destroy to destroy the tree, then calls then
	//			 recursive function CopyTree to copy originalTree into root
	// Pre:		 BST has been initialized, originalTree is a valid BST
	// Post:	 BST has values from originalTree

	void MakeEmpty();
	// Function: Initializes tree to empty state
	// Pre:		 BST has been initialized
	// Post:	 tree is empty, root is null	 

	bool IsEmpty() const;
	// Function: Returns true if the tree is empty and false otherwise
	// Pre:		 BST has been initialized
	// Post:	 Function value = (tree is empty)

	bool IsFull() const;
	// Function: Returns true if the free store has no room for another node and false
	//			 otherwise
	// Pre:		 BST has been initialized
	// Post:	 Function Value = (memory unavailable to create new nodes)
	
	int GetLength() const;
	// Function: Calls the recursive function CountNodes to count the nodes in root
	// Pre:		 BST has been initialized
	// Post:	 Function value = number of nodes in root

	ItemType GetItem(ItemType item, bool& found);
	// Function: Calls recursive function Retrieve to search the tree for item
	// Pre:		 BST has been initialized, key member of item is initalized
	// Post:	 If there is an element someItem whose key matches item's key, then
	//			 found = true and a copy of someItem is returned; otherwise, found =
	//			 false and item is returned

	void PutItem(ItemType item);
	// Function: Calls the recursive function Insert to insert item into tree
	// Pre:		 BST has been initialized, tree is not full, item is not in tree
	// Post:	 item is in tree, binary search property is maintained

	void DeleteItem(ItemType item);
	// Function: Calls the recursive function Delete to delete item from tree
	// Pre:		 BST has been intialized, key member of item is initialized, one and only
	//			 one element in tree has a key matching item's key
	// Post:	 No element in tree has a key matching item's key

	void ResetTree(OrderType order);
	// Function: Calls a function to create a queue of the tree elements in the desired
	//			 order
	// Pre:		 BST has been initialized
	// Post:	 Current position is prior to root of tree

	ItemType GetNextItem(OrderType order, bool& finished);
	// Function: Gets the next element in tree
	// Pre:		 BST has been initialized, current position is defined, element at
	//			 current position is not last in tree
	// Post:	 Current position is one position beyond current position at entry to
	//			 GetNextItem, finished = (current position is last in tree), a copy of
	//			 element at current position is returned

	void Print(std::ostream& outFile);
	// Function: Calls recursive function PrintTree to print item in the tree
	// Pre:		 BST has been initialized, outFile has been opened for writing
	// Post:	 Items in the tree have been printed in ascending key order, outFile is
	//			 still open

	ItemType RetrieveRoot();
	// Function: Returns root info
	// Pre:		 BST has been initialized
	// Post:	 Data in root node is returned, throws TreeEmpty exception if root is
	//			 null

	bool IsFullTree();
	// Function: Calls recursive function IsFullTreeHelper to check tree to see if full
	//			 (all nodes have zero or two children)
	// Pre:		 BST has been intialized
	// Post:	 Returns bool value if all nodes of tree have either zero or two children

private:
	TreeNode<ItemType>* root;
	QueueType<ItemType> preQue;
	QueueType<ItemType> inQue;
	QueueType<ItemType> postQue;
	QueueType<TreeNode<ItemType>*>* rows;

	void Destroy(TreeNode<ItemType>*& tree);
	// Function: Recursively frees the nodes in tree
	// Pre:		 tree is null or valid BST
	// Post:	 tree is empty, nodes have been deallocated

	void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree);
	// Function: Recursively copies the nodes of originalTree into copy
	// Pre:		 none
	// Post:	 copy is the root of a tree that is a duplicate of originalTree

	int CountNodes(TreeNode<ItemType>* tree);
	// Function: Recursively counts the nodes in tree
	// Pre:		 tree is initialized
	// Post:	 Returns the number of nodes in tree

	void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found);
	// Function: Recursively searches tree for item
	// Pre:		 tree is initialized
	// Post:	 If there is an element someItem whose key matches item's, found is true
	//			 and item is set to a copy of someItem; otherwise, found is false and
	//			 item is unchanged

	void Insert(TreeNode<ItemType>*& tree, ItemType item);
	// Function: Inserts item into tree.
	// Pre:		 tree is initialized, item is initialized
	// Post:	 item is in tree; search property is maintained; throws DuplicateItem
	//			 exception

	void DeleteNode(TreeNode<ItemType>*& tree);
	// Function: Deletes the node pointed to by tree
	// Pre:		 tree is initialized
	// Post:	 The user's data in the node pointed to by tree is no longer in the tree,
	//			 if tree is a leaf node or has only one non-NULL child pointer, the node
	//			 pointed to by tree is deleted; otherwise, the user's data is replaced by
	//			 its logical predecessor and the predecessor's node is deleted

	void Delete(TreeNode<ItemType>*& tree, ItemType item);
	// Function: Deletes item from tree
	// Pre:		 tree is initialized, key member of item is initalized
	// Post:	 Item is not in tree

	void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);
	// Function: Sets data to the info member of the rightmost node in tree
	// Pre:		 tree is initialized
	// Post:	 data contains rightmost node in tree

	void PreOrder(TreeNode<ItemType>* tree);
	// Function: Enqueues tree items in preorder
	// Pre:		 tree is initialized
	// Post:	 preQue contains tree items in preorder

	void InOrder(TreeNode<ItemType>* tree);
	// Function: Enqueues tree items in inorder
	// Pre:		 tree is initialized
	// Post:	 inQue contains tree items in inorder

	void PostOrder(TreeNode<ItemType>* tree);
	// Function: Enqueues tree items in postorder
	// Pre:		 tree is initialized
	// Post:	 postQue contains tree items in postorder

	void PrintTree(std::ostream& outStream, int& height) const;
	// Function: Prints tree diagram on outStream
	// Pre:		 BST has been initialized
	// Post:	 tree diagram is streamed to outStream

	void GetHeight(TreeNode<ItemType>* tree, int level, int& height);
	// Function: Gets height of tree
	// Pre:		 tree is initialized
	// Post:	 height contains height of tree

	void EnqueueRows(TreeNode<ItemType>* tree, int level, int height);
	// Function: EnQueues tree nodes by row
	// Pre:		 tree is initialized, height contains height of tree
	// Post:	 rows contains queues of tree nodes

	void IsFullTreeHelper(TreeNode<ItemType>*& tree, bool& full);
	// Function: Recursively checks to see if tree node has either zero or two children
	// Pre:		 tree is initialized
	// Post:	 the value of full is set to false if the tree node has only one child
};

#include "bst.template"
#endif