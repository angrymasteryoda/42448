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
    Card *getDeck();
private:
    int size;
    Card *deck;
    void setSize( int );
    void fillDeck();
};

#endif	/* DECK_H */

