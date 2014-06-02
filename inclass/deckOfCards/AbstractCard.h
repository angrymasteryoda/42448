/* 
 * File:   AbstractCard.h
 * Author: Michael
 *
 * Created on May 21, 2014, 12:59 PM
 */

#ifndef ABSTRACTCARD_H
#define	ABSTRACTCARD_H

using namespace std;

class AbstactCard {
    virtual char suit() = 0;
    virtual char name() = 0;
    virtual char value() = 0;
};



#endif	/* ABSTRACTCARD_H */

