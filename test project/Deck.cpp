/* 
 * File:   Deck.cpp
 * Author: Michael
 * 
 * Created on April 20, 2014, 3:31 PM
 */
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <sys/unistd.h>

#include "Deck.h"
#include "Card.h"

using namespace std;

/**
 * constructor
 * @param size size of the deck
 */
Deck::Deck( int size ) {
    setCurrentCard( 0 );
    setSize( size );
    fillDeck();
}

Deck::~Deck( ) {
    delete [] deck;
}

/**
 * fill the deck with default card suits and based on a ace to king
 */
void Deck::fillDeck(){
    int size = getSize();
    deck = new Card[ size ];
    if( getSize() % 4 != 0 ){
        //assume the extra cards are jokers
        size -= getSize() % 4;
        
        for( int i = size; i < getSize(); i++ ){
            deck[i].setFace( 13 );
            deck[i].setSuit( 4 );
        }
    }
        
    
    for( int i = 0; i < size; i++ ){
        deck[i].setFace( i % 13 );
        deck[i].setSuit( i / 13 );
    }
}

/**
 * shuffle the deck 6 times
 */
void Deck::shuffle(){
    shuffle( 6 );
}

/**
 * Shuffle the deck x times
 * @param times
 */
void Deck::shuffle( int times ){
    setCurrentCard( 0 );
    for( int x = 0; x < times; x++ ){
        for( int y = 0; y < getSize(); y++ ){
            int second = rand() % getSize();
            Card temp = deck[y];
            deck[y] = deck[second];
            deck[second] = temp;
        }
    }
}

/**
 * deal a single card
 * @return Card
 */
Card Deck::deal(){
    if ( currentCard < getSize() ){
        return deck[currentCard++];
    }   
}
Card Deck::deal( int i ){
    return deck[i];
}

/**
 * prints out the entire deck in plain text
 * @param p cards per line
 */
void Deck::printDeck( int p ){
    for( int i = 0; i < getSize(); i++ ){
        deck->printCard( deck[i] );
        cout << ", ";
        if( i % p  == p - 1 ){
            cout << endl;
        }
    }
}

//getters setters
int Deck::getSize(){
    return size;
}

void Deck::setSize( int s ){
    size = s;
}

int Deck::getCurrentCard(){
    return currentCard;
}

void Deck::setCurrentCard( int n ){
    currentCard = n;
}

Card* Deck::getDeck(){
    return deck;
}

