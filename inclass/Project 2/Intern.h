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
private:
    float payrate;
    float hours;
    bool isPaid;
};


#endif	/* INTERN_H */

