/**
	This is the implmentation for the math model class.

	@author Shawn Bhagat
	@version 1.0
*/

//Include user-defined header files
#include "rpn_calc_math_model.h"

/**
	add(double operand1, double operand2)
	
	Adds two operands and returns the result.

	@param	<double> operand1: First operand.
	@param	<double> operand2: Second operand.
	@return	<double> Sum of operands.
*/
double Calculator::add(double operand1, double operand2)
{
	return (operand1 + operand2);
}

/**
	subtract(double operand1, double operand2)
	
	Subtracts two operands and returns the result.

	@param	<double> operand1: First operand.
	@param	<double> operand2: Second operand.
	@return	<double> Difference between first and second operands.
*/
double Calculator::subtract(double operand1, double operand2)
{
	return (operand1 - operand2);
}

/**
	multiply(double operand1, double operand2)
	
	Multiplies two operands and returns the result.

	@param	<double> operand1: First operand.
	@param	<double> operand2: Second operand.
	@return	<double> Product of operands.
*/
double Calculator::multiply(double operand1, double operand2)
{
	return (operand1 * operand2);
}

/**
	divide(double operand1, double operand2)
	
	Divides two operands and returns the result. Throws exception
	if it tries to divide by zero.

	@param	<double> operand1: First operand.
	@param	<double> operand2: Second operand.
	@return	<double> Quotient between first and second of operands.
*/
double Calculator::divide(double operand1, double operand2)
{
	if (operand2 == 0)
	{
		throw "Cannot divide by zero.";
	}
	else
	{
		return (operand1 / operand2);
	}
}