/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 24, 2014, 1:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "ArrayStruct.h"

using namespace std;

void fillArray( ArrayStruct1d *, int );
void destroy ( ArrayStruct1d * );
void destroy2d ( ArrayStruct2d * );
void destroyStruct ( ArrayStruct1d * );
void printArray( ArrayStruct1d *, int );
void printArray2d( ArrayStruct2d * );

ArrayStruct1d *fillArray( int );
ArrayStruct2d *fillArray2d( int, int );

int main(int argc, char** argv) {
    srand( time( NULL ) );
    ArrayStruct1d a1, *ptrA1;
    
    fillArray( &a1, 100 );
    ptrA1 = fillArray( 100 );
    printArray( &a1, 25 );
    printArray( ptrA1, 25 );
    
    cout << "2d array\n";
    ArrayStruct2d *a2;
    a2 = fillArray2d( 10, 9);
    printArray2d( a2 );
    
    destroy( &a1 );
    destroyStruct( ptrA1 );
    destroy2d( a2 );
    return 0;
}

void fillArray( ArrayStruct1d *a, int s){
    // -> because a is a pointer
    a->size = s;
    a->array = new int[s];
    for( int i = 0; i < s; i++){
        a->array[i] = rand() % 90 + 10;
    }
}

void printArray( ArrayStruct1d *a, int p ){
    for( int i = 0; i < a->size; i++ ){
        cout << a->array[i] << " ";
        if ( i % p == ( p -1 ) ) {
            cout << endl;
        }

    }
    cout << endl;
}

void printArray2d( ArrayStruct2d *a ){
    for( int r = 0; r < a->rows; r++ ){
        for( int f = 0; f < a->cols; f++){
            cout << a->array[r][f] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

ArrayStruct2d *fillArray2d( int r, int f ){
    ArrayStruct2d *a = new ArrayStruct2d;
    a->rows = r;
    a->cols = f;
    a->array = new int*[r];
    for( int rows = 0; rows < r; rows++ ){
        a->array[rows] = new int[f];
        
        for( int cols = 0; cols < f; cols++ ){
            a->array[rows][cols] = rand() % 90 + 10;
        }
    }
    
    return a;
}

ArrayStruct1d *fillArray( int s ){
    ArrayStruct1d *a = new ArrayStruct1d;
    a->size = s;
    a->array = new int[s];
    for( int i = 0; i < s; i++){
        a->array[i] = rand() % 90 + 10;
    }
    return a;
}

void destroy( ArrayStruct1d *a ){
    delete [] a->array;
}

void destroyStruct ( ArrayStruct1d *a ){
    delete [] a->array;
    delete a;
}

void destroy2d( ArrayStruct2d *a ){
    for( int r = 0 ; r < a->rows; r++){
        delete [] a->array[r];
    }
    delete [] a->array;
    delete a;
}