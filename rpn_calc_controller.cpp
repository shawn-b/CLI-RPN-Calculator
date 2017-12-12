/**
	This is the implmentation for the calculator controller class.
	
	@author Shawn Bhagat
	@version 1.0
*/

//Include user-defined header files
#include "rpn_calc_controller.h"
#include "rpn_calc_interface_view.h"
#include "rpn_calc_cli_interface_view.h"
#include "rpn_calc_file_interface_view.h"

/**
	RpnCalcController()

	This is the class constructor. It receives a reference to an
	Interface class so that it can also display messages.

	@param	<Interface *> calcInt: A Calculator Interface reference.
*/
RpnCalcController::RpnCalcController()
{
	//initialize parameters here
}

/**
	evaluateRawInput(std::string rawInput)

	Cleans, parses, and evaluates user input. Also checks to make sure
	it is a legal input, with exception handling to help.

	@param	<std::string> rawInput: The raw input from the user.
	@return	<std::string> The most recent calculation/input result or
	error message.
*/
std::string RpnCalcController::evaluateRawInput(std::string rawInput)
{
	//Termination case: empty input string
	if (rawInput.empty())
	{
		return (getPreviousResult());
	}

	//Create try/catch blocks for exception handling
	try
	{
		//Clean up leading whitespace in raw input
		rawInput = trimInvalidInput(rawInput);

		//Get next entity in trimmed input
		std::string entity = getNextEntity(rawInput);

		//Check to see if entity is a valid number
		if (isNumber(entity))
		{
			double entityAsDouble = convertStringToDouble(entity);
			storeEntity(entityAsDouble);
		}
		//Check to see if entity is a valid operator
		else if (isOperator(entity))
		{
			calculatePrevEntities(entity[0]);
		}
		//Check to see if entity is EOT/EOF value
		else if (isEndOfTransmissionValue(entity))
		{
			throw USER_CMD_QUIT;
		}
		else
		{
			//Give appropriate error message if an invalid input
			throw "Invalid input detected.";
		}
	}
	catch (const char * exception)
	{
		return (exception);
	}
	
	//Prepare rawInput for next recursive iteration
	deleteCurrentEntity(rawInput);

	//Call recursively until termination
	return (evaluateRawInput(rawInput));
}

/**
	isEndOfTransmissionValue(std::string data)

	Checks to see if user entered end of transmission or end of 
	file character.

	@param	<std::string> data: User input.
	@return	<bool> True if EOT/EOF char, false if not.
*/
bool RpnCalcController::isEndOfTransmissionValue(std::string data)
{
	if ((data.size() == 1) && (data[0] == (char)END_OF_TRANSMISSION_NUM))
	{
		return (true);
	}

	return (false);
}

/**
	evaluateUserCommand(std::string data)
	
	Checks user input for valid application commands. If found,
	perform appropriate action.

	@param	<std::string> data: User input.
	@return	<void>
*/
std::string RpnCalcController::evaluateUserCommand(std::string data)
{
	try
	{
		if (data.compare(USER_CMD_QUIT) == 0)
		{
			//Terminate application
			return (USER_CMD_QUIT);
		}
		else if (data.compare(USER_CMD_HISTORY) == 0)
		{
			//Return current calculation history
			return (getCurrentHistory());
		}
		else if (data.compare(USER_CMD_CLEAR_HISTORY) == 0)
		{
			//Clear current calculation history
			clearCurrentHistory();
			return ("Calculation history cleared.");
		}
		else
		{
			return ("");
		}
	}
	catch (const char * exception)
	{
		return (exception);
	}
}

/**
	getCurrentHistory()
	
	Gets all values in current calculation.

	@return	<std::string> All values in calculation concatenated together.
*/
std::string RpnCalcController::getCurrentHistory()
{
	return (calcStack.getStackAsString());
}

/**
	clearCurrentHistory()
	
	Clears all values in current calculation.

	@return	<void>
*/
void RpnCalcController::clearCurrentHistory()
{
	calcStack.clearStack();
}

/**
	getPreviousResult()
	
	Returns the most recent valid calculation result.

	@return	<std::string> The calculation result.
*/
std::string RpnCalcController::getPreviousResult()
{
	std::string result = "";

	//Get most recent value that has been stored
	try
	{
		result = std::to_string(calcStack.peek());
	}
	catch (const char * exception)
	{
		return (exception);
	}

	//Return result if no errors caught
	return (result);
}

/**
	getNextEntity(std::string data)
	
	Parses and gets the first whitespace-delimited string from the
	original string.

	@param	<std::string> data: A string of characters.
	@return	<std::string> The first substring of of the whole string.
*/
std::string RpnCalcController::getNextEntity(std::string data)
{
	int whitespaceLoc = 0;

	whitespaceLoc = data.find(' ');
	whitespaceLoc = (whitespaceLoc == std::string::npos ? data.find('\t') : whitespaceLoc);
	whitespaceLoc = (whitespaceLoc == std::string::npos ? data.find('\n') : whitespaceLoc);

	return (data.substr(0, whitespaceLoc));
}

