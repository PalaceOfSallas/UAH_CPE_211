//****************************************
// Program Title: Magazine Subscriptions
// Project File: Project_09.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 11/2/18
// Program Description: 
// 
//****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
#include <cctype>
using namespace std;

// Structure Declarations
 struct SubscriberName
 {
 string first_name;
 string last_name;
 int customer_id;
 };
 struct Address
 {
 string street;
 string city;
 string state;
 int zip;
 };
 struct Date
 {
 string month;
 int day;
 int year;
 };
 struct Renewal_Information
 {
 int months_left;
 Date renewal;
 };
 struct Subscriber
 {
 SubscriberName subscribername;
 Address address;
 Renewal_Information renewal_information;
 };


// Function Prototypes
void inputfile(ifstream& Input);
void outputfile(ofstream& Output);
bool inrecords(ifstream& Input, Subscriber& Person, bool status);
void outrecords(ofstream& Output, Subscriber& Person, bool empty);


// Main Function
int main()
{
  // Variables
 ifstream Input;
 ofstream Output;
 Subscriber Person;
 int subscribers = 0;
 int expired = 0;
 bool empty = 0;
 // Opening Input and Output Files
 inputfile(Input);
 outputfile(Output);
 
 // Reading Information
 bool status = inrecords(Input, Person, status);
 
 // Fail Message if Empty
 if (!status)
 {
 cout << "===> Input file is empty.  Program terminated" << endl << endl;
 empty = 1;
 outrecords(Output, Person, empty);
 }
 
 // Looping and Outputting
 else
 {
 subscribers++;
 if (Person.renewal_information.months_left == 0)
 {
 expired++;
 outrecords(Output, Person, empty);
 }
 while (status)
 {
 int status = inrecords(Input, Person, status);
 if (status)
 {
 subscribers++;
 if (Person.renewal_information.months_left == 0)
 {
 expired++;
 outrecords(Output, Person, empty);
 }
 }
 if (status == 0)
 break;
 }
 cout << endl << string(47,'-') << endl;
 cout << "Number of subscribers processed: " << subscribers << endl;
 cout << "The number of expired subscriptions is: " << expired << endl;
 cout << string(47, '-') << endl << endl;
 }
 
 return 0;
}


// Function for Opening Input File
void inputfile(ifstream& Input)
{
  // Variables
  string file;
  
  // Opening Input File
  cout << endl << "Enter name of input file or Control-C to quit program: ";
  cin >> file;
  cout << file << endl << endl;
  Input.open(file.c_str());
  
  // Fail Statements and Loop
  while (Input.fail())
  {
  cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
  cout << "==> Input file failed to open properly!!" << endl;
  cout << "==> Attempted to open file: " << file << endl;
  cout << "==> Please try again..." << endl;
  cout << string(47,'*') << endl;
  Input.close();
  Input.clear();
  cout << endl << "Enter name of input file or Control-C to quit program: ";
  cin >> file;
  cout << file << endl << endl;
  Input.open(file.c_str());
  }
}


// Function for Opening Output File
void outputfile(ofstream& Output)
{
  // Variables
  string file;
  
  // Opening Output File
  cout << "Enter name of output file or Control-C to quit program: ";
  cin >> file;
  cout << file << endl << endl;
  Output.open(file.c_str());
  
  // Fail Statements and Loop
  while (Output.fail())
  {
  cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
  cout << "==> Output file failed to open properly!!" << endl;
  cout << "==> Attempted to open file: " << file << endl;
  cout << "==> Please try again..." << endl;
  cout << string(47,'*') << endl;
  Output.close();
  Output.clear();
  cout << endl << "Enter name of output file or Control-C to quit program: ";
  cin >> file;
  cout << file << endl << endl;
  Output.open(file.c_str());
  } 
}


// Function for Obtaining Records
bool inrecords(ifstream& Input, Subscriber& Person, bool status)
{
  // Reading in First Name
  Input >> Person.subscribername.first_name;
  
  // Fail Message if Empty
  if (Input.fail() || Input.eof())
  {
  status = 0;
  return status;
  }
  
  
  // Reading in Rest of Info
  Input >> Person.subscribername.last_name;
  Input >> Person.subscribername.customer_id;
  cout << "====> Processing Customer ID: " << Person.subscribername.customer_id << endl;
  Input.ignore(INT_MAX, '\n');
  getline(Input, Person.address.street, '\n');
  getline(Input, Person.address.city, '\n');
  getline(Input, Person.address.state, '\n');
  Input >> Person.address.zip;
  Input >> Person.renewal_information.months_left;
  Input >> Person.renewal_information.renewal.month;
  Input >> Person.renewal_information.renewal.day;
  Input >> Person.renewal_information.renewal.year;
  status = 1;
  return status;
}


//Function for Outputting Records
void outrecords(ofstream& Output, Subscriber& Person, bool empty)
{
  // Fail Message if Empty
  if (empty)
  {
  Output << string(52,'-') << endl;
  Output << "==> The input file does not contain any information." << endl;
  Output << string(52,'-') << endl;
  }
  
  // Outputting to File
  else
  {
  Output << string(55,'*') << endl;
  Output << Person.subscribername.first_name << ' ' << Person.subscribername.last_name << '(' << Person.subscribername.customer_id << ')' << endl;
  Output << Person.address.street << endl;
  Output << Person.address.city << ", " << Person.address.state << ' ' << Person.address.zip << endl;
  Output << "The last renewal notice was sent on " << Person.renewal_information.renewal.month << ' ' << Person.renewal_information.renewal.day << ", " << Person.renewal_information.renewal.year << endl;
  Output << string(55,'*') << endl << endl;
  }
}
