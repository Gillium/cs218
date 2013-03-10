#include "queue.h"
#include "stack.h"
#include "arithmeticExpressionTree.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{	
	string expression;

	// introduce program and give directions

	cout << "Please enter infix expression" << endl;
	getline(cin, expression);

	try
	{
		ArithmeticExpressionTree aet = ArithmeticExpressionTree(expression);
		double value = aet.Evaluate();
		cout << value << endl;
		cout << "Infix: " << aet.GetExpression(INFIX) << endl;
		cout << "Prefix: " << aet.GetExpression(PREFIX) << endl;
		cout << "Postfix: " << aet.GetExpression(POSTFIX) << endl;
		aet.Print(cout);
		cout << endl;
	}
	catch(Unbalanced)
	{
		cout << "Expression is unbalanced" << endl;
	}
	catch(InvalidCharacter)
	{
		cout << "Expression has an invalid character" << endl;
	}
	catch(DivisionByZero)
	{
		cout << "Cannot evaluate division by zero" << endl;
	}

	system("Pause");
	return 0;
}
/*
"2 + 3"
"12/(3-3)" -> division by 0
['12','+','3','/','5']
    '+'
   /   \
  '12'  '/'
        / \
	   '3' '5'
InOrder: 12 + 3 / 5   infix
PreOrder: + 12 / 3 5  prefix
PostOrder: 12 3 5 / + postfix
*/