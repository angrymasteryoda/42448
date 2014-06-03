/* 
 * File:   Data.h
 * Author: michael.risher
 *
 * Created on June 2, 2014, 3:52 PM
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
    Data();
    vector<Employee> getEmployees();
    vector<Intern> getInterns();
    vector<Volunteer> getVolunteers();
private:
    vector<Employee> employees;
    vector<Intern> interns;
    vector<Volunteer> volunteers;
};

#endif	/* DATA_H */

