/* 
 * File:   Deck.h
 * Author: Michael
 *
 * Created on April 8, 2014, 9:17 AM
 */
#include "Card.h"
#ifndef DECK_H
#define	DECK_H

class Deck {
public:
    Deck( int = 52 );
    Deck(const Deck& orig);
    virtual ~Deck();
    int getDeckSize();
private:
    Card *deck;
    int deckSize;
    void setDeckSize( int );
};

#endif	/* DECK_H */

