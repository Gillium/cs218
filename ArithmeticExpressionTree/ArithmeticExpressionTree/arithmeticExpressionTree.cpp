#include "arithmeticExpressionTree.h"
#include "stack.h"
#include <stdlib.h>

// OverloadedConstructor
ArithmeticExpressionTree::ArithmeticExpressionTree(string expression)
// Function: Greates an instance by parsing the infixExpression
{
	infixExpr = expression;
	Parse();
}

string ArithmeticExpressionTree::GetExpression(ExprType type)
// Function: Prints the corresponding prefix, postfix, and infix
//			 expression by using pre-order, post-order, and in-order
//			 traversals of the binary tree representation of the expression.
{
	if (type == PREFIX)
	{
		PreOrder(root);
		return prefixExpr;
	}
	else if (type == POSTFIX)
	{
		PostOrder(root);
		return postfixExpr;
	}
	else
		// puts user input in correct spacing order
		infixExpr = "";
		// defaults to infixExpr
		InOrder(root);
		return infixExpr;
}

double ArithmeticExpressionTree::Evaluate()
// Function: Calls recursive function EvaluateTree
{
	double answer;
	answer = EvaluateTree(root);
	return answer;
}

void ArithmeticExpressionTree::Print(std::ostream& outStream)
// Function: Calls recursive function PrintTree
{
	if (root == NULL)
		cout << "The tree is empty!" << endl;
	else
	{
		int height = 0;
		GetHeight(root, 0, height);

		rows = new QueueType<TreeNode<string>*>[height];
	
		for (int i = 0; i < height; i++)
		{
			rows[i] = QueueType<TreeNode<string>*>();
		}

		EnqueueRows(root, 0, height);
		PrintTree(outStream, height);

		for (int i = 0; i < height; i++)
		{
			rows[i].~QueueType<TreeNode<string>*>();
		}
	}
}

void ArithmeticExpressionTree::PrintTree(std::ostream& outStream, int&height)
// Function: Prints tree diagram on outStream
// Pre:		 AET has been initialized
// Post:	 tree diagram is streamed to outStream
{
	for (int i = 0; i < height; i++)
	{
		while (!rows[i].IsEmpty())
		{
			TreeNode<string>* tempPtr;
			rows[i].DeQueue(tempPtr);

			for (int j = 0; j < (int)(pow(2.0, (double)(height + 1)) / (pow(2.0, (double)i) + 1)); j++)
			{
				outStream << "  ";
			}

			if (tempPtr == NULL)
				outStream << " ";
			else
				outStream << tempPtr->info;
		}
		outStream << endl;
	}
}

void ArithmeticExpressionTree::Parse()
// Function: Parses infixExpression and builds tree.
{
	int parens = 0;
	bool invalidChar = false;

	Stack<char> opStack = Stack<char>();
	Stack<TreeNode<string>*> tnStack = Stack<TreeNode<string>*>();

	for (unsigned int i = 0; i < infixExpr.length(); i++)
	{
		// When you encounter an operand, made a node and put on tnStack
		if (isdigit(infixExpr[i]))
		{
			int startPos = i;
			int count = 1;

			while(i < infixExpr.length() - 1)
			{
				if (isdigit(infixExpr[i + 1]))
				{
					count++;
					i++;
				}
				else
					break;
			}

			TreeNode<string>* tempNodePtr = new TreeNode<string>;
			tempNodePtr->info = infixExpr.substr(startPos, count);
			tempNodePtr->left = NULL;
			tempNodePtr->right = NULL;
			tnStack.Push(tempNodePtr);
		}

		// Push each '(' onto the opStack
		else if (infixExpr[i] == '(')
		{
			++parens;
			opStack.Push(infixExpr[i]);
		}

		// When you encounter ')', pop operators off the opStack, build a Tree node with
		// the top two nodes in the tnStack as left (2nd one popped) and right
		// (1st one popped) children.
		else if (infixExpr[i] == ')')
		{
			--parens;
			while (!opStack.IsEmpty())
			{
				if (opStack.Top() == '(')
				{
					opStack.Pop();
					break;
				}
				else
				{
					TreeNode<string>* tempNodePtr = new TreeNode<string>;
					tempNodePtr->info = opStack.Top();
					tempNodePtr->right = tnStack.Top();
					tnStack.Pop();
					tempNodePtr->left = tnStack.Top();
					tnStack.Pop();
					tnStack.Push(tempNodePtr);
					opStack.Pop();
				}
			}
		}

		// Ignore spaces
		else if (isspace(infixExpr[i]))
			continue;

		// When you encounter an operator.
		else if (infixExpr[i] == '*' || infixExpr[i] == '/' || infixExpr[i] == '%' || infixExpr[i] == '-' || infixExpr[i] == '+')
		{
		//	i. if the stack is empty, push the operator onto the stack
			if (opStack.IsEmpty())
				opStack.Push(infixExpr[i]);

		//	ii. if the stack is not empty, pop operators of greater or equal
		//	precendence from the stack and append them to postfixExpr. you
		//	stop either you encounter either a '(' or an operator of lower
		//	precendence or when the stack becomes empty. (you need a 
		//	select statement and another loop for this). You then push the new operator onto the stack.
			else
			{
				while(!opStack.IsEmpty() && opStack.Top() != '(')
				{
					if (!IsLowerOpPrec(opStack.Top(),infixExpr[i]))
					{
						TreeNode<string>* tempNodePtr = new TreeNode<string>;
						tempNodePtr->info = opStack.Top();
						tempNodePtr->right = tnStack.Top();
						tnStack.Pop();
						tempNodePtr->left = tnStack.Top();
						tnStack.Pop();
						tnStack.Push(tempNodePtr);
						opStack.Pop();
					}
					else
						break;
				}

				opStack.Push(infixExpr[i]);
			}
		}
		else
		{
			invalidChar = true;
			break;
		}

	}

	// when you reach the end of the infixExpr, pop the remaining operators off the
	// opStack while building the rest of the tree
	while (!opStack.IsEmpty())
	{
		TreeNode<string>* tempNodePtr = new TreeNode<string>;
		tempNodePtr->info = opStack.Top();
		tempNodePtr->right = tnStack.Top();
		tnStack.Pop();
		tempNodePtr->left = tnStack.Top();
		tnStack.Pop();
		tnStack.Push(tempNodePtr);
		opStack.Pop();
	}

	if (!tnStack.IsEmpty() )
	  root = tnStack.Top(); 
	tnStack.Pop(); // memory leak?
	
	if (parens != 0)
		throw Unbalanced();
    if (invalidChar)
		throw InvalidCharacter();
}

