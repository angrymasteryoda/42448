/* 
 * File:   Deck.cpp
 * Author: Michael
 * 
 * Created on April 8, 2014, 9:17 AM
 */

#include "Deck.h"
#include "Card.h"

Deck::Deck( const int deckSize ) {
    setDeckSize( deckSize );
    deck = new Card[ getDeckSize() ];
    for( int i = 0; i < deckSize; i++){
        deck[i].face = i % 13;
        deck[i].suit = i / 13;
    }
}

//no clue what these are yet
Deck::Deck( const Deck& orig ) {
}

//trash can function?
Deck::~Deck( ) {
    delete [] Deck::deck;
}

void Deck::setDeckSize( int s ){
    Deck::deckSize = s;
}

int Deck::getDeckSize(){
    return Deck::deckSize;
}
