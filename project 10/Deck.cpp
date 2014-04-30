/* 
 * File:   Deck.cpp
 * Author: Michael
 * 
 * Created on April 8, 2014, 9:17 AM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck( const int deckSize ) {
    setDeckSize( deckSize );
    fillDeck();
}

//trash can function
Deck::~Deck( ) {
    delete [] Deck::deck;
}

void Deck::setDeckSize( int s ){
    Deck::deckSize = s;
}

int Deck::getDeckSize(){
    return Deck::deckSize;
}

Card Deck::getRandomCard(){
    int i = rand() % getDeckSize();
    cout << i << endl;
    return deck[i];
}

void Deck::fillDeck(){
    char faceNames[13][6] = {"Ace", "2", "3","4","5","6","7","8","9","10","Jack","Queen","King"};
    deck = new Card[ getDeckSize() ];
    for( int i = 0; i < deckSize; i++){
        deck[i].faceVal = ( i % 13 ) + 1;
        deck[i].suit = i / 13;
        deck[i].face = faceNames[ deck[i].faceVal ];
    }
}

void Deck::printDeck( int p ){
    for( int i = 0; i < getDeckSize(); i++ ){
        cout << deck[i].faceVal << ", ";
        if ( i % p == p - 1 ){
            cout << endl;
        }
    }
}
