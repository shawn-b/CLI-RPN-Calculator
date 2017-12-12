/**
	This is a Reverse Polish Notation calculator application. It supports multiple
	interfaces such as command-line and file, which can be easily extended to other
	interfaces.

	The application runs in an infinite loop until it receives a quit command or EOT
	from the chosen interface. It can always be aborted with CTRL+C.

	@author Shawn Bhagat
	@version 1.0
*/

//Include standard libraries
#include <iostream>
#include <string>

//Include user-defined header files
#include "rpn_calc_interface_view.h"
#include "rpn_calc_cli_interface_view.h"
#include "rpn_calc_file_interface_view.h"
#include "rpn_calc_controller.h"

//Define valid command-line argument parameters
#define COMMAND_LINE_IF_ARG "-c"
#define FILE_IF_ARG "-f"

//Declare user-defined functions
Interface * chooseInterface(int argc, char * argv[]);	//Choose appropriate interface based on command line args

//Main
int main(int argc, char * argv[])
{
	//Used to determine when application should terminate
	bool applicationRunning = true;

	//Create one controller for application
	RpnCalcController calcController;

	//Declare reference to interface
	Interface * appInterface = NULL;

	//Choose appropriate interface
	appInterface = chooseInterface(argc, argv);

	//Do not run application if interface cannot be established
	if (!appInterface)
	{
		applicationRunning = false;
	}

	//Iterate in an infinite loop until explicit user termination
	while (applicationRunning)
	{
		//Temporary variable to store user input
		std::string tempInput;

		//Display user prompt
		appInterface->output("> ");

		//Get user input
		if (!appInterface->input(tempInput))
		{
			//Terminate program if there is no more input detected (i.e. from a file)
			applicationRunning = false;
			continue;
		}
	
		//Temporary variable used in following code
		std::string result;

		//Check user input for special valid commands
		if (calcController.isUserCommand(tempInput))
		{
			result = calcController.evaluateUserCommand(tempInput);
		}
		//Otherwise evaluate user input as a calculation
		else
		{
			result = calcController.evaluateRawInput(tempInput);
		}

		//Terminate program if an 'EXIT' code is returned
		if (result.compare(USER_CMD_QUIT) == 0)
		{
			applicationRunning = false;
		}
		//Otherwise display calculation/error result
		else
		{
			appInterface->output(result + "\n");
		}
	}

	//Exit calculator application
	return (0);
}

//Define user-defined functions

/**
	chooseInterface(int argc, char * argv[])

	Returns appropriate Interface reference depending on command line
	arguments specified by user.

	@param	<int> argc: Number of command-line arguments.
	@param	<char * []> argv: Values of command-line arguments.
	@return	<Interface *> Interface to be used for program input/output.
*/
Interface * chooseInterface(int argc, char * argv[])
{
	//There has to be at least one argument specifying interface, otherwise exit
	if (argc < 2)
	{
		return (NULL);
	}
	else
	{
		//Check first argument, which should be a valid command
		std::string arg = argv[1];

		//'c' => choose command-line implementation
		if (arg.compare(COMMAND_LINE_IF_ARG) == 0)
		{
			return (new CliInterface);
		}
		//'f' => choose file implementation
		else if (arg.compare(FILE_IF_ARG) == 0)
		{
			//Needs command and two file names
			if (argc != 4)
			{
				return (NULL);
			}
			else
			{
				//Get input and output file names
				std::string inputFileName = argv[2];
				std::string outputFileName = argv[3];

				//Create file interface object
				FileInterface * fInterface = new FileInterface(inputFileName, outputFileName);

				//Open both input and output files
				bool ifileOpen = fInterface->openInputFile();
				bool ofileOpen = fInterface->openOutputFile();

				//If both files opened properly, return reference to file interface
				if (ifileOpen && ofileOpen)
				{
					return (fInterface);
				}
				else
				{
					return (NULL);
				}
			}
		}
		else
		{
			return (NULL);
		}
	}
}