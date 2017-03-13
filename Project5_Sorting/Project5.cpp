//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  Project4.cpp          ASSIGNMENT #:  4            Grade: _________          *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Micaiah Skolnick                                              *
//*                                                                                                   *
//*   COURSE #:  CSC 36000 11                            DUE DATE:  March 10, 2017                    *
//*                                                                                                   *
//*****************************************************************************************************
//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS:  One algebraic expression is read in as a series of characters. Each character of the  *
//*             expression is then converted to an item and pushed onto a stack for that expression.  *
//*             each item contains properties such as whether it is an operator or operand, and if it *
//*             is an operator, the priority of the oprator. The read infix expression is then        *
//*             converted to its equal postfix expression. Throughout the conversion process, a log   *
//*             is printed.                                                                           *
//*             After conversion, the postfix expression is evaluated, and the answer is printed.     *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     : Footer - Prints a footer to signify end of program output                        *
//*                  Header - Prints a header to signify start of program output                      *
//*                  newPage - Inserts blank lines until the start of a new page                      *
//*                  invertStack - Inverts the direction of a stack                                   *
//*                  getLine - Reads in one line with one expression from the input file              *
//*                  printStack - Prints each of the values in a stack                                *
//*                  printResults - Prints the original infix expression with the final answer        *
//*                  printTitleConversion - Prints the conversion section title                       *
//*                  printTitleEvaluation - Prints the evaluation section title                       *
//*                  printAllStack - Prints infix and post fix expressions along with opstack         *
//*                  printPostandOpStack - Prints the post fix expression and the opstack             *
//*                  convertInfixToPostfix - Converts an infix expression to its corresponding postfix*
//*                  evaluatePostfix - Evaluates a postfix expression, and returns the answer         *
//*                  main - Variables are declared, functions are called, and headers are printed     *
//*                                                                                                   *
//*****************************************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <locale>
#include <string>
#include <sstream>
using namespace std;
int lineCount = 0; // Declare and initialize a line counter
				   //*************************************  FUNCTION HEADER  *********************************************
void Header(ofstream &Outfile)
{       // Receives � the output file
		// Task - Prints the output preamble
		// Returns - Nothing
	Outfile << setw(30) << "Micaiah Skolnick ";
	Outfile << setw(17) << "CSC 36000";
	Outfile << setw(15) << "Section 11" << endl;
	Outfile << setw(27) << "Spring 2017";
	Outfile << setw(30) << "Assignment #4" << endl;
	Outfile << setw(35) << "---------------------------------- - ";
	Outfile << setw(35) << "---------------------------------- - " << endl << endl;
	lineCount += 4; // Increment the line count
	return;
}
//************************************* END OF FUNCTION HEADER  ***************************************
//*************************************  FUNCTION FOOTER  *********************************************
void Footer(ofstream &Outfile)
{
	// Receives � the output file
	// Task - Prints the output salutation
	// Returns - Nothing
	Outfile << endl;
	Outfile << setw(35) << "-------------------------------- - " << endl;
	Outfile << setw(35) << " | END OF PROGRAM OUTPUT | " << endl;
	Outfile << setw(35) << "-------------------------------- - " << endl;
	lineCount += 4; // Increment the line counter
	return;
}
//************************************* END OF FUNCTION FOOTER  ***************************************
void newPage(ofstream&dataOUT) {
	// Receives � the output file
	// Task - Skip to the top of the next page
	// Returns - Nothing
	// Insert lines until the end of the page is reached
	int MAXPAGELINES = 50;
	while (lineCount < MAXPAGELINES) {
		dataOUT << endl;
		lineCount++;
	}
	// Reset line counter to 0
	lineCount = 0;
}
//*****************************************************************************************************
struct recordType {
		// The structure "recordType" holds each record of the record list
	int iNum, quantity, reoNum;
	string iDes;
	float cost, price;
};
//*****************************************************************************************************
int getData(ifstream&dataIN, recordType recordList[]) {
		// Receives � The input file and the infixExp
		// Task - Read in a line of data.
		// Returns - A stack filled with one line of data, and true/false for successful operation
		// Declare local variables
	int iNum = 0, quantity = 0, reoNum = 0, i = 0;
	char description[26];
	float cost = 0, price = 0;
	dataIN >> ws >> iNum; // Read in first inventory number
	while (iNum > 0){

		dataIN.get(description, 20);
		//dataIN >> ws >> quantity >> reoNum >> cost >> price;
		dataIN >> ws >> quantity >> reoNum >> cost >> price;

		recordList[i].iNum = iNum;
		recordList[i].iDes = string(description);
		recordList[i].quantity = quantity;
		recordList[i].reoNum = reoNum;
		recordList[i].cost = cost;
		recordList[i].price = price;

		i++; // Increment the inventory count
		dataIN >> ws >> iNum;
	}
	return i;
}
//*****************************************************************************************************
void printList(ofstream&dataOUT, recordType recordList[]) {
	// Receives � The output file and the record list
	// Task - Print each record 
	// Returns - Nothing
	// Declare local variables

}
//*****************************************************************************************************
void printTitleConversion(ofstream&dataOUT) {
		// Receives � The output file
		// Task - Print data titles for conversion display
		// Returns - Nothing	
	dataOUT << setw(50) << "CONVERSION DISPLAY" << endl;
	dataOUT << "Infix Expression" << setw(28) << "POSTFIX Expression" << setw(28) << "Stack Contents";
	dataOUT << endl << setw(73) << "(Top to Bottom)" << endl;
	lineCount += 3; // increment the line counter
}
//*****************************************************************************************************
void printTitleEvaluation(ofstream&dataOUT) {
		// Receives � The output file
		// Task - Print data titles for evaluation display
		// Returns - Nothing	
	dataOUT << setw(50) << "Evaluation DISPLAY" << endl;
	dataOUT << setw(28) << "POSTFIX Expression" << setw(38) << "Stack Contents";
	dataOUT << endl << setw(67) << "(Top to Bottom)" << endl;
	lineCount += 3; // Increment the line counter
}
//*****************************************************************************************************
int main() {
		// Receives � Nothing
		// Task - Call each necessary function of the program in order
		// Returns - Nothing
		// Declare variables used in program.
	ifstream dataIN("data_in.txt");  // Open the file containing data.
	ofstream dataOUT("dataOUT.docx");  // Create and open the file to write data to.	
	Header(dataOUT); // Print data header.
	recordType recordList[50];
	int recordCount = 0;
	recordCount = getData(dataIN, recordList);
	printList(dataOUT, recordList);


	Footer(dataOUT); // Print footer. 
	dataIN.close(); // Close input data file. 
	dataOUT.close(); // Close output data file.
	return 0;
}
//*****************************************************************************************************