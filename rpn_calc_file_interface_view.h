/**
	This is the declarations for the file interface view class.

	@author Shawn Bhagat
	@version 1.0
*/

#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H

//Include standard libraries
#include <string>
#include <fstream>

//Include user-defined header files
#include "rpn_calc_interface_view.h"

//Define class
class FileInterface : public Interface
{
private:
	std::string ifileName;	//input file name
	std::string ofileName;	//output file name
	std::ifstream ifile;	//input file stream
	std::ofstream ofile;	//ouput file stream
public:
	FileInterface(std::string ifileName, std::string ofileName);
	bool openInputFile();						//open file for reading
	bool openOutputFile();						//open file for writing
	virtual bool input(std::string & itext);	//get input from file
	virtual void output(std::string otext);		//send output to file
};

#endif
