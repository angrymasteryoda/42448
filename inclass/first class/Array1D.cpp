/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on April 9, 2014, 1:30 PM
 */
#include <cstdlib>
#include <iostream>

#include "Array1D.h"

using namespace std;

Array1D::Array1D( int size ){
    setSize( size );
    fillArray();
}

void Array1D::setSize( int s ) {
    if( s <= 2 ){
        size = 2;
    }
    else{
        size = s;
    }
}

void Array1D::fillArray(){
    data = new int[size];
    for( int i = 0; i < size; i++ ){
        data[i] = rand( ) % 90 + 10;
    }
}

void Array1D::printArray( int per ) {
    for( int i = 0; i < size; i++ ){
        cout << data[i] << ", ";
        if( i % per == per - 1 ){
            cout << endl;
        }
    }
}

