/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 12:46 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

#include "Data.h"

using namespace std;

void menu();
void build( Data & );
void buildEmployees( Data&);
void buildIntern( Data & );
void buildVolunteer( Data & );
void load( Data & );
void list( Data & );
void listHeader( bool ispay = false );
void deleteEmp( Data & );
void search( Data & );
void searchMenu();
void hours( Data & );
void pay( Data & );
void edit( Data & );

int main( int argc, char** argv ) {
    char option;
    
    Data data( "new.txt" );
    data.load( "lol.txt" );
    
    data.print( 0, 0 );
    data.print( 0, 1 );
//    
//    cout << "Welcome to employee management 1.0\n";
//    do {
//        menu();
//        cout << "Enter an option from the menu\n";
//        cin >> option;
//        
//        switch( option ){
//            case 'b':
//                build( data );
//                break;
//            case 'l':
//                load( data );
//                break;
//            case 'i':
//                list( data );
//                break;
//            case 'd':
//                deleteEmp( data );
//                break;
//            case 's':
//                search( data );
//                break;
//            case 'h':
//                hours( data );
//                break;
//            case 'p':
//                pay( data );
//                break;
//            case 'e':
//                edit( data );
//                break;
//            case 'q':
//                cout << "Bye.\n";
//                break;
//        }
//    } while( option != 'q' );
//    
    return 0;
}

/**
 * Print the main menu for the program
 */
void menu(){
    cout << endl;
    cout << "Press b ----> Build The Employee Table\n";
    cout << "Press l ----> Load an Employee Table\n";
    cout << "Press i ----> List all Employee Data\n";
    cout << "Press d ----> Delete an Employee\n";
    cout << "Press s ----> Search for an Employee\n";
    cout << "Press h ----> Set Hours for Employees\n";
    cout << "Press p ----> View Payment Info\n";
    cout << "Press e ----> Edit Employee Info\n";
    cout << "Press q ----> To Quit\n";
}

/**
 * build the employee table
 * @param data
 */
void build( Data &data ){
    char option;
    do{
        cout << "What type of employee are you added?";
        cout << "\nPress e ----> Regular paid employee.\nPress i ----> Intern.\nPress v ----> Volunteer\nPress q ----> Main menu\n";
        cin >> option;
        
        switch ( option ) {
            case 'e':
                buildEmployees( data );
                break;
            case 'i':
                buildIntern( data );
                break;
            case 'v':
                buildVolunteer( data );
                break;
        }
    }
    while( option != 'q' );
    
    data.save();
}

/**
 * build the employees and save
 * @param data
 */
