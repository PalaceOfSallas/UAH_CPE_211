//****************************************
// Program Title: Extra Credit
// Project File: Project_12.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 11/30/18
// Program Description:
// 
//****************************************
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  // Variables
  ifstream Input;
  string inputfile;
  string calc;
  string op;
  double num1, num2;
  string dr;
  double angle;
  float pi = 3.14159265;
  
  // Asking for Input and Attempting to Open
  cout << endl << "Enter the name of the input file: ";
  cin >> inputfile;
  cout << inputfile << endl << endl;
  Input.open(inputfile.c_str());
  
  // File Open Error
  while (Input.fail())
  {
    cout << "*************** File Open Error ***************" << endl;
    cout << "==>  Input file could not be opened." << endl;
    cout << "==>  " << inputfile << " is an invalid file!!" << endl;
    cout << "==>  Please try again." << endl;
    cout << "***********************************************" << endl << endl;
    Input.clear();
    cout << "Enter the name of the input file: ";
    cin >> inputfile;
    cout << inputfile << endl << endl;
    Input.open(inputfile.c_str());
  }
  
  // Priming Read
  Input >> calc;
  
  // Error for Empty File
  if (Input.eof())
  {
    cout << "*************** Empty Input File **************" << endl;
    cout << "==> The input file is empty." << endl;
    cout << "==> There is no information to process." << endl;
    cout << "==> Terminating the program!!!" << endl;
    cout << "***********************************************" << endl << endl;
    return 0;
  }
  
  // Looping Through File
  while (Input.good())
  {
    // Error for Invalid Calculation Type
    if ((calc.find("Math") != 0) && (calc.find("Trig") != 0))
    {
      cout << "Invalid Calculation Type: " << calc << endl;
      Input >> calc >> calc >> calc;
    }
    else
    { 
      // Inputting Operation
      Input >> op;
      
      // Error for Invalid Operations
      if ((calc.find("Math") == 0) && (op.find("+")!=0 && op.find("-")!=0 && op.find("*")!=0 && op.find("/")!=0 && op.find("%")!=0))
      {
        cout << "Invalid Operator for Math Operations: " << op << endl;
        Input >> calc >> calc;
      }
      else if ((calc.find("Trig") == 0) && (op.find("s")!=0 && op.find("c")!=0 && op.find("t")!=0))
      {
        cout << "Invalid Operator for Trig Operations: " << op << endl;
        Input >> calc >> calc;
      }
      else
      {
        // Math Outputs
        if (calc.find("Math") == 0)
        {
          Input >> num1 >> num2;
          if (op.find("+") == 0)
            cout << "Add: " << num1 << "+" << num2 << " = " << (num1+num2) << endl;
          else if (op.find("-") == 0)
            cout << "Sub: " << num1 << "-" << num2 << " = " << (num1-num2) << endl;
          else if (op.find("*") == 0)
            cout << "Mul: " << num1 << "*" << num2 << " = " << (num1*num2) << endl;
          else if (op.find("/") == 0)
            cout << "Div: " << num1 << "/" << num2 << " = " << (num1/num2) << endl;
          else
            cout << "Mod: " << num1 << "%" << num2 << " = " << (int(num1)%int(num2)) << endl;
        }
        else
        {
          // Trig Outputs
          Input >> dr >> angle;
          if (dr.find("d") == 0)
          {
            if (op.find("s") == 0)
            {
              cout << "sin(degrees): sin(" << angle << ") = " << sin(angle*(pi/180)) << endl;
            }
            else if (op.find("c") == 0)
            {
              cout << "cos(degrees): cos(" << angle << ") = " << cos(angle*(pi/180)) << endl;
            }
            else
            {
              cout << "tan(degrees): tan(" << angle << ") = " << tan(angle*(pi/180)) << endl;
            }
          }
          else
          {
            if (op.find("s") == 0)
            {
              cout << "sin(radians): sin(" << angle << ") = " << sin(angle) << endl;
            }
            else if (op.find("c") == 0)
            {
              cout << "cos(radians): cos(" << angle << ") = " << cos(angle) << endl;
            }
            else
            {
              cout << "tan(radians): tan(" << angle << ") = " << tan(angle) << endl;
            }
          }
        }
      }
    }
    // Inputting Next Calculation
    Input >> calc;
  }
  cout << endl;
  return 0;
}
