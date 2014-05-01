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
    srand( time( NULL ) );
    lol
    char cont;
    do{
        Game me;
        me.start();
        cout << "Want to play again (y or n)\n";
        cin >> cont;
    }
    while( cont != 'n' );
    
    return 0;
}

void destroy( Card* c ){
    delete [] c;
}
void destroy( Player* p){
    delete [] p->hand;
    delete [] p;
}
