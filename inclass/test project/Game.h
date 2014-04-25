/* 
 * File:   Game.h
 * Author: Michael
 *
 * Created on April 24, 2014, 11:22 AM
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
    void stop();
    void run();
};
#endif	/* GAME_H */
