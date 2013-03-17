#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include "queue.h"

using namespace std;

enum ExprType {INFIX, PREFIX, POSTFIX};

class Unbalanced
// Exception class used by Parse when parens are not matched
{
};

class InvalidCharacter
// Exception class used by Parse when infixExpr has an invalid character
{
};

class DivisionByZero
// Exception class used by Evaluate when division by zero 
{
};

template <class ItemType>
struct TreeNode
{
	ItemType info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

class ArithmeticExpressionTree
{
public:
    ArithmeticExpressionTree(string infixExpression);
	// Overloaded Constructor
	// Function:  Creates an instance by parsing the infixExpression
	// Pre:		  None
	// Post:	  AET is initialized

	~ArithmeticExpressionTree();
	// Destructor
	// Function: Calls recursive function Destroy to destroy the tree
	// Pre:		 AET has been initialized
	// Post:	 Nodes of tree are recursively deleted

	string GetExpression(ExprType type);
	// Function: Returns the corresponding prefix, postfix, and infix
	//			 expression by using pre-order, post-order, and in-order
	//			 traversals of the binary tree representation of the expression
	// Pre:		 AET is initialized
	// Post:	 prefixExpr, postfixExpr, or infixExpr contain the corresponding
	//			 expression, function value = (prefixExpr, postfixExpr, or infixExpr)

	double Evaluate();
	// Function: Calls recursive Function EvaluateTree
	// Pre:		 AET is initialized
	// Post:	 function value = (calculated value of recursive calls)

	void Print(std::ostream& outStream);
	// Function: Calls recursive functions GetHeight, EnqueueRows, and PrintTree
	// Pre:		 AET is initialized
	// Post:	 Tree diagram is printed to outStream, rows is empty

private:
	string infixExpr;
	string prefixExpr;
	string postfixExpr;
    TreeNode<string>* root;
	QueueType<TreeNode<string>*>* rows;
	
	void PrintTree(std::ostream& outStream, int& height);
	// Function: Prints tree diagram on outStream
	// Pre:		 AET is initialized
	// Post:	 tree diagram is streamed to outStream

	void Parse();
	// Function: Parses infixExpression and builds tree
	// Pre:		 infixExpr is initialized 
	// Post:	 root contains tree

	bool IsLowerOpPrec(char a, char b);
	// Function: Returns true when a has a lower operator precedence then b
	// Pre:		 None
	// Post:	 None

	double EvaluateTree(TreeNode<string>* tree);
	// Function: Recursively evaluates the expression in tree
	// Pre:		 tree is initialized
	// Post:	 function value = (value of expression tree)

	void InOrder(TreeNode<string>* tree);
	// Function: Generates a infix expression
	// Pre:		 tree is initialized, infixExpr is initialized
	// Post:	 infixExpr is appended by the tree info and space

	void PreOrder(TreeNode<string>* tree);
	// Function: Generates a prefix expression
	// Pre:		 tree is initialized, infixExpr is initialized
	// Post:	 infixExpr is appended by the tree info and space

	void PostOrder(TreeNode<string>* tree);
	// Function: Generates a postfix expression
	// Pre:		 tree is initialized, infixExpr is initialized
	// Post:	 infixExpr is appended by the tree info and space

	void GetHeight(TreeNode<string>* tree, int level, int& height);
	// Function: Recursively gets the height of the tree
	// Pre:		 tree is initialized, height is initialized 
	// Post:	 height contains level if level is greater than height

	void EnqueueRows(TreeNode<string>* tree, int level, int height);
	// Function: EnQueues tree nodes by row
	// Pre:		 tree is initialized, height contains height of tree
	// Post:	 rows contains queues of tree nodes

	void Destroy(TreeNode<string>*& tree);
	// Function: Recursively frees the nodes in tree
	// Pre:		 tree is null or valid BST
	// Post:	 tree is empty, nodes have been deallocated
};