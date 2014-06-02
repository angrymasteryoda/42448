/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 12:46 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void menu();
void build();

int main( int argc, char** argv ) {
    char option;
    
    menu();
    do {
        cout << "enter a option from the menu\n";
        option = cin.get();
        
        switch( option ){
            case 'b':
                build();
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
 */
void build(){
    int option = 0;
    do{
        cout << "What type of employee are you added?";
        cout << "\n\t1 Regular paid employee.\n\t2 Intern.\n\t3 Volunteer\n";
        cin >> option;
    }
    while( option < 1 || option > 3);
    cout << option;
    
}
