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

long factorial(long n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }	
}
int main( int argc, char** argv ) {
    srand( time( NULL ) );
    
    Game me;
    me.start();
//    string s = "as";
//    string b = "df";
//    string c = s + b;
//    cout << c;
    //♠♣♥♦
//    cout << "+----+\n";
//    cout << "|1♠  |\n";
//    cout << "|    |\n";
//    cout << "+----+\n";       
    
//    int s;
//    cout << "text\n";
//    cin.get();
//    cout << 'e';
    
//    Deck deck( 54 );
//    deck.shuffle( 10 );
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
    delete [] p->hand;
    delete [] p;
}
