//****************************************
// Program Title: Report Card Creator
// Project File: Project_06.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 09/28/18
// Program Description: 
//****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;

int main(int argc, char *argv[])
{

  // Error Message for Insufficient Command Line Arguments
  if (argc != 3)
  {
  cout << endl << "Incorrect number of command line arguments provided.\nThis program requires 2 command line arguments:\nAn input filename and an output filename" << endl << endl;
  cout << "Program usage is:" << endl;
  cout << "./Project_06 InputFileName OutputFileName" << endl << endl;
  return 1; 
  }
    
  // Variables
  string infile = argv[1];
	string outfile = argv[2];
	ifstream Input;
	ofstream Output;
  float quiztotal;
  float hwtotal;
  float examtotal;
  string last;
  string first;
  float score;
  float quizscore;
  float quiznum = 0;
  float hwscore;
  float hwnum = 0;
  float examscore;
  float examnum = 0;
  float keytotal;
  float total;
  float average;
  float numstudents = 0;
  float classaverage = 0;
  
    
  // Opening Input File and Error Message 
  Input.open(infile.c_str());
  cout << endl << "Opening Input File: " << infile << endl;
  while(Input.fail()) 
	{ 
	cout << endl << string(15,'*') << " File Open Error "  
	     << string(15,'*') << endl; 
	cout << "==> Input file failed to open properly!!\n"; 
	cout << "==> Attempted to open file: " << infile << endl; 
	cout << "==> Please try again...\n"; 
	cout << string(47,'*') << endl << endl; 
  infile.clear();
	cout << "Enter the name of the input file: ";
  cin >> infile;
  cout << infile << endl;
  Input.open(infile.c_str());
	}
 
 
  // Opening Output File and Error Message
  Output.open(outfile.c_str());
  cout << endl << "Opening Output File: " << outfile << endl << endl;
  while(Output.fail()) 
	{ 
	cout << string(15,'*') << " File Open Error "  
	     << string(15,'*') << endl; 
	cout << "==> Output file failed to open properly!!\n"; 
	cout << "==> Attempted to open file: " << outfile << endl; 
	cout << "==> Please try again...\n"; 
	cout << string(47,'*') << endl << endl; 
  outfile.clear();
	cout << "Enter the name of the output file: ";
  cin >> outfile;
  cout << outfile << endl << endl;
  Output.open(outfile.c_str());
	}
  
  
  // Reading Amount of Scores
  Input >> quiztotal >> hwtotal >> examtotal;
  
  
  // Error Messages for Empty Input File
  if (Input.fail())
  {
  cout << string(13,'*') << " Input File Is Empty " << string(13, '*') << endl;
  cout << "==> The input file is empty." << endl;
  cout << "==> Terminating the program." << endl;
  cout << string(47,'*') << endl << endl;
  Output << "Input file " << infile << " is empty." << endl;
  return 1;
  }
  
  
  // Header Lines for Output File
  Output << left << setw(3) << "#" << setw(12) << "Last" << setw(7) << "First"<< setw(6) << "Quiz" << setw(6) << "HW" << setw(6) << "Exam" << setw(7) << "Total" << setw(9) << "Average" << endl; 
  
  Output << left << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----"<< setw(6) << "----" << setw(6) << "---" << setw(6) << "----" << setw(7) << "-----" << setw(9) << "-------" << endl; 
   
   
  // Reading for Key
  Input >> last >> first;
  
  while (quiznum < quiztotal)
  {
  Input >> score;
  quizscore+=score;
  quiznum++;
  }
  while (hwnum < hwtotal)
  {
  Input >> score;
  hwscore+=score;
  hwnum++;
  }
  while (examnum < examtotal)
  {
  Input >> score;
  examscore+=score;
  examnum++;
  }
  
  
  // Total and Average for Key
  keytotal = quizscore+hwscore+examscore;
  average = (keytotal/keytotal)*100;
  
  
  // Outputting Key
  Output << left << setw(3) << " " << setw(12) << last << setw(7) << first << setw(6) << quizscore << setw(6) << hwscore << setw(6) << examscore << setw(7) << keytotal << setw(9) << setprecision(2) << fixed << average << endl;
  
  Output << left << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----"<< setw(6) << "----" << setw(6) << "---" << setw(6) << "----" << setw(7) << "-----" << setw(9) << "-------" << endl; 
  
  
  // Resetting Scores and Counters to 0
  quiznum = 0;
  quizscore = 0;
  hwnum = 0;
  hwscore = 0;
  examnum = 0;
  examscore = 0; 
  
  
  // Starting Loop to Read Student Information
  while (Input.good())
  {
   Input >> last >> first;
   
   
   // Fail Message for No Names and End of Output with Class Average
   if (Input.fail() && numstudents == 0)
   {
   cout << "Input file did not contain any students" << endl;
   Output << "Input file did not contain any students" << endl;
   return 1;
   }
   else if (Input.fail() && Input.eof())
   {
   Output << left << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----"<< setw(6) << "----" << setw(6) << "---" << setw(6) << "----" << setw(7) << "-----" << setw(9) << "-------" << endl;
   classaverage/=numstudents;
   Output << endl << "Class Average = " << classaverage << endl;
   return 1;
   }
   
   
   // Student Counter
   numstudents++;
   
   
   //Loops for Grades
   while (quiznum < quiztotal)
   {
   Input >> score;
   quizscore+=score;
   quiznum++;
   }
   while (hwnum < hwtotal)
   {
   Input >> score;
   hwscore+=score;
   hwnum++;
   }
   while (examnum < examtotal)
   {
   Input >> score;
   examscore+=score;
   examnum++;
   }
   
   
   // Total and Average Calculations
   total = quizscore+hwscore+examscore;
   average = (total/keytotal)*100;
   
   
   // Updating Class Average
   classaverage+=average;
   
   
   // Outputs
   Output << left << setprecision(0) << noshowpoint << setw(3) << numstudents << setw(12) << last.substr(0,10) << setw(7) << first.substr(0,5) << setw(6) << quizscore << setw(6) << hwscore << setw(6) << examscore << setw(7) << total << setw(9) << setprecision(2) << fixed << average << endl;
  
  
  // Resetting Scores and Counters to 0
  quiznum = 0;
  quizscore = 0;
  hwnum = 0;
  hwscore = 0;
  examnum = 0;
  examscore = 0;
  }
  
  
  return 0;
}
