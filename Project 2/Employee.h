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
    Employee( int id );
    void setPayrate( float );
    void setHours( float );
    int getType(){ return 0; };
    float getPayrate();
    float getHours();
    float getPay();
    string toString();
private:
    float payrate;
    float hours;
};

#endif	/* EMPLOYEE_H */

