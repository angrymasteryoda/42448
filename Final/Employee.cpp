/* 
 * File:   Employee.cpp
 * Author: Michael
 *
 * Created on June 10, 2014, 6:55 PM
 */

#include "Employee.h"

using namespace std;

Employee::Employee( char name[] , char job[] , float rate ){
    setHourlyRate( rate );
    MyName = name;
    JobTitle = job;
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}

float Employee::Tax( float p ){
    if ( p <= 500.0 ) {
        p -= p * 0.1;
    }
    else if ( (p <= 1000.0 ) && ( p > 500.0 ) ) {
        float r = 50.0 + (p - 500.0 ) * 0.2;
        p -= r;
    }
    else {
        float r = 150.0 + ( p - 1000.0 ) * 0.3;
        p -= r;
    }
    return p;
}

int Employee::setHoursWorked( int hours ){
    if( hours > 0 && hours < 84 ) {
        HoursWorked = hours;
        return hours;
    } 
    
    cout << "Unacceptable Hours Worked" << endl;
    return 0;
}   
float Employee::setHourlyRate( float rate ){
    if( rate > 0 && rate < 200 ) {
        HourlyRate = rate;
        return rate;
    }
    
    cout << "Unacceptable Hourly Rate" << endl;
    return 0;
}

float Employee::CalculatePay( float rate, int hours ){
    if (hours <= 40) {
        GrossPay = ( hours * rate );
    }
    else if ( ( hours > 40 ) && ( hours <= 50 ) ) {
      GrossPay = ( 40.0 * rate + rate * ( ( hours - 40) * 1.5 ) );
    }
    else {
      GrossPay = ( 40.0 * rate + rate * 15.0 + rate * ( hours - 50 ) * 2.0 );
    }
    NetPay = Tax( GrossPay );
}

float Employee::getGrossPay( float rate, int hours ) {
    CalculatePay( rate, hours );
    return GrossPay;
}

float Employee::getNetPay( float gross ){
    return Tax( gross );
}

void Employee::toString(){
    cout << "Name = " << MyName << " Title = " << JobTitle << " Hourly Rate = " << HourlyRate <<
            " Hours Worked = " << HoursWorked << " Gross Pay = " << GrossPay << " Net Pay = " << NetPay << endl;
}
