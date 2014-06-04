/* 
 * File:   Intern.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 4:37 PM
 */

#include "Intern.h"

using namespace std;

Intern::Intern( int id ){
    setFname( "" );
    setLname( "" );
    setId( id );
    setAge( 0 );
    setSex( 0 );
    setIsPaid( false );
    setPayrate( 0.0 );
    setHours( 0.0 );
}

void Intern::setPayrate( float f ){
    payrate = f;
}

void Intern::setHours( float hours ){
    hours = hours;
}

void Intern::setIsPaid( bool flag ){
    
}

float Intern::getPayrate(){
    return payrate;
}

float Intern::getHours(){
    return hours;
}

float Intern::getPay(){
    if ( getIsPaid() ) {
        return getPayrate() * getHours();
    }
    else{
        return 0.0;
    }
}

bool Intern::getIsPaid(){
    return isPaid;
}

string Intern::toString(){
    stringstream s;
    s << "int" << id << '\t' << fname << '\t' << lname << '\t' << age << '\t' << sex << '\t' << isPaid << '\t' << payrate << '\t' << hours;
    return s.str();
}