bool ArithmeticExpressionTree::IsLowerOpPrec(char a, char b)
// Function: Returns true when a has a lower operator precedence then b
// Pre: None
// Post: None
{
	switch(a)
	{
		case '+':
			return(b == '*' || b == '/' || b == '%');
		case '-':
			return(b == '*' || b == '/' || b == '%');
		default:
			return false;
	}
}

double ArithmeticExpressionTree::EvaluateTree(TreeNode<string>* tree)
// Function: Evaluates the expression in the tree
{
	if (tree != NULL)
	{
		// AET is always full, so only check for null left node
		if (tree->left == NULL)
			return atof(tree->info.c_str());

		double leftVal = EvaluateTree(tree->left);
		double rightVal = EvaluateTree(tree->right);

		switch(tree->info[0])
		{
			case '+':
				return leftVal + rightVal;
				break;
			case '-':
				return leftVal - rightVal;
				break;
			case '*':
				return leftVal * rightVal;
				break;
			case '/':
				if (rightVal == 0)
				{
					throw(DivisionByZero());
				}
				else
				{
					return leftVal / rightVal;
					break;
				}
			case '%':
				return static_cast<int>(leftVal + 0.5) % static_cast<int>(rightVal + 0.5);
				break;
		}
	}
}

void ArithmeticExpressionTree::InOrder(TreeNode<string>* tree)
// Function: Generates a infix expression
{
	if (tree != NULL)
	{
		InOrder(tree->left);
		// Append to infixExpr
		infixExpr.append(tree->info);
		infixExpr.append(" ");
		InOrder(tree->right);
	}
}

void ArithmeticExpressionTree::PreOrder(TreeNode<string>* tree)
// Function: Generates a prefix expression
{
	if (tree != NULL)
	{
		// Append to prefixExpr;
		prefixExpr.append(tree->info);
		prefixExpr.append(" ");
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}

void ArithmeticExpressionTree::PostOrder(TreeNode<string>* tree)
// Function: Generates a postfix expression
{
	if (tree != NULL)
	{
		PostOrder(tree->left);
		PostOrder(tree->right);
		// Append to postfixExpr;
		postfixExpr.append(tree->info);
		postfixExpr.append(" ");
	}
}

void ArithmeticExpressionTree::GetHeight(TreeNode<string>* tree, int level, int& height)
// Function: Gets height of tree
// Pre:		 tree is initialized
// Post:	 height contains height of tree
{
	if (tree == NULL)
	{
		if (level > height)
			height = level;
	}
	else
	{
		GetHeight(tree->left, level + 1, height);
		GetHeight(tree->right, level + 1, height);
	}
}

void ArithmeticExpressionTree::EnqueueRows(TreeNode<string>* tree, int level, int height)
// Function: EnQueues tree nodes by row
// Pre:		 tree is initialized, height contains height of tree
// Post:	 rows contains queues of tree nodes
{
	if (tree == NULL)
	{
		if (level < height)
		{
			for (int i = 0; i < (height - level); i++)
			{
				for (unsigned int j = 0; j < pow(2.0, (double)i); j++)
				{
					rows[level + i].EnQueue(NULL);
				}
			}
		}
	}
	else
	{
		rows[level].EnQueue(tree);
		EnqueueRows(tree->left, level + 1, height);
		EnqueueRows(tree->right, level + 1, height);
	}
}