//****************************************
// Program Title: Project_03.cpp
// Project File: Project_03.cpp
// Name: Stephen Sallas
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 9/7/18
// Program Description: This program will compute the savings account balance
// using four differenttypes of interest computing methods.
//****************************************
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
    //Variables
    double P;       // Principle
    double S_I;     // Balance Simple Interest
    double C_M;     // Balance Compounded Monthly
    double C_D;     // Balance Compounded Daily
    double C_C;     // Balance Compounded Continuously
    double R;       // Simple Interest Rate
    double T;       // Number of Years Invested
    double Reff_1;  // Effictive Simple Interst Rate for Monthly
    double Reff_2;  // Effictive Simple Interst Rate for Daily
    double Reff_3;  // Effictive Simple Interst Rate for Continuously

    //Inputs
    cout << "Input the starting balance: ";
    cin >> P;
    cout << P << endl;      // Echoprint
    cout << "Input the interst rate (Ex: 5 for 5%): ";
    cin >> R;
    cout << R << endl;      // Echoprint
    cout << "Input the number of years: ";
    cin >> T;
    cout << T << endl;      // Echoprint
    cout << endl;

    //Outputs
    cout << "For a principle of $" << setprecision(2) << fixed << P << endl;
    cout << "at and interest rate of " << R << "%" << endl;
    cout << "for a period of " << T << " years," << endl;
    cout << "the final account balance would be:" << endl;
    cout << endl;

    //Converting R to a decimal
    R=R/100;

    //Simple interest
    S_I= P*(1+T*R);
    cout << "Simple Interest:" << endl << "\tBalance = $" << S_I << endl;
    cout << endl;

    //Compounded Monthly
    Reff_1=((pow((1+R/12),(12*T))-1)/T);
    C_M=P*(1+T*Reff_1);
    cout << "Compounded Monthly:" << endl << "\tBalance = $" << C_M << endl;
    cout << "\tThe Effective Simple Interest Rate: " << Reff_1*100 << "%" << endl;
    cout << "\tBalance using Simple Interest at the Effective Rate = $" << C_M << endl;
    cout << endl;

    //Compounded Daily
    Reff_2=((pow((1+R/365),(365*T))-1)/T);
    C_D=P*(1+T*Reff_2);
    cout << "Compounded Daily:" << endl << "\tBalance = $" << C_D << endl;
    cout << "\tThe Effective Simple Interest Rate: " << Reff_2*100 << "%" << endl;
    cout << "\tBalance using Simple Interest at the Effective Rate = $" << C_D << endl;
    cout << endl;

    //Compounded Continuously
    Reff_3= (exp(R*T)-1)/T;
    C_C= P*(1+T*Reff_3);
    cout << "Compounded Continuously:" << endl << "\tBalance = $" << C_C << endl;
    cout << "\tThe Effective Simple Interest Rate: " << Reff_3*100 << "%" << endl;
    cout << "\tBalance using Simple Interest at the Effective Rate = $" << C_C << endl;
    cout << endl;




















    return 0;
}
