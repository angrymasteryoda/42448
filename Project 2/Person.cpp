/* 
 * File:   Person.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 1:17 PM
 */

#include "Person.h"


void Person::setFname( string str ){
    fname = str;
}

void Person::setLname( string str ) {
    lname = str;
}

void Person::setId( int id ) {
    this->id = id;
}

void Person::setAge( int a ) {
    age = a;
}

/**
 * set the sex 0 F, 1 M
 * @param s
 */
void Person::setSex( int s ){
    if( s == 0 || s == 1 ){
        sex = s;
    }
}

string Person::getFname(){
    return fname;
}

string Person::getLname(){
    return lname;
}

int Person::getId() {
    return id;
}

int Person::getAge(){
    return age;
}

int Person::getSex(){
    return sex;
}

char Person::getSexLetter(){
    return sex == 0 ? 'F' : 'M';
}
