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

/**
 * constructor
 * @param face
 * @param suit
 */
Card::Card( int f, int s ){
    setFace( f );
    setSuit( s );
}

/**
 * constructor defaulted to 0's
 */
Card::Card(){
    setFace( 0 );
    setSuit( 0 );
}

Card::~Card(){
    
}

/**
 * print out a single card in plain text
 * @param card
 */
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
        cout << face << " of " << suit;
    }
}
/**
 * prints out the abbrevation of the card eg 10♠ or 10H
 * @param c
 * @param sym can print symbols
 * @return 
 */
string Card::printAbbrev( Card c, bool sym ){
    string face;
    bool isJoker = false;
    switch( c.getFace() ){
        case 0:
            face = "A";
            break;
        case 10:
            face = "J";
            break;
        case 11:
            face = "Q";
            break;
        case 12:
            face = "K";
            break;
        case 13:
            isJoker = true;
            face = "JO";
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
            suit = sym ? "\u2665" : "H";
            break;
        case 1:
            suit = sym ? "\u2666" : "D";
            break;
        case 2:
            suit = sym ? "\u2663" : "C";
            break;
        case 3:
            suit = sym ? "\u2660" : "S";
            break;
        default:
            //no suit like jokers? or other odd cards in games
            suit = "blank?";
            break;
    }
    if( isJoker ){
        return face;
    }
    else{
        return face + suit;
    }
}

/**
 * gets the game value of a card not face value
 * @return Game value
 */
int Card::getGameVal(){
    if ( getFace() == 0) {
        return 13;
    }
    else if( getFace() == 13 ){
        return 14;
    }
    else{
        return getFace();
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
