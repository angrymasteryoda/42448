/* 
 * File:   Game.cpp
 * Author: Michael
 * 
 * Created on April 21, 2014, 8:14 AM
 */
#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Card.h"
#include "Deck.h"

using namespace std;

Game::Game( ) {
    setPlayers( 0 );
    setIsRunning( false );
}

Game::~Game( ) {
}

void Game::start(){
    setIsRunning( true );
    //run();
}

void Game::stop(){
    setIsRunning( false );
}

void Game::run(){
    //set up the pre loop stuff like deck and dealing cards
    int players = 0;
    while( players <= 1 ){
        cout << "How many players would you like to play war against?\n";
        cin >> players;
    }
    //have jokers as all powerful card
    bool haveJokers = false;
    char confirm;
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
    
    //init game loop
    while( getIsRunning() ){
        
    }
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

