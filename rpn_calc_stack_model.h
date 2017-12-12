/**
	This is the declarations for the stack model class.

	@author Shawn Bhagat
	@version 1.0
*/

#ifndef STACK_H
#define STACK_H

//Include standard libraries
#include <vector>
#include <string>

//Define class
class Stack
{
private:
	std::vector<double> myStack;	//stack implemented as a vector

public:
	Stack();					//constructor
	void push(double value);	//add value to stack
	void pop();					//remove top value from stack
	double peek();				//get top value from stack
	bool isEmpty();				//check if stack is empty
	void clearStack();			//clear stack of all values
	std::string getStackAsString();	//gets all values in stack
};

#endif