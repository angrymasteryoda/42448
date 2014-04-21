/* 
 * File:   Deck.h
 * Author: Michael
 *
 * Created on April 20, 2014, 3:31 PM
 */

#ifndef DECK_H
#define	DECK_H

#include "Card.h"

class Deck {
public:
    Deck( int );
    ~Deck();
    int getSize();
    int getCurrentCard();
    Card *getDeck();
    Card deal();
    void setCurrentCard( int );
    void shuffle();
    void shuffle( int );
    void printDeck( int );
private:
    int size;
    int currentCard;
    Card *deck;
    void setSize( int );
    void fillDeck();
};

#endif	/* DECK_H */

