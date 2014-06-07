/* 
 * File:   Volunteer.h
 * Author: Michael
 *
 * Created on June 2, 2014, 1:29 PM
 */

#ifndef VOLUNTEER_H
#define	VOLUNTEER_H

#include "Person.h"

using namespace std;

class Volunteer:public Person{
public:
    Volunteer( int );
    void setHours( float );
    int getType(){ return 2; };
    float getHours();
    float getPay(){
        return 0.0;
    }
    string toString();
private:
    float hours;
};

#endif	/* VOLUNTEER_H */

