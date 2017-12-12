# CLI RPN Calculator

## I. Design Description

This application is a calculator that implements the four basic arithmetic operations: addition, subtraction, multiplication, and division. It utilizes Reverse Polish Notation in its implementation, so the operands are inputted before the operator. The program currently supports command-line and file interfaces to handle application input and output.

## II. Technical & Architectural Choices

The program architecture follows a Model-View-Controller Object-Oriented architecture to separate the various functionalities of the program.

#### Model: This is the underlying data structures and mathematical implementations for this application.

*Data structure:* A stack class is used for the natural implementation of the RPN calculations, but it can also be implemented using a linked list, array, etc.

*Mathematics:* A calculator class is used to define all of the different arithmetic operations.

#### View: This is the user interface, with its implementation selected by the user upon application execution.

*Interface:* A general interface is used to dictate the input/output operations for the application. This is further specified so that the user can easily switch between a command-line or file implementation.

#### Controller: This handles the data flow between the user interface and the back-end models code.

*Features:*

* Recursively evaluates each distinct value in the user input to handle errors more cleanly.
* Returns either the last valid result, the result of a valid command, or an error message.
* Detects and/or cleans invalid characters and whitespace from user input.
* Checks for valid user commands.
		
## III. Trade-Offs

* Recursion is used in place of while loop to simplify exception handling.

## IV. Non-Included Features

* WebSocket/TCP Socket interfaces are not implemented.

## V. Future Changes & Improvements

* Improvements will be based on the requirement of additional features like more mathematical operations or interfaces (WebSocket, TCP Socket).

## VI. Link to Application

https://github.com/shawn-b/CLI-RPN-Calculator

*Note: CliRpnCalculator.exe is included in the repository and can be run on a Windows 10 computer.*