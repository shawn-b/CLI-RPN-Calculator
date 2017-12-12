/**
	This is the declarations for the interface view class.

	@author Shawn Bhagat
	@version 1.0
*/

#ifndef INTERFACE_H
#define INTERFACE_H

//Include standard libraries
#include <string>

//Define class
class Interface
{
public:
	//'input' & 'output' methods must be implemented in all derivative classes
	virtual bool input(std::string & itext) = 0;
	virtual void output(std::string otext) = 0;
};

#endif
