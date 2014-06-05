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
 * @param filename
 */
Data::Data( string file ){
    totalRecords = 0;
    fileName = file;   
}

/**
 * copy constructor
 * @param obj
 */
Data::Data( const Data &obj ){
    totalRecords = obj.totalRecords;
    fileName = obj.fileName;
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
    fileName = right.fileName;
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

/**
 * push back to employee vector
 * @param e
 */
void Data::pushBackEmployee(Employee e ){
    employees.push_back( e );
}

/**
 * push back to intern vector
 * @param i
 */
void Data::pushBackIntern(Intern i ) {
    interns.push_back( i );
}

/**
 * push back to volunteer vector
 * @param v
 */
void Data::pushBackVolunteer(Volunteer v){
    volunteers.push_back( v );
}

/**
 * save all the date to default file
 */
void Data::save(){
    save( getFileName() );
}

/**
 * save all the data to custom file
 * @param fileName
 */
void Data::save( string fileName ) {
    fstream file;
    file.open( fileName.c_str(), ios::out );
    
    for( int i = 0; i < employees.size(); i++ ){
        file << employees.at( i ).toString() << '\n';
    }
    
    for( int i = 0; i < interns.size(); i++ ){
        file << interns.at( i ).toString() << '\n';
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        file << volunteers.at( i ).toString() << '\n';
    }
    
    file.close();
}

/**
 * load the data from the default save location
 */
void Data::load(){
    load( getFileName() );
}

/**
 * load the data from a s
 * @param 
 */
void Data::load( string ){
    
}

void Data::setFileName(string s ) {
    fileName = s;
}

int Data::getTotalRecords(){
    return employees.size() + interns.size() + volunteers.size();
}

string Data::getFileName(){
    return fileName;
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
