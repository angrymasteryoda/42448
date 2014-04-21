/* 
 * File:   Player.h
 * Author: Michael
 *
 * Created on April 21, 2014, 9:25 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Card.h"


struct Player{
    Card* hand;
    int currentCard;
};

#endif	/* PLAYER_H */

