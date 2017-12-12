/**
	This is the implmentation for the file interface view class.

	@author Shawn Bhagat
	@version 1.0
*/

//Include standard libraries
#include <iostream>
#include <fstream>

//Include user-defined header files
#include "rpn_calc_file_interface_view.h"

/**
	FileInterface(std::string ifileName, std::string ofileName)
	
	Class constructor. Initializes input and output file names needed
	for file i/o operations.

	@param	<std::string> ifileName: Input file name.
	@param	<std::string> ofileName: Output file name.
*/
FileInterface::FileInterface(std::string ifileName, std::string ofileName)
{
	this->ifileName = ifileName;
	this->ofileName = ofileName;
}

/**
	openInputFile()
	
	Open input file for reading. Also outputs user input to output
	file so user input is shown alongside corresponding output.

	@return	<void>
*/
bool FileInterface::openInputFile()
{
	 ifile.open(this->ifileName, std::ios::in);

	 if (!ifile.is_open())
	 {
		 return (false);
	 }

	 return (true);
}

/**
	openOutputFile()
	
	Open output file for writing.

	@return	<void>
*/
bool FileInterface::openOutputFile()
{
	ofile.open(this->ofileName, std::ios::out | std::ios::app);

	if (!ofile.is_open())
	{
		return (false);
	}

	return (true);
}

/**
	input(std::string & itext)
	
	Gets user input from input file.

	@param	<std::string &> itext: Reference to user input from file.
	@return	<void>
*/
bool FileInterface::input(std::string & itext)
{
	std::getline(ifile, itext);

	if (ifile.eof() && itext.empty())
	{
		ifile.close();
		return (false);
	}

	//Write input to output file so user can see commands written
	output(itext + "\n");

	return (true);
}

/**
	output(std::string otext)
	
	Displays user input to output file.

	@param	<std::string> otext: String to be displayed in file.
	@return	<void>
*/
void FileInterface::output(std::string otext)
{
	if (ofile.eof())
	{
		ofile.close();
	}
	else
	{
		ofile << otext;
	}
}