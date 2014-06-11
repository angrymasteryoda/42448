/* 
 * File:   Prob1Random.h
 * Author: Michael
 *
 * Created on June 10, 2014, 9:47 AM
 */

#ifndef PROB1RANDOM_H
#define	PROB1RANDOM_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Prob1Random {
private:
        unsigned char *set;      //The set of numbers to draw random numbers from
        char  nset;     //The number of variables in the sequence
        int  *freq;     //Frequency of all the random numbers returned
        int   numRand;  //The total number of times the random number function is called
public:
        Prob1Random(const char,const unsigned char *);     //Constructor
        ~Prob1Random();                       //Destructor
        char randFromSet();                   //Returns a random number from the set
        int *getFreq();                 //Returns the frequency histogram
        unsigned char *getSet();                 //Returns the set used
        int getNumRand();               //Gets the number of times randFromSet has
                                                  //been called
};

#endif	/* PROB1RANDOM_H */

