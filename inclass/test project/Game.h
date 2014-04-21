/* 
 * File:   Game.h
 * Author: Michael
 *
 * Created on April 21, 2014, 8:14 AM
 */

#ifndef GAME_H
#define	GAME_H

class Game {
public:
    Game();
    ~Game();
    int getPlayers();
    bool getIsRunning();
    void setIsRunning( bool );
    void start();
    void stop();
    void run();
private:
    int players;
    bool isRunning;
    void setPlayers( int );
};

#endif	/* GAME_H */

