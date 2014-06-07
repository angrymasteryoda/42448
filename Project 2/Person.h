/* 
 * File:   Person.h
 * Author: Michael
 *
 * Created on June 2, 2014, 12:52 PM
 */

#ifndef PERSON_H
#define	PERSON_H

#include <string>
#include <sstream> //streamstream

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
    virtual string toString() = 0;
    int getId();
    int getAge();
    int getSex();
    virtual int getType() = 0;
    virtual float getPay() = 0;
protected:
    string fname;
    string lname;
    int id;
    int age;
    int sex;
};

#endif	/* PERSON_H */

