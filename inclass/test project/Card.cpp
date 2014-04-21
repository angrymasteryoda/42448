/* 
 * File:   Card.cpp
 * Author: Michael
 *
 * Created on April 20, 2014, 3:17 PM
 */

#include <cstdlib>

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