void buildEmployees( Data &data ){
    char option;
    do {
        int inNum;
        float inFloat;
        bool taken;
        do{
            cout << "Enter the employees id number: ";
            cin >> inNum;
            taken = data.isUnqiueId( inNum );
            if( !taken ) cout << "That id is being used use another\n";
        }
        while( !taken );
        Employee E( inNum );
        
        string temp;
        cout << "\nEnter the employees first name: ";
        cin.ignore();
        getline( cin, temp );
        E.setFname( temp );
        
        cout << "\nEnter the employees last name: ";
        cin >> temp;
        E.setLname( temp );
        
        cout << "\nEnter the employees age: ";
        cin >> inNum;
        E.setAge( inNum );
        
        do{
            cout << "\nEnter the employees sex (m/f): ";
            cin >> option;
            if ( option == 'f' || option == 'm' ){
                E.setSex( ( option == 'f' ? 0 : 1 ) );
            }
        }
        while( option != 'f' && option != 'm' );
        
        do{
            cout << "\nEnter the employees pay rate ( pay > 0): ";
            cin >> inFloat;
            E.setPayrate( inFloat );
        }
        while( inFloat < 0);
        
        do{
            cout << "\nEnter the hours worked now? (y/n): ";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
        
        if ( option == 'y' ){
            do {
                cout << "\nEnter the employees hours worked ( hours > 0): ";
                cin >> inFloat;
                E.setHours( inFloat );
            }
            while( inFloat < 0);
        }
        
        option = '\0';
        
        //save the employee into the db
        data.pushBackEmployee( E );
        do{
            cout << "Enter another y/n\n";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
    }
    while( option != 'n' );
}

/**
 * build the intern and save
 * @param data
 */
void buildIntern( Data &data ){
    char option;
    do {
        int inNum;
        float inFloat;
        bool taken;
        do{
            cout << "Enter the interns id number: ";
            cin >> inNum;
            taken = data.isUnqiueId( inNum );
            if( !taken ) cout << "That id is being used use another\n";
        }
        while( !taken );
        Intern E( inNum );
        
        string temp;
        cout << "\nEnter the interns first name: ";
        cin.ignore();
        getline( cin, temp );
        E.setFname( temp );
        
        cout << "\nEnter the interns last name: ";
        cin >> temp;
        E.setLname( temp );
        
        cout << "\nEnter the interns age: ";
        cin >> inNum;
        E.setAge( inNum );
        
        do{
            cout << "\nEnter the interns sex (m/f): ";
            cin >> option;
            if ( option == 'f' || option == 'm' ){
                E.setSex( ( option == 'f' ? 0 : 1 ) );
            }
        }
        while( option != 'f' && option != 'm' );
        
        do{
            cout << "\nIs intern paid? (y/n): ";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
        
        //if the intern is paid
        if( option == 'y' ) {
            E.setIsPaid( true );
            do{
                cout << "\nEnter the interns pay rate ( pay > 0): ";
                cin >> inFloat;
                E.setPayrate( inFloat );
            }
            while( inFloat < 0);
        }
        else{
            E.setIsPaid( false );
        }
        
        do{
            cout << "\nEnter the hours worked now? (y/n): ";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
        
        if ( option == 'y' ){
            do {
                cout << "\nEnter the interns hours worked ( hours > 0): ";
                cin >> inFloat;
                E.setHours( inFloat );
            }
            while( inFloat < 0);
        }
        
        option = '\0';
        
        //save the intern into the db
        data.pushBackIntern( E );
        do{
            cout << "Enter another y/n\n";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
    }
    while( option != 'n' );
}

/**
 * build the volunteer and save
 * @param data
 */
void buildVolunteer( Data &data ){
    char option;
    do {
        int inNum;
        float inFloat;
        bool taken;
        do{
            cout << "Enter the volunteers id number: ";
            cin >> inNum;
            taken = data.isUnqiueId( inNum );
            if( !taken ) cout << "That id is being used use another\n";
        }
        while( !taken );
        Volunteer E( inNum );
        
        string temp;
        cout << "\nEnter the volunteers first name: ";
        cin.ignore();
        getline( cin, temp );
        E.setFname( temp );
        
        cout << "\nEnter the volunteers last name: ";
        cin >> temp;
        E.setLname( temp );
        
        cout << "\nEnter the volunteers age: ";
        cin >> inNum;
        E.setAge( inNum );
        
        do{
            cout << "\nEnter the volunteers sex (m/f): ";
            cin >> option;
            if ( option == 'f' || option == 'm' ){
                E.setSex( ( option == 'f' ? 0 : 1 ) );
            }
        }
        while( option != 'f' && option != 'm' );
        
        do{
            cout << "\nEnter the hours worked now? (y/n): ";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
        
        if ( option == 'y' ){
            do {
                cout << "\nEnter the interns hours worked ( hours > 0): ";
                cin >> inFloat;
                E.setHours( inFloat );
            }
            while( inFloat < 0);
        }
        
        option = '\0';
        
        //save the intern into the db
        data.pushBackVolunteer( E );
        do{
            cout << "Enter another y/n\n";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
    }
    while( option != 'n' );
}

/**
 * load db from a file
 * @param 
 */
void load( Data &data ){
    char option;
    do{
        cout << "load data from " << data.getFileName() << " or from another file ( y/n ): ";
        cin >> option;
    }
    while( option != 'y' && option != 'n' );
    
    if( option == 'y' ){
        data.load();
    }
    else {
        string file;
        cout << "enter a filename to load from: ";
        cin.ignore();
        getline( cin, file );
        data.load( file );
    }
}

/**
 * list all the employee data
 * @param data
 */
void list( Data &data ){
    listHeader();
    for( int i = 0; i < data.getTypes(); i++ ) {
        data.printFormatedPerson( i );
    }
}

void listHeader( bool isPay ){
    if( isPay ){
        cout << '|'<< setw( 8 ) << "Id |" << setw( 20 ) << "Fname |" << setw( 20 ) << "Lname |" << setw( 11 ) << " Pay |" << " Type |" << endl;
    }
    else{
        cout << '|'<< setw( 8 ) << "Id |" << setw( 20 ) << "Fname |" << setw( 20 ) << "Lname |" << " Age |" << " Sex |"
            << " Pay Rate |" << " Hours |" << " Type |" << endl;
    }
}

/**
 * delete employee by id
 * @param data
 */
void deleteEmp( Data &data ){
    int id;
    do{
        cout << "Enter the id of the employee you want to delete or -1 to cancel\n";
        cin >> id;
    }
    while( id == 0);
    
    if( data.deleteById( id ) ) {
        cout << "Deleted successfully\n";
    }
    else {
        cout << "Could not find that employee\n";
    }    
}

/**
 * search the employee by all the properties of the classes
 * @param data
 */
void search( Data &data ){
    char option;
    do {
        searchMenu();
        cout << "Enter an option from the menu\n";
        cin >> option;
        
        string name;
        int num;
        float fnum;
        char sex;
        switch( option ){
            case 'i':
                cout << "Enter an id to search for: ";
                cin >> num;
                listHeader();
                data.searchId( num );
                break;
            case 'f':
            case 'l':
                cout << "Enter a name to search for:\n";
                cin.ignore();
                getline( cin, name );
                listHeader();
                data.searchName( name, ( option == 'f' ? true : false ) );
                break;
            case 'a':
                cout << "Enter an age to search for: ";
                cin >> num;
                listHeader();
                data.search( 1, num );
                break;
            case 's':
                do{
                    cout << "Enter the sex to search for (f/m): ";
                    cin >> sex;
                }
                while( sex != 'f' && sex != 'm');
                listHeader();
                data.search( 2, ( sex == 'f' ? 0 : 1 ) );
                break;
            case 'p':
                cout << "Enter an pay rate to search for: ";
                cin >> fnum;
                listHeader();
                data.search( 3, 0, fnum );
                break;
            case 'q':
                break;
        }
    } while( option != 'q' );
}

/**
 * menu for searching
 */
void searchMenu(){
    cout << endl;
    cout << "Press i ----> Search by id\n";
    cout << "Press f ----> Search by First Name\n";
    cout << "Press l ----> Search by Last Name\n";
    cout << "Press a ----> Search by Age\n";
    cout << "Press s ----> Search by Sex\n";
    cout << "Press p ----> Search by Pay Rate\n";
    cout << "Press q ----> Back to Main Menu\n";
}

/**
 * set the hours worked for employees
 * @param data
 */
void hours( Data &data ){
    int id;
    float hours;
    char option;
    do{
        cout << "Enter the id of the employee: ";
        cin >> id;
        do{
            cout << "Enter their hours worked (hours >= 0): ";
            cin >> hours;
        }
        while( hours < 0 );
        data.setHours( id, hours );
        do{
            cout << "Enter another y/n\n";
            cin >> option;
        }
        while( option != 'y' && option != 'n' );
    }
    while( option != 'n' );
    data.save();
    
}

/**
 * get the pay for one or all employees
 * @param $data
 */
void pay( Data &data ){
    int id;
    cout << "Enter the id of the employee or -1 for all employees: ";
    cin >> id;
    listHeader( true );
    data.getPay( id );
}

/**
 * Edit the employee
 * @param data
 */
void edit( Data &data ){
    int id;
    cout << "Enter the id of the employee you want to edit\n";
    cin >> id;
    data.edit( id );
}
