/* 
 * File:   Employee.h
 * Author: Michael
 *
 * Created on June 10, 2014, 6:53 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee {
public:
    Employee(char[],char[],float);  //Constructor
    float  CalculatePay(float,int); //Procedure
    float  getGrossPay(float,int);  //Procedure
    float  getNetPay(float);        //Procedure
    void   toString();              //Procedure
    int    setHoursWorked(int);     //Procedure
    float  setHourlyRate(float);    //Procedure
private:
//    double Tax(float);      //Utility Procedure //wtf double
    float  Tax(float);      //Utility Procedure
    char*   MyName;      //Property
    char*   JobTitle;    //Property
    float  HourlyRate;      //Property
    int    HoursWorked;     //Property
    float  GrossPay;        //Property
    float  NetPay;          //Property
};

#endif	/* EMPLOYEE_H */

