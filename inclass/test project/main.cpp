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

using namespace std;

void destroy( Card* );

int main( int argc, char** argv ) {
    srand( time( NULL ) );
    
    Game game();
    //TODO fix this error main.cpp:25: error: request for member `start' in `game', which is of non-class type `Game ()()'
    //game.start();
    
    Deck deck( 54 );
    //deck.shuffle( 10 );
    Card* cards = deck.getDeck();
//    deck.printDeck( 4 );
//    cout << endl;

    int players = 2;
    //deal to players
    for( int i = 0; i < deck.getSize(); i++ ){
        
    }
    
    destroy( cards );
    return 0;
}

void destroy( Card* c ){
    delete [] c;
}
