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
private:
    int players;
    int whoWon( Player * );
    bool isRunning;
    bool useSymbols;
    void setPlayers(int);
    void setUseSymbols( bool );
    void destroy( Player * );
    void print( Player );
    void dealPlayers( Player * );
    void printPlayerCards( Player * );
    
public:
    Game();
    ~Game();
    int getPlayers();
    bool getIsRunning();
    bool getUseSymbols();
    void setIsRunning( bool );
    void start();
    void stop();
    void run();
};
#endif	/* GAME_H */
