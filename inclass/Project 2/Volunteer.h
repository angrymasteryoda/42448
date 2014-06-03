/* 
 * File:   Volunteer.h
 * Author: Michael
 *
 * Created on June 2, 2014, 1:29 PM
 */

#ifndef VOLUNTEER_H
#define	VOLUNTEER_H

class Volunteer:public Person{
public:
    void setHours( float );
    float getHours();
private:
    float hours;
};

#endif	/* VOLUNTEER_H */

