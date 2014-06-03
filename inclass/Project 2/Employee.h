/* 
 * File:   Employee.h
 * Author: Michael
 *
 * Created on June 2, 2014, 12:53 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include "Person.h"
using namespace std;

class Employee:public Person{
public:
    Employee( int id = 0 );
    void setPayrate( float );
    void setHours( float );
    float getPayrate();
    float getHours();
    float getPay();
private:
    float payrate;
    float hours;
};

#endif	/* EMPLOYEE_H */

