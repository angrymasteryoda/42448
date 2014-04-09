/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on April 8, 2014, 9:14 AM
 */

#include <cstdlib>
#include "Deck.h"

using namespace std;

void destroy( Deck d );

int main( int argc, char** argv ) {
    Deck d = new Deck();
    return 0;
}

void destroy( Deck d ){
    d.~Deck();
    delete d;
}

