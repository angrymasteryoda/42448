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
void listHeader();
void deleteEmp( Data & );
void search( Data & );
void searchMenu();

int main( int argc, char** argv ) {
    char option;
    
    Data data( "save.txt" );
    data.load( "lol.txt" );
    
    cout << "Welcome to employee management 1.0\n";
    do {
        menu();
        cout << "Enter an option from the menu\n";
        cin >> option;
        //option = cin.get();
        
        switch( option ){
            case 'b':
                build( data );
                break;
            case 'l':
                load( data );
                break;
            case 'i':
                list( data );
                break;
            case 'd':
                deleteEmp( data );
                break;
            case 's':
                search( data );
                break;
            case 'q':
                cout << "Bye.\n";
                break;
        }
    } while( option != 'q' );
    
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
    cout << "Press q ----> To Quit\n";
}

/**
 * build the employee table
 * @param data
 */
void build( Data &data ){
    int option = 0;
    do{
        cout << "What type of employee are you added?";
        cout << "\n\t1 Regular paid employee.\n\t2 Intern.\n\t3 Volunteer\n\t4 Main menu\n";
        cin >> option;
        
        switch ( option ) {
            case 1:
                buildEmployees( data );
                break;
            case 2:
                buildIntern( data );
                break;
            case 3:
                buildVolunteer( data );
                break;
        }
    }
    while( option != 4 );
    
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
        cout << "Enter the employees id number: ";
        cin >> inNum;
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
        cout << "Enter the interns id number: ";
        cin >> inNum;
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
        cout << "Enter the volunteers id number: ";
        cin >> inNum;
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

void listHeader(){
    cout << '|'<< setw( 8 ) << "Id |" << setw( 20 ) << "Fname |" << setw( 20 ) << "Lname |" << " Age |" << " Sex |"
            << " Pay Rate |" << " Hours |" << endl;
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

void search( Data &data ){
    char option;
    do {
        searchMenu();
        cout << "Enter an option from the menu\n";
        cin >> option;
        
        switch( option ){
            case 'i':
                int id;
                cout << "Enter an id to search for: ";
                cin >> id;
                listHeader();
                data.searchId( id );
                break;
            case 'q':
                break;
        }
    } while( option != 'q' );
}

void searchMenu(){
    cout << endl;
    cout << "Press i ----> Search by id\n";
    cout << "Press q ----> Back to Main Menu\n";
}

