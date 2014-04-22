/* 
 * File:   Game.h
 * Author: Michael
 *
 * Created on April 21, 2014, 8:14 AM
 */

#ifndef GAME_H
#define	GAME_H


class Game{
private:
    int players;
    bool isRunning;
    void setPlayers(int);
public:
    Game();
    ~Game();
    int getPlayers();
    bool getIsRunning();
    void setIsRunning( bool );
    void start();
    void stp(){};
    void run();
};

#endif	/* GAME_H */
