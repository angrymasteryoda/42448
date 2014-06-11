/* 
 * File:   Prob2Sort.h
 * Author: Michael
 *
 * Created on June 10, 2014, 10:38 AM
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H

#include <cstdlib> 

using namespace std;

template<class T>
class Prob2Sort {
private:
        int *index;                                 //Index that is utilized in the sort
public:
        Prob2Sort(){index=NULL;};                   //Constructor
        ~Prob2Sort(){delete []index;};              //Destructor
        T * sortArray(const T*,int,bool);           //Sorts a single column array
        T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 


#endif	/* PROB2SORT_H */

