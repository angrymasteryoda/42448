/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on April 20, 2014, 3:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#include "Card.h"
#include "Deck.h"

using namespace std;

void printCard( Card c );
void destroy( Card* );

int main( int argc, char** argv ) {
    
    Deck deck( 52 );
    Card* cards = deck.getDeck();
    for( int i = 0; i < deck.getSize(); i++ ){
        printCard( cards[i] );
        cout << endl;
    }
    cout << endl;
    return 0;
}

void printCard( Card c ){
    string face;
    switch( c.getFace() ){
        case 0:
            face = "An Ace";
            break;
        case 10:
            face = "Jack";
            break;
        case 11:
            face = "Queen";
            break;
        case 12:
            face = "King";
            break;
        default:
            //convert int to string
            stringstream out;
            out << ( c.getFace() + 1 );
            face = out.str();
            break;
    }
    string suit;
    switch ( c.getSuit() ){
        case 0:
            suit = "Hearts";
            break;
        case 1:
            suit = "Diamonds";
            break;
        case 2:
            suit = "Clubs";
            break;
        case 3:
            suit = "Spades";
            break;
    }
    cout << face + " of " + suit;
}

void Destroy( Card* c ){
    delete [] c;
}
