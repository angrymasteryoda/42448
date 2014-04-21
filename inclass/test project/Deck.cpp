/* 
 * File:   Deck.cpp
 * Author: Michael
 * 
 * Created on April 20, 2014, 3:31 PM
 */

#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck( int size ) {
    setSize( size );
    fillDeck();
}

Deck::~Deck( ) {
    delete [] deck;
}

void Deck::fillDeck(){
    deck = new Card[ getSize() ];
    for( int i = 0; i < getSize(); i++ ){
        deck[i].setFace( i % 13 );
        deck[i].setSuit( i / 13 );
    }
}

int Deck::getSize(){
    return size;
}

void Deck::setSize( int s ){
    size = s;
}

Card* Deck::getDeck(){
    return deck;
}

