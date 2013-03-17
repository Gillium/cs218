#include "queue.h"
#include "stack.h"
#include "arithmeticExpressionTree.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{	
	string expression;

	char command = 'M';

	cout << "This program will take an infix expression and put it into an arithmetic" << endl;
	cout << "expression tree. It will display a diagram of the tree, evaluate the expression,and gives the infix, prefix, and postfix notations of the expression.";
	cout << endl << endl;

	while(command != 'Q' || command != 'q')
	{
		if(command == 'M')
		{
			cout << "What would you like to do?" << endl;
			cout << "<E>nter an expression" << endl;
			cout << "<Q>uit the program" << endl;
			cout << "?";
			cin  >> command;
			cout << endl << endl; 
		}
		else if (command == 'Q' || command == 'q')
		{
			break;
		}
		else if (command == 'E' || command == 'e')
		{
			cout << "You can use operators such as + , - , * , / , % , ( , and ) ." << endl;
			cout << "Example: (3 + 1) / 2" << endl;
			cout << "Please enter expression." << endl;
			cin.ignore();
			getline(cin, expression);

			try
			{
				ArithmeticExpressionTree aet = ArithmeticExpressionTree(expression);
				double value = aet.Evaluate();
				cout << endl;
				aet.Print(cout);
				cout << endl << "The value of the expression is: " << value << endl;
				cout << "Infix: " << aet.GetExpression(INFIX) << endl;
				cout << "Prefix: " << aet.GetExpression(PREFIX) << endl;
				cout << "Postfix: " << aet.GetExpression(POSTFIX) << endl;
				cout << endl;
			}
			catch(Unbalanced)
			{
				cout << "Expression is unbalanced!" << endl;
			}
			catch(InvalidCharacter)
			{
				cout << "Expression has an invalid character!" << endl;
			}
			catch(DivisionByZero)
			{
				cout << "Cannot evaluate division by zero!" << endl;
			}
			catch(...)
			{
				cout << "Expression is invalid!" << endl;
			}

			command = 'M';
		}
		else
		{
			cout << "You entered an invalid command!" << endl << endl;
			command = 'M';
		}
	}

	system("Pause");
	return 0;
}