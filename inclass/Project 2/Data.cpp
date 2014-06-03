/* 
 * File:   Data.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 8:20 PM
 */

#include "Data.h"

using namespace std;

/**
 * Constructor
 * @param records this is here just to fix a compile issue 
 */
Data::Data( int records ){
    totalRecords = records;
}

/**
 * copy constructor
 * @param obj
 */
Data::Data( const Data &obj ){
    totalRecords = obj.totalRecords;
    for( int i = 0; i < obj.employees.size(); i++ ){
        employees.push_back( obj.employees.at( i ) );
    }
    for( int i = 0; i < obj.interns.size(); i++ ){
        interns.push_back( obj.interns.at( i ) );
    }
    for( int i = 0; i < obj.volunteers.size(); i++ ){
        volunteers.push_back( obj.volunteers.at( i ) );
    }
}

void Data::operator = ( const Data &right ){
    totalRecords = right.totalRecords;
    for( int i = 0; i < right.employees.size(); i++ ){
        employees.push_back( right.employees.at( i ) );
    }
    for( int i = 0; i < right.interns.size(); i++ ){
        interns.push_back( right.interns.at( i ) );
    }
    for( int i = 0; i < right.volunteers.size(); i++ ){
        volunteers.push_back( right.volunteers.at( i ) );
    }
}

void Data::pushBackEmployee(Employee e ){
    employees.push_back( e );
}

void Data::pushBackIntern(Intern i ) {
    interns.push_back( i );
}

void Data::pushBackVolunteer(Volunteer v){
    volunteers.push_back( v );
}

vector<Employee> Data::getEmployees(){
    return employees;
}

vector<Intern> Data::getInterns(){
    return interns;
}

vector<Volunteer> Data::getVolunteers(){
    return volunteers;
}

int Data::getTotalRecords(){
    return employees.size() + interns.size() + volunteers.size();
}
