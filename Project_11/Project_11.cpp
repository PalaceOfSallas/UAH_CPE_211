// **************************************************************
// **************************************************************
// Stephen Sallas
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 11
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "P11.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
  // Default
  Date::Date()
  {
    month = 1;
    day = 1;
    year = 1900;
  }
  
  // Parameterized
  Date::Date(int initMonth, int initDay, int initYear)
  {
    month = initMonth;
    day = initDay;
    year = initYear;
  }
  
// ************** TRANSFORMERS **************
  // Set
  void Date::SetDate(int m, int d, int y)
  {
    month = m;
    day = d;
    year = y;
  }
  
// ************** OBSERVERS *******************
  // Write
  void Date::WriteNumberFormat() const
  {
    if (month < 10)
      cout << "0";
    cout << month << "/";
    
    if (day < 10)
      cout << "0";
      
    cout << day << "/" << year << endl;
  }
  
  void Date::WriteNameFormat() const
  {
    if (month == 1)
      cout << "January ";
    if (month == 2)
      cout << "February ";
    if (month == 3)
      cout << "March ";
    if (month == 4)
      cout << "April ";
    if (month == 5)
      cout << "May ";
    if (month == 6)
      cout << "June ";
    if (month == 7)
      cout << "July ";
    if (month == 8)
      cout << "August ";
    if (month == 9)
      cout << "September ";
    if (month == 10)
      cout << "October ";
    if (month == 11)
      cout << "November ";
    if (month == 12)
      cout << "December ";
    
    cout << day << ", " << year << endl;
  }
  
  bool Date::SameDate(Date otherDate) const
  {
    return (month == otherDate.month && day == otherDate.day && year == otherDate.year);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  