/**
	deleteCurrentEntity(std::string & data)
	
	Parses and deletes the first whitespace-delimited string from the
	original string.

	@param	<std::string> data: A string of characters.
	@return	<void>
*/
void RpnCalcController::deleteCurrentEntity(std::string & data)
{
	int whitespaceLoc = 0;

	whitespaceLoc = data.find(' ');
	whitespaceLoc = (whitespaceLoc == std::string::npos ? data.find('\t') : whitespaceLoc);
	whitespaceLoc = (whitespaceLoc == std::string::npos ? data.find('\n') : whitespaceLoc);

	data.erase(0, whitespaceLoc);
}

/**
	trimInvalidInput(std::string data)
	
	Trims the leading and trailing whitespace from a string.

	@param	<std::string> data: An un-trimmed string.
	@return	<std::string> A trimmed string.
*/
std::string RpnCalcController::trimInvalidInput(std::string data)
{
	//Valid input characters
	std::string digits = VALID_USER_INPUT_DIGITS;
	std::string operators = VALID_USER_INPUT_OPERATORS;

	//Find location of first valid character
	int validFirstCharLoc = data.find_first_of(digits + operators);

	//Delete all non-valid chars up to valid char
	if (validFirstCharLoc != std::string::npos)
	{
		data.erase(0, validFirstCharLoc);
	}

	//Find location of last valid character
	int validLastCharLoc = data.find_last_of(digits + operators);

	//Delete all non-valid chars from last valid char to end of string
	if ((validLastCharLoc != std::string::npos) && (validLastCharLoc < (data.size() - 1)))
	{
		data.erase(validLastCharLoc + 1, data.size() - 1 - validLastCharLoc);
	}

	//Return string with trimmed leading whitespace
	return data;
}

/**
	isNumber(std::string entity)
	
	Checks whether or not a string is a valid number. Allows negative
	numbers and fractional values.

	@param	<std::string> entity: A string of characters.
	@return	<bool> True if the string is a number, and false if not.
*/
bool RpnCalcController::isNumber(std::string entity)
{
	//Checks for valid, non-digit characters
	int decimalPointCount = 0;
	int validDigitCount = 0;

	//Iterate through string, char by char
	for (int i = 0; i < entity.size(); i++)
	{
		//Identify non-numeric digits (not 0-9)
		if (!isdigit(entity[i]))
		{
			//Case: negative sign can only be first char
			if (!(i == 0 && entity[i] == '-'))
			{
				//Case: only one negative sign can exist	
				if (i > 0 && entity[i] == '-')
				{
					return (false);
				}
				//Case: only one decimal point can exist
				else if (entity[i] == '.')
				{
					decimalPointCount++;

					if (decimalPointCount > 1)
					{
						return (false);
					}
				}
				//All other character cases
				else
				{
					return (false);
				}	
			}			
		}
		else
		{
			validDigitCount++;
		}
	}

	//Checks to see if final number has at least 1 valid numberic digit
	if (validDigitCount < 1)
	{
		return (false);	//catches special case of single '-' operator entity
	}
	else
	{
		return (true);
	}
}

/**
	isOperator(std::string entity)
	
	Checks whether or not a string is a valid arithmetic operator.

	@param	<std::string> entity: A string of characters.
	@return	<bool> True if the string is an operator, and false if not.
*/
bool RpnCalcController::isOperator(std::string entity)
{
	//Return 'true' if entity matches a valid operator
	if ((entity.compare(MATH_OP_ADD) == 0) ||
		(entity.compare(MATH_OP_SUB) == 0) ||
		(entity.compare(MATH_OP_MULT) == 0) ||
		(entity.compare(MATH_OP_DIV) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}

}

/**
	isUserCommand(std::string entity)
	
	Checks whether or not a string is a valid user command.

	@param	<std::string> entity: A string of characters.
	@return	<bool> True if the string is a command, and false if not.
*/
bool RpnCalcController::isUserCommand(std::string entity)
{
	//Return 'true' if entity matches a valid command
	if ((entity.compare(USER_CMD_QUIT) == 0) ||
		(entity.compare(USER_CMD_HISTORY) == 0) ||
		(entity.compare(USER_CMD_CLEAR_HISTORY) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
	convertStringToDouble(std::string entity)
	
	Converts a string to a double value.

	@param	<std::string> entity: A string of characters.
	@return	<double> The string as a double value.
*/
double RpnCalcController::convertStringToDouble(std::string entity)
{
	return (atof(entity.c_str()));
}

/**
	storeEntity(double entity)
	
	Stores the operand in a data structure for later use.

	@param	<double> entity: A double number to be stored.
	@return	<void>
*/
void RpnCalcController::storeEntity(double entity)
{
	calcStack.push(entity);
}

/**
	calculatePrevEntities(char op)
	
	Performs the appropriate arithmetic operation on two operands,
	given an operator.

	@param	<char> op: Mathematical operator that determines operation to be done.
	@return	<void>
*/
void RpnCalcController::calculatePrevEntities(char op)
{
	double op1 = 0;
	double op2 = 0;

	op2 = calcStack.peek();
	calcStack.pop();
	op1 = calcStack.peek();
	calcStack.pop();

	switch (op)
	{
	case MATH_OP_ADD[0]:
		calcStack.push(calc.add(op1, op2));
		break;
	case MATH_OP_SUB[0]:
		calcStack.push(calc.subtract(op1, op2));
		break;
	case MATH_OP_MULT[0]:
		calcStack.push(calc.multiply(op1, op2));
		break;
	case MATH_OP_DIV[0]:
		calcStack.push(calc.divide(op1, op2));
		break;
	default:
		break;
	}
}