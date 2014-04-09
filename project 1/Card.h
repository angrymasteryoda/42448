/* 
 * File:   Card.h
 * Author: Michael
 *
 * Created on April 8, 2014, 9:17 AM
 */

#ifndef CARD_H
#define	CARD_H

struct Card {
    int face;
    int suit;
    
    Card::Card( int f, int s){
        face = f;
        suit = s;
    }
};

#endif	/* CARD_H */

