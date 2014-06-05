/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on June 4, 2014, 1:00 PM
 */

#include <cstdlib>
#include "SimpleVector.h"

using namespace std;

int main( int argc, char** argv ) {
    
    SimpleVector<int> vec(5);
    
    for( int i = 0; i < vec.size(); i++ ){
        vec[i] = i;
    }
    
    //test the push back
    vec.push_back( 20 );
    
    for( int i = 0; i < vec.size(); i++ ){
        cout << vec.getElementAt( i );
    }
    return 0;
}

//    int newAllocate;
//    int newSize = this->size() + 1;
//    if( this->allocatedSize < newSize ) { // if the new size is bigger than current double it
//        newAllocate = this->size() * 2;
//    } else { // else we have enough space made just need to use it
//        newAllocate = this->size();
//    }
//    
//    SimpleVector<T> newV( newAllocate );
//    
//    //set the size on the new array to the last val
//    newV.arraySize = newSize;
//    
//    for( int i = 0; i < this->size(); i++ ){
//        newV[i] = this->getElementAt( i );
//    }
//    
//    newV[ this->size() ] = val;
//    
//    //delete the old vec
//    if ( this->arraySize > 0){
//      delete [] this->aptr;
//    }
//    
//    //set the old vec to new vec
//    this->arraySize = newV.arraySize;
//    this->allocatedSize = newV.allocatedSize;
//    this->aptr = new T[newV.allocatedSize];
//    for ( int i = 0; i < this->arraySize; i++ ){
//        this[i] = newV.getElementAt( i );
//    }