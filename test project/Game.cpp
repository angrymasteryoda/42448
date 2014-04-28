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
    setGameOver( false );
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
    cout << "Do these card suit symbols look right (y/n)\n";
    cout << "\u2660" << "\u2663" << "\u2665" << "\u2666" <<endl;
    cin >> confirm;
    if( confirm != 'y' ){
        setUseSymbols( false );
    }
    //set up the pre loop stuff like deck and dealing cards
    //x players will be done if time allows for now 2 will be it
    int players = 2;
    while( players <= 1 ){
        cout << "How many players would you like to play war against?\n";
        cin >> players;
    }
    setPlayers( players );
    //have jokers as all powerful card
    bool haveJokers = false;
    confirm = 'q';
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
    deck.shuffle( 10 );
    
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
    
//    cout << "Press enter to deal your card\n";
    cin.ignore();
//    cin.get();
//    dealPlayers( playerDecks );
    //init game loop
    while( getIsRunning() ){
        cout << "Press enter to deal your card\n";
//        cin.get();
        dealPlayers( playerDecks );
        if( getGameOver() ){
            stop();
        }
    }
    //end of game clean up the mess you made
    destroy( playerDecks );
}

void Game::checkGameOver( Player* p, int winner ){
    //check if any players only have 1 card and see if they lost
    for( int i = 0; i < getPlayers(); i++){
        if( p[i].size == 1 ){
            if ( winner != i ){
                setGameOver( true );
                if ( winner == 0 ){
                    cout << "You won the game!\n";
                }
                else{
                    cout << "You lost! Player " << winner << " has won the game\n";
                }
                stop();
            }
        }
    }
}

void Game::dealPlayers(Player* p){
    //always going to be the first card so doesnt matter
    printPlayerCards( p );
    
    int winner = whoWon( p );
    if ( winner == 0 ){
        cout << "you won!\n";
    }
    else{
        cout << "you lost! Player " << winner << " has won\n";
    }
    checkGameOver( p, winner );
    if ( !getGameOver() ) {
        rearrangeHand( p, winner );
    }
    for( int i = 0; i < getPlayers(); i++ ){
        cout << p[i].size << "\t";
    }
    cout << endl;
    
    //todo take the others cards add them to the end of the winners deck
    //todo war aspect
}

void Game::rearrangeHand( Player* p, int winner ){
    //todo add this if time allows
    bool war = false;
    //make a copy of the players array
    //destroy it then recreate with different length and put the new cards for the winner
    //and remove the card from the loser
    Player* copy = new Player[ getPlayers() ];
    for ( int i = 0; i < getPlayers(); i++ ){
        copy[i].size = p[i].size;
        copy[i].currentCard = p[i].currentCard;
    }
    
    //add cards to winner
    //skip the first card
    //if not a war
    if( !war ){
        copy[ winner ].size += ( getPlayers() - 1 );
        copy[winner].hand = new Card[ copy[winner].size];
        //volatile variable;
        Card* tempDeck = copyHand( p[winner] );
        for( int i = 0; i < p[winner].size - 1; i++ ){
            copy[winner].hand[i] = tempDeck[ (i + 1) ];
        }
        //add the winner card to his deck
        copy[winner].hand[ p[winner].size - 1 ] = tempDeck[0];
        destroy( tempDeck );
        //add the loser cards
        int j = p[winner].size;
        for ( int i = 0; i < getPlayers(); i++ ){
            if ( i != winner ){
                copy[winner].hand[j++] = p[i].hand[0];
            }
        }
        
        //time to take care of the losers
        //remove their first card and resize
        for ( int i = 0; i < getPlayers(); i++ ){
            if ( i != winner ){
                tempDeck = copyHand( p[i] );
                //resize
                copy[i].size--;
                copy[i].hand = new Card[ copy[i].size ];
                //copy
                for( int j = 0; j < p[i].size - 1; j++ ){
                    copy[i].hand[j] = tempDeck[ ( j + 1) ];
                }
                destroy( tempDeck );
            }
        }
        
        //copy should now be the new set up for players
        //destroy players and set copy to players
        //testing to make sure
//        print( p[winner] );
//        cout<< "new win\n";
//        print( copy[winner] );
//        cout<<"lose\n";
//        print( p[1]);
//        cout<<"new lose\n";
//        print( copy[1] );
        for( int i = 0; i < getPlayers(); i++ ){
            p[i].size = copy[i].size;
            p[i].currentCard = copy[i].currentCard;
            destroy( p[i].hand );
            p[i].hand = copyHand( copy[i] );
        }
    }
    destroy( copy );
}

Card* Game::copyHand( Player p ){
    Card* c = new Card[ p.size ];
    for( int i = 0; i < p.size; i++ ){
        c[i] = p.hand[i];
    }
    return c;
}

void Game::printPlayerCards( Player* p ){
    int s = getPlayers();
    //print per line
    //TODO test to make sure the print 10 is spaced right
    bool isTen = false;
    for( int i = 0; i < s; i++ ){
        if( p[i].hand[0].getFace() == 9 ){
            isTen = true;
        }
    }
    for( int i = 0; i < s; i++ ){
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
        cout << "|" << p[i].hand[0].printAbbrev( p[i].hand[0], getUseSymbols() ) << "  ";
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
    for( int i = 0; i < s; i++ ){
        if ( i == 0 ) {
            if( isTen ){
                cout << "you\t\t";
            }
            else{
                cout << "you\t";
            }
            
        }
        else{
            cout << "ai" << i << "\t";
        }
    }
    cout << endl;
    
}

int Game::whoWon(Player* p ){
    int face = 0;
    int winner;
    for( int i = 0; i < getPlayers(); i++ ){
        if( face < p[i].hand[0].getGameVal() ){
            face = p[i].hand[0].getGameVal();
            winner = i;
        }
    }
    return winner;
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

void Game::setGameOver( bool b ){
    gameOver = b;
}

bool Game::getGameOver(){
    return gameOver;
}

void Game::destroy( Player* p){
    for( int i = 0; i < getPlayers(); i++){
        delete [] p[i].hand;
    }
    delete [] p;
}

void Game::destroy( Card* p){
    delete [] p;
}

void Game::print( Player p ){
    for( int i = 0; i < p.size; i++ ){
        p.hand[i].printCard( p.hand[i] );
        cout<< endl;
    }
}
