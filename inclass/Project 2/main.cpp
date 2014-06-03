/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 12:46 PM
 */

#include <iostream>
#include <cstdlib>

#include "Data.h"

using namespace std;

void menu();
void build( Data );
void buildEmployees( Data );

int main( int argc, char** argv ) {
    char option;
    
    Data database();
    
    menu();
    do {
        cout << "enter a option from the menu\n";
        option = cin.get();
        
        switch( option ){
            case 'b':
                build( database );
                break;
            case 'q':
                exit( 255 );
                break;
        }
    } while( option != 'q' );
    
    return 0;
}

/**
 * Print the main menu for the program
 */
void menu(){
    cout << "Press b ----> Build The Employee Table\n";
}

/**
 * build the employee table
 * @param data
 */
void build( Data data ){
    int option = 0;
    do{
        cout << "What type of employee are you added?";
        cout << "\n\t1 Regular paid employee.\n\t2 Intern.\n\t3 Volunteer\n";
        cin >> option;
    }
    while( option < 1 || option > 3 );
    
    switch ( option ) {
        case 1:
            buildEmployees( data );
            break;
        case 2:
            
            break;
        case 3:
            
            break;
    }
}

/**
 * build the employees and save
 * @param data
 */
void buildEmployees( Data data){
    do {
        Employee E();
        cout << "Enter the employees first name: ";
        //cin 
    }
    while( true );
    
}