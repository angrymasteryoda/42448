/* 
 * File:   Volunteer.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 7:57 PM
 */

#include "Volunteer.h"


using namespace std;

Volunteer::Volunteer( int id ){
    setFname( "" );
    setLname( "" );
    setId( id );
    setAge( 0 );
    setSex( 0 );
    setHours( 0.0 );
}

void Volunteer::setHours( float h ){
    hours = h;
} 

float Volunteer::getHours(){
    return hours;
}

string Volunteer::toString(){
    stringstream s;
    s << "vol" << id << '\t' << fname << '\t' << lname << '\t' << age << '\t' << sex << '\t' << hours;
    return s.str();
}
