/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on April 8, 2014, 9:14 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Deck.h"
#include "Card.h"

using namespace std;

void printCard( Card card );
void destroy( Deck d );

int main( int argc, char** argv ) {
    //random seed
    srand( time( NULL ) );
    
    Deck d( 52 );
    
    d.printDeck( 10 );
    
    Card card = d.getRandomCard();
    
    printCard( card );
    
    return 0;
}
void printCard ( Card card ){
    int i = 0;
    while ( card.face[i] != '\0' ){
        cout << card.face[i++];
    }
}

void destroy( Deck d ){
    d.~Deck();
}

