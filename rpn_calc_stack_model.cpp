/**
	This is the implmentation for the stack model class.

	@author Shawn Bhagat
	@version 1.0
*/

//Include user-defined header files
#include "rpn_calc_stack_model.h"

/**
	Stack()
	
	Class constructor. Initializes any class properties here.
*/
Stack::Stack()
{
}

/**
	push(double value)
	
	Pushes a numeric value onto the stack.

	@param	<double> value: Value to be added to stack.
	@return	<void>
*/
void Stack::push(double value)
{
	myStack.push_back(value);
}

/**
	pop()
	
	Pops a numeric value off of the stack. Throws exception if 
	stack is empty.

	@return	<void>
*/
void Stack::pop()
{
	if (isEmpty())
	{
		throw "No values currently stored.";
	}
	else
	{
		myStack.pop_back();
	}
}

/**
	peek()
	
	Returns the value on the top of the stack. Throws exception if 
	stack is empty.

	@return	<double> Top value of stack.
*/
double Stack::peek()
{
	if (isEmpty())
	{
		throw "No values currently stored.";
	}
	else
	{
		return myStack.back();
	}
}

/**
	isEmpty()
	
	Checks whether or not the stack is empty.

	@return	<bool> True if stack is empty, false if not.
*/
bool Stack::isEmpty()
{
	return (myStack.empty());
}

/**
	clearStack()
	
	Clears the stack of all values.

	@return	<void>
*/
void Stack::clearStack()
{
	if (!isEmpty())
	{
		myStack.clear();
	}
}

/**
	getStackAsString()
	
	Returns stack as a string of values.

	@return	<std::string> Formatted stack string.
*/
std::string Stack::getStackAsString()
{
	if (isEmpty())
	{
		throw "No values currently stored.";
	}
	else
	{
		std::string stackString = "";

		for (int i = 0; i < myStack.size(); i++)
		{
			stackString.append("[" + std::to_string(myStack[i]) + "] ");
		}

		return (stackString);
	}
}