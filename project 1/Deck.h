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
    Deck();
    Deck(const Deck& orig);
    virtual ~Deck();
private:
    Card *deck;
    int deckSize;
    Card getCard();
};

#endif	/* DECK_H */

