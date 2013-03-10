#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>

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
	// Overloaded Constructor
    ArithmeticExpressionTree(string infixExpression);
	// Function: Creates an instance by parsing the infixExpression

	string GetExpression(ExprType type);
	// Function: Prints the corresponding prefix, postfix, and infix
	//			 expression by using pre-order, post-order, and in-order
	//			 traversals of the binary tree representation of the expression.

	double Evaluate();
	// Function: Calls recrusive Function EvaluateTree

	void Print(std::ostream& outStream);
	// Function: Calls recusive function PrintTree

private:
	string infixExpr;
	string prefixExpr;
	string postfixExpr;
    TreeNode<string>* root;
	
	void PrintTree(TreeNode<string>* tree, std::ostream& outStream);
	// Function: Prints a diagram of the binary tree.

	void Parse();
	// Function: Parses infixExpression and builds tree

	bool IsLowerOpPrec(char a, char b);
	// Function: Returns true when a has a lower operator precedence then b
	// Pre: None
	// Post: None

	double EvaluateTree(TreeNode<string>* tree);
	// Function: Evaluates the expression in the trees

	void InOrder(TreeNode<string>* tree);
	// Function: Generates a infix expression

	void PreOrder(TreeNode<string>* tree);
	// Function: Generates a prefix expression

	void PostOrder(TreeNode<string>* tree);
	// Function: Generates a postfix expression
};