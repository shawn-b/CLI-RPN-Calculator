/**
	This is the declarations for the command-line interface view class.

	@author Shawn Bhagat
	@version 1.0
*/

#ifndef CLI_INTERFACE_H
#define CLI_INTERFACE_H

//Include standard libraries
#include <string>

//Include user-defined header files
#include "rpn_calc_interface_view.h"

//Define class
class CliInterface : public Interface
{
public:
	virtual bool input(std::string & itext);
	virtual void output(std::string otext);
};

#endif
