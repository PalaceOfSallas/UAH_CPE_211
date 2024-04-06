//****************************************
// Program Title: Compressing and Decompressing
// Project File: Project_08.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 10/19/18
// Program Description: Compressing and Decompressing Files 
// 
//****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;

// Function Prototypes
void menu();
int integer();
void openinput(ifstream& Input);
void openoutput(ofstream& Output);
void compression(ifstream& Input, ofstream& Output);
void decompression(ifstream& Input, ofstream& Output);

// Main Function
int main()
{
  // Variables
  int selection;
  ifstream Input;
  ofstream Output;
 
  // Opening Menu and Retrieving Selection 
  menu();
  selection = integer();

  
  // Path Based on Selection
  
  // Quitting
  if (selection == 0)
  {
  cout << "Quit selected.  Terminating program now.." << endl << endl;
  return 0;
  }
  
  // Compressing
  else if (selection == 1)
  {
  openinput(Input);
  openoutput(Output);
  compression(Input, Output);
  cout << "==> File has been Compressed" << endl;
  Input.close();
  Output.close();
  main();
  }
  
  // Decompressing
  else if (selection == 2)
  {
  openinput(Input);
  openoutput(Output);
  decompression(Input, Output);
  cout << "==> File has been Decompressed" << endl;
  Input.close();
  Output.close();
  main();
  }
  
  return 0;
}


// Menu Function
void menu()
{
  cout << endl << string(10,'*') << "  Compression Menu  " << string(10,'*') << endl;
  cout << "0. Exit Program" << endl;
  cout << "1. Compress File" << endl;
  cout << "2. Uncompress File" << endl;
  cout << string(40,'*') << endl << endl;
  cout << "Input your selection now: ";
}


// Integer Selection Function
int integer()
{
  // Variables
  int s;
  char x;
  
  // Inputting Selection
  cin >> s;
  
  // Loop if Character is Entered
  while (cin.fail())
  {
  cin.clear();
  cin.get(x);
  cout << x << endl << endl;
  cin.ignore();
  cout << string(14,'*') << " Invalid Selection " << string(14,'*') << endl;
  cout << "==> Invalid character entered!!" << endl; 
  cout << "==> Please enter 0, 1 or 2" << endl;
  cout << string(47,'*') << endl;
  menu();
  cin >> s;
  }
  
  // Statements if Integer is Entered
  if (s==0)
  {
    cout << s << endl << endl;
    return s;
  }
  else if (s==1)
  {
    cout << s << endl << endl;
    return s;
  }
  else if (s==2)
  {
    cout << s << endl << endl;
    return s;
  }
  else
  {
    cin.clear();
    cin.get(x);
    cout << x << endl << endl;
    cin.ignore();
    cout << string(14,'*') << " Invalid Selection " << string(14,'*') << endl;
    cout << "==> Invalid integer value entered" << endl; 
    cout << "==> Please enter 0, 1 or 2" << endl;
    cout << string(47,'*') << endl;
    menu();
    cin >> s;
  }
  
  // Echoprint
  cout << s << endl << endl;
  
  return s;
}
  

// Input Opening Function
void openinput(ifstream& Input)
{
  // Variables
  string file;
  
  // Opening File
  cout << "Enter the name of the input file: ";
  cin >> file;
  cout << file << endl << endl;
  Input.open(file.c_str());
  
  // File Open Error
  if (Input.fail())
  {
  cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
  cout << "==> Output file failed to open properly!!" << endl;
  cout << "==> Attempted to open file: " << file << endl;
  cout << "==> Selected operation has been cancelled" << endl;
  cout << string(47,'*') << endl;
  main();
  }
  
  return;
}
  
  
// Output Opening Function
void openoutput(ofstream& Output)
{
  // Variables
  string file;
  
  // Opening File
  cout << "Enter the name of the output file: ";
  cin >> file;
  cout << file << endl << endl;
  Output.open(file.c_str());
  
}


void compression(ifstream& Input, ofstream& Output)
{
  // Variables
  char x;
  
  // Retrieving First Character
  Input.get(x);
  
  // Error for Empty File
  if (Input.fail())
  {
   cout << string(14,'*') << " Empty Input File " << string(14,'*') << endl;
   cout << "==> Empty file for Compression" << endl;
   cout << "==> Nothing written to the output file" << endl;
   cout << string(47,'*') << endl;
   main();
  }

  // Compression
  // Could Not Figure Out
}


void decompression(ifstream& Input, ofstream& Output)
{
  // Variables
  char x;
  char y;
  int counter = 0;
  
  // Retrieving First Character
  Input >> x;
  
  // Error for Empty File
  if (Input.fail())
  {
   cout << string(14,'*') << " Empty Input File " << string(14,'*') << endl;
   cout << "==> Empty file for Decompression" << endl;
   cout << "==> Nothing written to the output file" << endl;
   cout << string(47,'*') << endl;
   main();
  }
  
  // Decompressing
  // Could Not Figure Out
 while (Input.good() && !Input.eof())
 {
 Input.get(y);
 while (counter < x)
 {
 Output << y;
 counter++;
 }
 Input >> x;
 }
}
    
  
  
  
  
  