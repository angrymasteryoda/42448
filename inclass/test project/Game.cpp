/* 
 * File:   Game.cpp
 * Author: Michael
 *
 * Created on April 24, 2014, 11:26 AM
 */
#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;
Game::Game( ) {
    setPlayers( 0 );
    setIsRunning( false );
    setUseSymbols( true );
}

Game::~Game( ) {
}

void Game::start(){
    setIsRunning( true );
    run();
}

void Game::stop(){
    setIsRunning( false );
}

void Game::run(){
    //ask if the symbols look right
    char confirm = 'n';
//    cout << "Do these card suit symbols look right (y/n)\n";
//    cout << "\u2660" << "\u2663" << "\u2665" << "\u2666" <<endl;
//    cin >> confirm;
    if( confirm != 'y' ){
        setUseSymbols( false );
    }
    //set up the pre loop stuff like deck and dealing cards
    int players = 2;
    while( players <= 1 ){
        cout << "How many players would you like to play war against?\n";
        cin >> players;
    }
    setPlayers( players );
    //have jokers as all powerful card
    bool haveJokers = false;
    confirm = 'n';
    while ( confirm != 'y' && confirm != 'n' ){
        cout << "Include jokers as all powerful cards? (y/n)\n";
        cin >> confirm;
    }
    int deckSize = 52;
    if ( confirm == 'y' ){
        haveJokers = true;
        deckSize += 2;
    }
    
    Deck deck( deckSize );
//    deck.printDeck( 4 );
//    deck.shuffle( 10 );
    
    Player* playerDecks = new Player[players];
    
    for( int i = 0; i < players; i++ ){
        playerDecks[i].hand = new Card[ deck.getSize() / players ];
        playerDecks[i].size = deck.getSize() / players;
    }
    
    int j = 0;
    for( int i = 0; i < deck.getSize(); i++ ){
        playerDecks[ (i % players ) ].hand[j] = deck.deal( i );
        if( i % players == players - 1 && i != 0){
            j++;
        }
    }
    
    cout << "Press enter to deal your card\n";
    cin.ignore();
    cin.get();
    dealPlayers( playerDecks );
    //init game loop
//    while( getIsRunning() ){
//        
//        int x;
//        cout << "x";
//        cin >> x;
//        if( x == 1 ){
//            stop();
//        }
//    }
    //end of game clean up the mess you made
    destroy( playerDecks );
}
void Game::dealPlayers(Player* p){
    //always going to be the first card so doesnt matter
    printPlayerCards( p );
//    cout << "+----+\n";
//    cout << "|1♠  |\n";
//    cout << "|    |\n";
//    cout << "+----+\n";  
}

void Game::printPlayerCards( Player* p ){
    int s = getPlayers();
    //print per line
    //TODO test to make sure the print 10 is spaced right
    bool isTen = false;
    for( int i = 0; i < s; i++ ){
        if( p[i].hand[4].getFace() == 9 ){
            isTen = true;
        }
    }
    for( int i = 0; i < s; i++ ){
        if( p[i].hand[4].getFace() == 9 ){
            isTen = true;
        }
        cout << "+----";
        if( isTen ) {
            cout << "--+\t";
        }
        else{
            cout << "+\t";
        }
    }
    cout << endl;
    for( int i = 0; i < s; i++ ){
        //♠♣♥♦
        cout << "|" << p[i].hand[0].printAbbrev( p[i].hand[4], getUseSymbols() ) << "  ";
        if( isTen ){
           cout << "  |\t";
        }
        else{
            cout << "|\t";
        }
    }
    cout << endl;
    
    for( int i = 0; i < s; i++ ){
        cout << "|    ";
        if( isTen ){
           cout << "  |\t";
        }
        else{
            cout << "|\t";
        }
    }
    cout << endl;
    for( int i = 0; i < s; i++ ){
        cout << "+----";
        if( isTen ){
           cout << "--+\t";
        }
        else{
            cout << "+\t";
        }
    }
    cout << endl;
}

bool Game::getUseSymbols(){
    return useSymbols;
}

void Game::setUseSymbols( bool f ){
    useSymbols = f;
}

int Game::getPlayers(){
    return players;
}

void Game::setPlayers( int p ){
    players = p;
}

bool Game::getIsRunning(){
    return isRunning;
}

void Game::setIsRunning( bool b ){
    isRunning = b;
}

void Game::destroy( Player* p){
    //delete [] p->hand;
    delete [] p;
}

void Game::print( Player p ){
    for( int i = 0; i < p.size; i++ ){
        p.hand[i].printCard( p.hand[i] );
        cout<< endl;
    }
}
