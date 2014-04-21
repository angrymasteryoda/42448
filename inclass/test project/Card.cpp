/* 
 * File:   Card.cpp
 * Author: Michael
 *
 * Created on April 20, 2014, 3:17 PM
 */

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

#include "Card.h"

using namespace std;

Card::Card( int f, int s ){
    setFace( f );
    setSuit( s );
}

Card::Card(){
    setFace( 0 );
    setSuit( 0 );
}

Card::~Card(){
    
}

void Card::printCard( Card c ){
    string face;
    bool isJoker = false;
    switch( c.getFace() ){
        case 0:
            face = "An Ace";
            break;
        case 10:
            face = "Jack";
            break;
        case 11:
            face = "Queen";
            break;
        case 12:
            face = "King";
            break;
        case 13:
            isJoker = true;
            face = "Joker";
            break;
        default:
            //convert int to string
            stringstream out;
            out << ( c.getFace() + 1 );
            face = out.str();
            break;
    }
    string suit;
    switch ( c.getSuit() ){
        case 0:
            suit = "Hearts";
            break;
        case 1:
            suit = "Diamonds";
            break;
        case 2:
            suit = "Clubs";
            break;
        case 3:
            suit = "Spades";
            break;
        default:
            //no suit like jokers? or other odd cards in games
            suit = "blank?";
            break;
    }
    if( isJoker ){
        cout << face;
    }
    else{
        cout << face + " of " + suit;
    }
}

int Card::getFace(){
    return face;
}

int Card::getSuit(){
    return suit;
}

void Card::setFace( int f ){
    face = f;
}

void Card::setSuit(int s){
    suit = s;
}
