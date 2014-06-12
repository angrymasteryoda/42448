/* 
 * File:   Prob2Sort.h
 * Author: Michael
 *
 * Created on June 10, 2014, 10:38 AM
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H

#include <cstdlib> 
#include <iostream>

using namespace std;

template<class T>
class Prob2Sort {
private:
        int *index;                                 //Index that is utilized in the sort
public:
        Prob2Sort(){index=NULL;};                   //Constructor
        ~Prob2Sort(){delete []index;};              //Destructor
        T * sortArray(const T*,int,bool);           //Sorts a single column array
        T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

template<class T> 
T * Prob2Sort<T>::sortArray( const T* arr, int rows, int cols, int column, bool isAscend){
    column--;
    T temp;
    bool swap;
    index = new int[rows];
    //copy it
    T *newArr = new T[ rows * cols ];
    for( int i = 0; i < rows; i++ ){
        for( int j = 0; j < cols; j++ ){
            newArr[ j + ( cols * i) ] = arr[ j + ( cols * i) ];
        }
    }
    //get last char num
    for ( int i = 0; i < rows; i++ ){
        index[i] = newArr[ column + ( cols * i ) ];
    }
    
    do{
        swap = false;
        for( int i = 0; i < rows - 1; i++ ){
            //ascend
            if( index[i] > index[ i + 1 ] && isAscend) {
                swap = true;
                T temp = index[i];
                index[i] = index[ i + 1 ];
                index[ i + 1 ] = temp;
                for(int j = 0; j < cols - 1; j++) {
                    T ntemp = newArr[ j + ( 17 * i )];
                    newArr[ j + ( 17 * i ) ] = newArr[ j + ( 17 * ( i + 1 ) ) ];
                    newArr[ j + ( 17 * ( i + 1) ) ] = ntemp;
                }
            }
            //descend
            else if ( index[i] > index[ i + 1 ] && !isAscend) {
                swap = true;
                T temp = index[i + 1];
                index[i + 1] = index[i];
                index[ i ] = temp;
                for(int j = 0; j < cols - 1; j++) {
                    T ntemp = newArr[ j + ( 17 * ( i + 1 ) ) ];
                    newArr[ j + ( 17 * ( i + 1 ) ) ] = newArr[ j + ( 17 * i ) ];
                    newArr[ j + ( 17 * i ) ] = ntemp;
                }
            }
        }
    }
    while( swap != false );

    return newArr;
    
}

#endif	/* PROB2SORT_H */

