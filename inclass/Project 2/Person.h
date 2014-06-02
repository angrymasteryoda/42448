/* 
 * File:   Person.h
 * Author: Michael
 *
 * Created on June 2, 2014, 12:52 PM
 */

#ifndef PERSON_H
#define	PERSON_H

#include <string>
using namespace std;
class Person {
public:
    void setFname( string );
    void setLname( string );
    void setId( int );
    void setAge( int );
    void setSex( int );
    string getFname();
    string getLname();
    int getId();
    int getAge();
    int getSex();
private:
    string fname;
    string lname;
    int id;
    int age;
    int sex;
};

#endif	/* PERSON_H */

