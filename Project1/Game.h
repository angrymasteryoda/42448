/* 
 * File:   Game.h
 * Author: Michael
 *
 * Created on April 24, 2014, 11:22 AM
 */

#ifndef GAME_H
#define	GAME_H

#include "Player.h"

class Game{
public:
    Game();
    ~Game();
    int getPlayers();
    bool getIsRunning();
    bool getGameOver();
    bool getUseSymbols();
    void setIsRunning( bool );
    void start();
    void stop();
    void run();
private:
    int players;
    int whoWon( Player * );
    Card* copyHand( Player p );
    bool isRunning;
    bool useSymbols;
    bool gameOver;
    void setGameOver( bool );
    void setPlayers(int);
    void setUseSymbols( bool );
    void destroy( Player * );
    void destroy( Card * );
    void print( Player );
    void dealPlayers( Player * );
    void printPlayerCards( Player * );
    void rearrangeHand( Player* p, int winner ); 
    void checkGameOver( Player* p, int winner );
};
#endif	/* GAME_H */
