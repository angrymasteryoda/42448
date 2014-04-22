/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on April 20, 2014, 3:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace std;

void destroy( Card* );
void destroy( Player* );

int main( int argc, char** argv ) {
    //srand( time( NULL ) );
    
    Game me;
    //TODO fix this error main.cpp:25: error: request for member `start' in `game', which is of non-class type `Game ()()'
    me.stp();
    
//    Deck deck( 54 );
    //deck.shuffle( 10 );
//    Card* cards = deck.getDeck();
//    deck.printDeck( 4 );
//    cout << endl;

//    int p = 2;
//    //deal to players
//    Player* players = new Player[p];
//    int j = 0;
//    for( int i = 0; i < p; i++ ){
//        players[i].hand = new Card[ ( deck.getSize() / p ) ];
//    }
//    for( int i = 0; i < deck.getSize(); i++ ){
//        players[i].handcards[i];
//    }
//    
//    destroy( cards );
//    destroy( players );
    return 0;
}

void destroy( Card* c ){
    delete [] c;
}
void destroy( Player* p){
    delete [] p;
}
