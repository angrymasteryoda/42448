/* 
 * File:   Intern.h
 * Author: Michael
 *
 * Created on June 2, 2014, 12:53 PM
 */

#ifndef INTERN_H
#define	INTERN_H

#include "Person.h"
using namespace std;

class Intern:public Person{
public:
    Intern( int id = 0 );
    void setPayrate( float );
    void setHours( float );
    void setIsPaid( bool );
    float getPayrate();
    float getHours();
    float getPay();
    bool getIsPaid();
private:
    float payrate;
    float hours;
    bool isPaid;
};


#endif	/* INTERN_H */

