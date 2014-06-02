/* 
 * File:   ChildCard.h
 * Author: Michael
 *
 * Created on May 21, 2014, 1:10 PM
 */

#ifndef CHILDCARD_H
#define	CHILDCARD_H

#include <string>
#include "Card.h"

using namespace std;

class ChildCard:public Card {
    public:
        ChildCard(int num):Card( num ){}
        void setFN( string fn ){
            fileName = fn;
        }
        string getFN(){
             return fileName;
        }
    private:
        string fileName;
};

#endif	/* CHILDCARD_H */

