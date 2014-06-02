/* 
 * File:   Card.h
 * Author: Dr. Mark E. Lehr
 * Created on April 30, 2014, 12:56 PM
 * Card Specification
 */

#ifndef CARD_H
#define	CARD_H

#include "AbstractCard.h"

using namespace std;

class Card:public AbstactCard{
private:
    char number;
public:
    Card(int);
    char suit();
    char name();
    char value();
    char getNumber() {
        return number;
    }
};


#endif	/* CARD_H */

