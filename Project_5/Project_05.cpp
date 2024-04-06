//****************************************
// Program Title: Report Card Creator
// Project File: Project_05.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 09/21/18
// Program Description: Inputs information from an external file, manipulates the information,  
// and outputs it to a newly created file given by the user.
//****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;

int main(int argc, char *argv[])
{
	// Variables
	string infile = argv[1];
	string outfile = argv[2];
	ifstream Input;
	ofstream Output;
	string header;
	string firstname;
	string lastname;
	float test1;
	float test2;
	float test3;
	float test4;
	float grade;
	char letter;
	

	// Opening Input File
	Input.open(infile.c_str());
	

	// Copy and Pasted Error Message
	if(Input.fail()) 
	{ 
  cout << endl << "Opening input file: " << infile << endl << endl;
	cout << string(15,'*') << " File Open Error "  
	     << string(15,'*') << endl; 
	cout << "==> Input file failed to open properly!!\n"; 
	cout << "==> Attempted to open file: " << infile << endl; 
	cout << "==> Terminating program!!!\n"; 
	cout << string(47,'*') << endl << endl; 
	   return 1;   
	}

	
	// Opening Output File
	Output.open(outfile.c_str());


	//
	if(Output.fail()) 
	{ 
  cout << endl << "Opening input file: " << infile << endl << endl;
	cout << "Opening output file: " << outfile << endl << endl;
	cout << string(15,'*') << " File Open Error "  
	     << string(15,'*') << endl; 
	cout << "==> Output file failed to open properly!!\n"; 
	cout << "==> Attempted to open file: " << outfile << endl; 
	cout << "==> Terminating program!!!\n"; 
	cout << string(47,'*') << endl << endl; 
	   return 1;   
	}

	
	// Message Showing Successful File Openings
	cout << endl << "Opening input file: " << infile << endl << endl;
	cout << "Opening output file: " << outfile << endl << endl;


	// Inputting and Outputting Header lines
	getline(Input, header, '\n');
	Output << header << endl;
	Output << setw(12) << left << "Last Name" << setw(12) << "First Name" << setw(9)
		<< "Average" << "Letter" << endl;
	Output << setw(12) << left << string(9,'-') << setw(12) << string(10,'-') << setw(9)
		<< string(7,'-') << string(6,'-') << endl;

		
	// Inputting  and Outputting Name
  	getline(Input, firstname, ',');
	firstname= firstname.substr(0,10);
	getline(Input, lastname, ',');
	lastname= lastname.substr(0,9);
	Output << setw(12) << left << lastname;
	Output << setw(12) << left << firstname;
	
	// Inputting Grades and Outputting Calculated Average
	Input >> test1 >> test2 >> test3 >> test4;
	grade = (test1+test2+test3+test4)/4;
	Output << setw(9) << left << setprecision(2) << fixed << grade;

	
	// Determining Grade
	if (grade >= 90)
	{
	letter = 'A';
	Output << letter << endl;
	}
	else if (grade >= 80)
	{
	letter = 'B';
	Output << letter << endl;
	}
	else if (grade >= 70)
	{
	letter = 'C';
	Output << letter << endl;
	}
	else if (grade >= 60)
	{
	letter = 'D';
	Output << letter << endl;
	}
	else
	{
	letter = 'F';
	Output << letter << endl;
	}
	
	
	// Ignoring Extra Lines
	Input.ignore(INT_MAX, '\n');


	// Repeating for Student #2
  	getline(Input, firstname, ',');
	firstname= firstname.substr(0,10);
	getline(Input, lastname, ',');
	lastname= lastname.substr(0,9);
	Output << setw(12) << left << lastname;
	Output << setw(12) << left << firstname;
	Input >> test1 >> test2 >> test3 >> test4;
	grade = (test1+test2+test3+test4)/4;
	Output << setw(9) << left << setprecision(2) << fixed << grade;
	if (grade >= 90)
	{
	letter = 'A';
	Output << letter << endl;
	}
	else if (grade >= 80)
	{
	letter = 'B';
	Output << letter << endl;
	}
	else if (grade >= 70)
	{
	letter = 'C';
	Output << letter << endl;
	}
	else if (grade >= 60)
	{
	letter = 'D';
	Output << letter << endl;
	}
	else
	{
	letter = 'F';
	Output << letter << endl;
	}
	Input.ignore(INT_MAX, '\n');	


	// Repeating for Student #3
  	getline(Input, firstname, ',');
	firstname= firstname.substr(0,10);
	getline(Input, lastname, ',');
	lastname= lastname.substr(0,9);
	Output << setw(12) << left << lastname;
	Output << setw(12) << left << firstname;
	Input >> test1 >> test2 >> test3 >> test4;
	grade = (test1+test2+test3+test4)/4;
	Output << setw(9) << left << setprecision(2) << fixed << grade;
	if (grade >= 90)
	{
	letter = 'A';
	Output << letter << endl;
	}
	else if (grade >= 80)
	{
	letter = 'B';
	Output << letter << endl;
	}
	else if (grade >= 70)
	{
	letter = 'C';
	Output << letter << endl;
	}
	else if (grade >= 60)
	{
	letter = 'D';
	Output << letter << endl;
	}
	else
	{
	letter = 'F';
	Output << letter << endl;
	}
	Input.ignore(INT_MAX, '\n');

	
	//Ending Dashes
	Output << setw(12) << left << string(9,'-') << setw(12) << string(10,'-') << setw(9)
		<< string(7,'-') << string(6,'-') << endl;
		
	

	return 0;
}
