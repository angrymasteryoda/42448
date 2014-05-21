/* 
 * File:   Deck.h
 * Author: rcc
 * Created on April 30, 2014, 1:58 PM
 * Deck Implementation
 */

#include "Deck.h"
#include <cstdlib>
using namespace std;

Deck::Deck( int numCrds ) {
    if ( numCrds <= 0 ) {
        this->nCards = 52;
        card = new Card*[nCards];
    } else {
        this->nCards = numCrds;
        if ( numCrds >= 52 )card = new Card*[52];
        else card = new Card*[numCrds];
    }
    this->nDelt = 0;
    this->index = new int[this->nCards];
    //Check out all the cards
    for ( int i = 0; i < nCards; i++ ) {
        card[i] = new Card( i );
        index[i] = i;
    }
}

int *Deck::deal( int nHand ) {
    int *hand;
    if ( nHand > 0 && nHand <= 5 ) {
        hand = new int[nHand];
        for ( int i = 0; i < nHand; i++ ) {
            hand[i] = index[nDelt++];
            if ( nDelt >= ( nCards - nHand ) ) {
                nDelt = 0;
                shuffle( );
            }
        }
    } else {
        hand = 0;
    }
    return hand;
}

void Deck::shuffle( int nShufl ) {
    int rnd;
    for ( int n = 1; n <= nShufl; n++ ) {
        for ( int i = 0; i < nCards; i++ ) {
            rnd = rand( ) % nCards;
            //Swap
            int temp = index[i];
            index[i] = index[rnd];
            index[rnd] = temp;
        }
    }
}