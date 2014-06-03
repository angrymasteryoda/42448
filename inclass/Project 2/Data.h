/* 
 * File:   Data.h
 * Author: Michael
 *
 * Created on June 2, 2014, 8:19 PM
 */

#ifndef DATA_H
#define	DATA_H

#include <vector>
#include "Employee.h"
#include "Intern.h"
#include "Volunteer.h"

using namespace std;

class Data{
public:
    Data( int );
    Data( const Data & );
    void operator=( const Data & );
    int getTotalRecords();
    void pushBackEmployee( Employee );
    void pushBackIntern( Intern );
    void pushBackVolunteer( Volunteer );
    vector<Employee> getEmployees();
    vector<Intern> getInterns();
    vector<Volunteer> getVolunteers();
private:
    int totalRecords;
    vector<Employee> employees;
    vector<Intern> interns;
    vector<Volunteer> volunteers;
};

#endif	/* DATA_H */

