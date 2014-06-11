/* 
 * File:   Prob1Random.cpp
 * Author: Michael
 *
 * Created on June 10, 2014, 9:48 AM
 */

#include <algorithm>

#include "Prob1Random.h"

using namespace std;


Prob1Random::Prob1Random( const char size, const unsigned char *arry ){
    nset = size;
    set = new unsigned char[ int(size) ];
    numRand = 0;
    freq = new int[ int(size) ];
    for( int i = 0; i < int(size); i++ ){
        set[i] = arry[i];
        freq[i] = 0;
    }
}     

Prob1Random::~Prob1Random(){
    delete [] set;
    delete [] freq;
}                      

char Prob1Random::randFromSet(){
    numRand++;

    char a = rand() % nset;
    
    for ( int i = 0; i < nset; i++ ){
        if ( int(a) == i ){
            freq[i]++;
            break;
        }
    }
    
}                   
int * Prob1Random::getFreq(){
    return freq;
}              
unsigned char * Prob1Random::getSet() {
    return set;
}               
int Prob1Random::getNumRand() {
    return numRand;
}
