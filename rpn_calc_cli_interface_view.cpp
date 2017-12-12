/**
	This is the implmentation for the command-line interface view class.

	@author Shawn Bhagat
	@version 1.0
*/

//Include standard libraries
#include <iostream>

//Include user-defined header files
#include "rpn_calc_cli_interface_view.h"

/**
	input(std::string & itext)
	
	Gets user input from command line.

	@param	<std::string &> itext: Reference to user input from command line.
	@return	<void>
*/
bool CliInterface::input(std::string & itext)
{
	std::getline(std::cin, itext);
	return (true);
}

/**
	output(std::string otext)
	
	Displays user input to command line.

	@param	<std::string> otext: String to be displayed on command line.
	@return	<void>
*/
void CliInterface::output(std::string otext)
{
	std::cout << otext;
}