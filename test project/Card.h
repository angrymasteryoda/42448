/* 
 * File:   Card.h
 * Author: Michael
 *
 * Created on April 20, 2014, 3:13 PM
 */
#ifndef CARD_H
#define	CARD_H

#include <string>
using namespace std;
class Card{
public:
    Card();
    Card( int, int );
    ~Card();
    int getSuit();
    int getFace();
    int getGameVal();
    string printAbbrev( Card, bool );
    void setSuit( int );
    void setFace( int );
    void printCard( Card );
    
private:
    int suit;
    int face;
};



#endif	/* CARD_H */

