//****************************************
// Program Title: Arrays
// Project File: Project_10.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 10/15/18
// Program Description: Finding different statistics from a numerical array.
// 
//****************************************
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// Function Prototypes
void sort(float array[], int nums);
float average(float array[], int nums);
float median(float array[], int nums);
float variance(float array[], int nums, float a);
void inputfile(ifstream& Input);
int readnums(ifstream& Input, float array[]);

// Main Function
int main()
{
  // Variables
  ifstream Input;
  float array[50];
  float nums;
  float a;
  float m;
  float v;
  float sd;
  
  // Opening File
  inputfile(Input);
  
  // Reading Numbers into the Array and Total Amount of Numbers in it
  nums = readnums(Input, array);
  
  // Exiting Program if Error was Encountered
  if (nums == 0)
  return 0;
  
  // Sorting Numbers
  sort(array, nums);
  
  // Obtaining all Statistical Information from Functions
  a = average(array, nums);
  m = median(array, nums);
  v = variance(array, nums, a);
    
  // Finding Standard Deviation
  sd = pow(v,0.5);
  
  // Final Outputs
  cout << string(15,'*') << " File Statistics " << string(15,'*') << endl;
  cout << string(47,'*') << endl;
  cout << left << setw(25) << "Number of Values........." << nums << endl;
  cout << left << setw(25) << "Average................." << a << endl;
  cout << left << setw(25) << "Median.................." << m << endl;
  cout << left << setw(25) << "Variance................" << v << endl;
  cout << left << setw(25) << "Standard Deviation......." << sd << endl;
  cout << string(47,'*') << endl << endl;
  
  return 0;
}


// Sorting Function
void sort(float array[], int nums)
{
  // Variables
  float temp;
  int j,k;
  
  // Sorting
  for (k = 0; k < nums-1; k++)
  {
    for(j = k+1; j < nums; j++)
    {
      if (array[k] > array[j])
      {
      temp = array[k];
      array[k] = array[j];
      array[j] = temp;
      }
    }
  }
}


// Averaging Function
float average(float array[], int nums)
{
 // Variables
 int x = 0; //counter variable
 float avg = 0.0; 
 
 // Finding Average
 while (x < nums)
 {
 avg+=array[0+x];
 x++;
 }
 avg/=nums;
 
 // Returning Average
 return avg;
}


// Median Function
float median(float array[], int nums)
{
  // Variables
  float even = 0;
  float odd = 1;
  float e_or_o;
  float med;
  
  // Finding if Amount of Numbers is Odd or Even
  e_or_o = nums%2;
  
  // Finding Median if Odd
  if (e_or_o == odd)
  med = array[((nums+1)/2)-1];
  
  // Finding Median if Even
  if (e_or_o == even)
  med = (array[nums/2] + array[(nums/2)-1])/2.0;
  
  // Outputting Median
  return med;  
}


// Variance Function
float variance(float array[], int nums, float a)
{
  // Variables
  int x = 0; //counter variable
  float var;
  
  // Finding Variance
 while (x < nums)
 {
 var+=(pow((array[0+x]-a),2));
 x++;
 }
 var/=nums;
 
 // Returning Variance
 return var;
}


// Input File Function
void inputfile(ifstream& Input)
{
  // Variables
  string file;
  
  // Opening Input File
  cout << endl << "Enter the name of the input file (ctrl-c to exit): ";
  cin >> file;
  cout << file << endl << endl;
  Input.open(file.c_str());
  
  // Fail Statements and Loop
  while (Input.fail())
  {
  cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
  cout << "==>  Input file could not be opened." << endl;
  cout << "==>  " << file << " is an invalid file!!" << endl;
  cout << "==>  Please try again." << endl;
  cout << string(47,'*') << endl;
  Input.close();
  Input.clear();
  cout << endl << "Enter the name of the input file (ctrl-c to exit): ";
  cin >> file;
  cout << file << endl << endl;
  Input.open(file.c_str());
  }
}


// Reading Floating Point Numbers Function
int readnums(ifstream& Input, float array[])
{
  // Variables
  float totalnums;
  float num;
  int index = 0;
  float readnums = 0;
  
  // Reading in First Number to Find the Total Numbers in the File
  Input >> totalnums;
  
  // Fail Message if Number of Values Cannot be Read
  if (Input.fail() && !Input.eof())
  {
  cout << string(15,'*') << " File Read Error " << string(15,'*') << endl;
  cout << "==> Error occurred reading the number of values" << endl;
  cout << "==> present in the input file." << endl;
  cout << "==> Program terminated." << endl;
  cout << string(47,'*') << endl << endl;
  return 0;
  }
  
  // Fail Message if File Empty
  if (Input.fail() && Input.eof())
  {
  cout << string(15,'*') << " Empty Input File " << string(14,'*') << endl;
  cout << "==> The input file is empty." << endl;
  cout << "==> There is no information to process." << endl;
  cout << "==> Terminating the program!!!" << endl;
  cout << string(47,'*') << endl << endl;
  return 0;
  }
  
  // Reading Numbers into the Array
  Input >> num;
  readnums++;
  while (Input.good())
  {
  array[index] = num;
  index++;
  Input >> num;
  readnums++;
  if (Input.fail() && !Input.eof())
  {
  cout << string(15,'*') << " File Read Error " << string(15,'*') << endl;
  cout << "==> Error occurred reading in one of the numbers." << endl; 
  cout << "==> Program terminated." << endl;
  cout << string(47,'*') << endl << endl;
  return 0;
  }
  }
  
  // Returning Total Number of Values in Array
  return totalnums;
}
