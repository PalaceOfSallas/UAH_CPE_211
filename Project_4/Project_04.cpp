//****************************************
// Program Title: Launching Objects and Doing Math
// Project File: Project_04.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 09/14/18
// Program Description: This program computes the time for a projectile to reach maximum height, time for the projectile to
// hit the ground, maximum height, and maximum distance given the initial velocity and angle.
//****************************************
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Variables
    const double Pi = 3.14159265;    // Constant Pi
    const double g = 9.80665;        // Constant Gravity (m/s^2)
    double v;        // Initial Velocity
    double th;       // Time to Reach Maximum Height
    double td;       // Time to Reach Maximum Distance
    double h;        // Maximum Height
    double d;        // Maximum Distance
    double a;        // Starting Angle
    ifstream InFile; // Inputted File
    string inputFile; // Variable Assigned to Inputted File


    // Header
    cout << endl << string(30,'*') << endl;
    cout << string(5,'*') << " Projectile Motion" << endl;
    cout << string(30,'*') << endl << endl;


    // Inputing and Opening External File
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    cout << inputFile << endl << endl;
    InFile.open(inputFile.c_str());


    // Copy and Pasted Code from Instructions
     if(InFile.fail())
    {
        cout << string (47,'*') << endl;
        cout << "==> Input file failed to open properly!\n";
        cout << "==> Name of file opened: " << inputFile << endl;
        cout << "==> Terminating program!!!\n";
        cout << string (47,'*') << endl;
        return 1;
    }


    // Assigning Values to Variables from External File
    InFile >> v;
    InFile >> a;


    // Velocity and Starting Angle Output
    cout << "Initial Velocity(in m/s): " << v << endl << endl;
    cout << "Starting angle(in degrees): " << a << endl << endl;


    // Converting Angle to Radians
    a= a*Pi/180.0;


    // Calculations
    th= (v*(sin(a)))/g;
    td= (2*v*(sin(a)))/g;
    h= (pow(v,2)*pow(sin(a),2))/(2*g);
    d= v*td*(cos(a));


    // Final Results Output
    cout << "Results:" << endl << string(8,'-') << endl;
    cout << setw(25) << left << "Time to max height:" << setprecision(3) << fixed << th << " seconds" << endl;
    cout << setw(25) << left << "Time to max distance:" << setprecision(3) << fixed << td << " seconds" << endl;
    cout << setw(25) << left << "Maximum height:" << setprecision(3) << fixed << h << " meters" << endl;
    cout << setw(25) << left << "Maximum distance:" << setprecision(3) << fixed << d << " meters" << endl << endl;


    return 0;
}
