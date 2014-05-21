/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 30, 2014, 12:54 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Our Libraries
#include "Card.h"
#include "Deck.h"

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main( int argc, char** argv ) {
    //Create an array of 52 cards
    int nCards = 52;
    Deck deck( nCards );
    srand( static_cast<unsigned int> ( time( 0 ) ) );
    //Check out all the cards
    int nCrdDlt = 5;
    deck.shuffle( );
    //Deal out multiple hands
    int nHands = 15;
    for ( int plrs = 1; plrs <= nHands; plrs++ ) {
        int *hand = deck.deal( nCrdDlt );
        cout << endl << "Hand " << plrs << endl;
        for ( int i = 0; i < nCrdDlt; i++ ) {
            Card card( hand[i] );
            cout << card.name( ) << card.suit( );
            cout << " " << static_cast<int> ( card.value( ) );
            cout << " " << static_cast<int> ( card.getNumber( ) ) << endl;
        }
        delete []hand;
    }
    //Exit stage right
    cout << "Press a number key" << endl;
    int dum;
    cin >> dum;
    return 0;
}

