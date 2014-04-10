/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on April 9, 2014, 1:28 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Array1D.h"
using namespace std;

int main( int argc, char** argv ) {
    srand( time( NULL ) );
    
    Array1D a1d( 100 ), a2(50);
    a1d.printArray( 10 );
    a2.printArray( 10 );
    return 0;
}

