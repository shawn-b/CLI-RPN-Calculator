# CLI RPN Calculator

## How to Run & Use Application

### NAME

CliRpnCalculator.exe \- runs RPN calculator

### SYNOPSIS

CliRpnCalculator.exe \[OPTION\]

CliRpnCalculator.exe \[OPTION\] \[FILE\] \[FILE\]

### OPTIONS

\-c  
* Calculator will run in command-line mode.

\-f \[input_file_name\] \[output_file_name\]  
* Calculator will run in file mode. One input file needs to be specified followed by one output file.  
* In the input file, put each distinct command on a new line. Each input command and corresponding output will be displayed in output file.  
* By default, program will look for the input file in the current directory, unless the complete path is specified.  
* By default, program will create the output file in the current directory, unless the complete path is specified.

### DESCRIPTION

User commands once program is running:  
* **'q'** terminates program  
* **'h'** displays all values in current calculation history  
* **'c'** clears all values in current calculation history  
* **'CTRL+D'** terminates program

*Note: For the command-line interface, press ENTER after inputting the above commands.*

Exit status:  
* 0 if OK

### AUTHOR

Written by Shawn Bhagat.