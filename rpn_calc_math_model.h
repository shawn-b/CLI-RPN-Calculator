/**
	This is the declarations for the math model class.

	@author Shawn Bhagat
	@version 1.0
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

//Define class
class Calculator
{
public:
	double add(double operand1, double operand2);		//addition function
	double subtract(double operand1, double operand2);	//subtraction function
	double multiply(double operand1, double operand2);	//multiplication function
	double divide(double operand1, double operand2);	//division function
};

#endif