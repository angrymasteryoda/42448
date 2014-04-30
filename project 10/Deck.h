/* 
 * File:   Deck.h
 * Author: Michael
 *
 * Created on April 8, 2014, 9:17 AM
 */

#ifndef DECK_H
#define	DECK_H

#include "Card.h"

class Deck{
public:
    Deck( const int );
    ~Deck();
    int getDeckSize();
    Card getRandomCard();
    void printDeck( int );
private:
    Card *deck;
    int deckSize;
    void setDeckSize( int );
    void fillDeck();
};

#endif	/* DECK_H */

