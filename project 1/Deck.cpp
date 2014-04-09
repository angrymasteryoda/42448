/* 
 * File:   Deck.cpp
 * Author: Michael
 * 
 * Created on April 8, 2014, 9:17 AM
 */

#include "Deck.h"
#include "Card.h"

Deck::Deck( ) {
    deck = new Card[52];
    for( int i = 0; i < deckSize; i++){
        deck[i].face = i % 13;
        deck[i].suit = i / 13;
    }
}

Card Deck::getCard(){
    
}

//no clue what these are yet
Deck::Deck( const Deck& orig ) {
}

//trash can function?
Deck::~Deck( ) {
    delete [] Deck::deck;
}

