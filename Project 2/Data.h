/* 
 * File:   Data.h
 * Author: Michael
 *
 * Created on June 2, 2014, 8:19 PM
 */

#ifndef DATA_H
#define	DATA_H

#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Employee.h"
#include "Intern.h"
#include "Volunteer.h"

using namespace std;


class Data{
public:
    Data( string );
    Data( const Data & );
    void operator=( const Data & );
    int getTotalRecords();
    int getTypes(){ return 3; }
    void pushBackEmployee( Employee );
    void pushBackIntern( Intern );
    void pushBackVolunteer( Volunteer );
    void save();
    void save( string );
    void load();
    void load( string );
    void setFileName( string );
    void printFormatedPerson( int );
    void printEmployee( int, bool isPay = false );
    void printIntern( int, bool isPay = false );
    void printVolunteer( int, bool isPay = false );
    void search( int, int num = 0, float fnum = 0 );
    void searchId( int );
    void searchName( string, bool );
    void searchAge( int );
    void searchSex( char );
    void searchPayrate( float );
    void setHours( int, float );
    void getPay( int );
    void printPay( int );
    bool deleteById( int );
    string getFileName();
    vector<Employee> getEmployees();
    vector<Intern> getInterns();
    vector<Volunteer> getVolunteers();
private:
    void clear();
    int totalRecords;
    string fileName;
    vector<Employee> employees;
    vector<Intern> interns;
    vector<Volunteer> volunteers;
    
};

#endif	/* DATA_H */

