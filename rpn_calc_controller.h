/**
	This is the declarations for the calculator controller class.

	@author Shawn Bhagat
	@version 1.0
*/

#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

//Include standard libraries
#include <string>
#include <vector>

//Include user-defined header files
#include "rpn_calc_stack_model.h"
#include "rpn_calc_math_model.h"
#include "rpn_calc_interface_view.h"

//Define class
class RpnCalcController
{
private:
	Stack calcStack;	//gives access to stack implementation
	Calculator calc;	//gives acccess to arithmetic functions

	bool isEndOfTransmissionValue(std::string data);	//checks to see if data is EOT char (aka EOF/ctrl-d)
	std::string getPreviousResult();					//return most recent valid operation results
	std::string getNextEntity(std::string data);		//gets next substring in user input
	void deleteCurrentEntity(std::string & data);		//removes current entity from user input
	std::string trimInvalidInput(std::string data);		//trim whitespace from user input
	bool isNumber(std::string entity);					//check if string is a valid number
	bool isOperator(std::string entity);				//check if string is a valid operator
	double convertStringToDouble(std::string entity);	//convert string to double
	void storeEntity(double entity);					//store operand in data structure
	void calculatePrevEntities(char op);				//calculate previous entities based on operator
	std::string getCurrentHistory();					//get current calculation's history as a string of values
	void clearCurrentHistory();							//clear current calculation's history

public:
	RpnCalcController();								//constructor
	std::string evaluateRawInput(std::string data);		//parse and evaluate user input
	std::string evaluateUserCommand(std::string data);	//check user input for valid application commands
	bool isUserCommand(std::string entity);				//check if string is a valid user calc command
};

//End of transmission char; ASCII numeric equivalent
#define END_OF_TRANSMISSION_NUM 4

//Special application user commands
#define USER_CMD_QUIT "q"
#define USER_CMD_HISTORY "h"
#define USER_CMD_CLEAR_HISTORY "c"

//Valid operands and operators to be used for calculations
#define VALID_USER_INPUT_DIGITS ".0123456789"
#define VALID_USER_INPUT_OPERATORS "+-*/"

//All currently implemented mathematical operations
#define MATH_OP_ADD "+"
#define MATH_OP_SUB "-"
#define MATH_OP_MULT "*"
#define MATH_OP_DIV "/"

#endif
