//****************************************
// Program Title: Character Reader
// Project File: Project_07.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 10/5/18
// Program Description: Reads an input file and outputs how many letters, digits, and
// other characters exist per line and in the entire file.
//****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
#include <cctype>
using namespace std;

int main()
{

 // Variables
 string infile;
 ifstream Input;
 char character;
 float numline = 0;
 float numletters = 0;
 float numdigits = 0;
 float numother = 0;
 float totalline = 0;
 float totalletters = 0;
 float totaldigits = 0;
 float totalother = 0;
 float totalcharacters = 0;
 float percentletters;
 float percentdigits;
 float percentother;

 // Asking for Input
 cout << endl << "Enter in the name of the input file: " << infile;
 cin >> infile;
 cout << infile << endl << endl;


 // Opening Input File
 Input.open(infile.c_str());
 
 
 // Error Message
 while(Input.fail()) 
 	{ 
 	cout << string(15,'*') << " File Open Error "  
  << string(15,'*') << endl; 
 	cout << "==> Input file failed to open properly!!\n"; 
 	cout << "==> Attempted to open file: " << infile << endl; 
 	cout << "==> Please try again...\n"; 
 	cout << string(47,'*') << endl << endl; 
  infile.clear();
 	cout << "Enter in the name of the input file: ";
  cin >> infile;
  cout << infile << endl << endl;
  Input.open(infile.c_str());
 	}
  
  
 // Getting First Character
 Input.get(character);
 
 
 // Error for Empty File
 if (Input.fail())
 {
 cout << string(13,'*') << " Input File Is Empty " << string(13, '*') << endl;
 cout << "==> The input file is empty." << endl;
 cout << "==> Terminating the program." << endl;
 cout << string(47,'*') << endl << endl;
 return 1;
 }
 
 
 // Outer Loop
 while (Input.good())
 {
 
 // Header Output
 if (numline == 0)
 {
 cout << left <<  setw(15) << "Line number" << setw(10) << "Letters" << setw(10)
 << "Digits" << setw(10) << "Other" << setw(10) << "Total" << endl;
 cout << left << setw(15) << string(11,'-') << setw(10) << string(7,'-') << setw(10)
 << string(6,'-') << setw(10) << string(5,'-') << setw(10) << string(5,'-') << endl;
 }
 
   // Inner Loop
   while (character != '\n') 
   {
   
   if (isalpha(character))
   {
   numletters++;
   }
   else if (isdigit(character))
   {
   numdigits++;
   }
   else
   {
   numother++;
   }
   
   Input.get(character);
   }
 
 // Outer Loop Continued
 numother++;
 numline++;
 totalline = numletters + numdigits + numother;
 
 // Output for Each Line
 cout << left <<  setw(15) << numline << setw(10) << numletters << setw(10)
 << numdigits << setw(10) << numother << setw(10) << totalline << endl;
 
 // Adding Information to Totals
 totalletters += numletters;
 totaldigits += numdigits;
 totalother += numother;
 
 // Resetting Counters to Zero
 numletters = 0;
 numdigits = 0;
 numother = 0;
 totalline = 0;
 
 // Getting Next Character
 Input.get(character);
 }
 
 
 // Total Characters Read
 totalcharacters = totalletters + totaldigits + totalother;
 
 
 // Outputting Dashes and Totals
 cout << string(50,'-') << endl;
 cout << left <<  setw(15) << "Totals" << setw(10) << totalletters << setw(10)
 << totaldigits << setw(10) << totalother << setw(10) << totalcharacters << endl;
 
 
 // Calculating Percents
 percentletters = (totalletters/totalcharacters)*100;
 percentdigits = (totaldigits/totalcharacters)*100;
 percentother = (totalother/totalcharacters)*100;
 
 
 // Outputting Percents
 cout << left << fixed << setprecision(2) << setw(15) << "Percent" << setw(10) << percentletters << setw(10) << percentdigits << setw(10) << percentother << endl << endl;
 
 
 return 0;
}
