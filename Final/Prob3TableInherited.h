/* 
 * File:   Prob3TableInherited.h
 * Author: Michael
 *
 * Created on June 11, 2014, 3:54 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define	PROB3TABLEINHERITED_H

#include "Prob3Table.h"

using namespace std;

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
protected:
    T *augTable;                                  //Augmented Table with sums
public:
    Prob3TableInherited(char [], int ,int );          //Constructor
    ~Prob3TableInherited(){delete [] augTable;};  //Destructor
    const T *getAugTable(void){return augTable;}; 
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char filename[], int ro, int co) : Prob3Table<T>( filename, ro, co ) {
    this->calcTable();
    augTable = new T[ (ro + 1) * (co + 1) ];
    for( int r = 0; r < ro; r++ ){
        for( int c = 0; c < co; c++ ){
            augTable[ r * ( co + 1) + c] = this->table[ r * co + c ];
        }
    }
    //fill the rows
    for( int r = 0; r < ro; r++ ){
        int index = r * ( co + 1 )  + co;
        augTable[ r * ( co + 1 )  + co ] = this->rowSum[r];
    }
    //fill the cols
    for( int c = 0; c < co; c++ ){
        augTable[ ro * (co + 1 ) + c ] = this->colSum[c];
    }
    
    augTable[ (ro + 1) * (co + 1) - 1 ] = this->grandTotal;
}

/*
 
      0     1     2     3     4     5     6
0   100   101   102   103   104   105   0
1   106   107   108   109   110   111   0
2   112   113   114   115   116   117   0
3   118   119   120   121   122   123   0
4   124   125   126   127   128   129   0
5   0     0     0     0     0     0     0

non aug
    0     1     2     3     4     5  
0   000   001   002   003   004   005
1   007   008   009   010   011   012
2   014   015   016   017   018   019
3   021   022   023   024   025   026
4   028   029   030   031   032   033
 
augment table
    0     1     2     3     4     5     6
0   000   001   002   003   004   005   006
1   007   008   009   010   011   012   013
2   014   015   016   017   018   019   020
3   021   022   023   024   025   026   027
4   028   029   030   031   032   033   034
5   035   036   037   038   039   040   041

0 * 7 + 6 = 6
1 * 7 + 6 = 13
2 * 7 + 6 = 20
r * co + co
0 * 6 + 6 = 6
1 * 6 + 6 = 12

ro * co + c
5 * 6 + 0 = 30
5 * 6 + 1 = 31
 */

#endif	/* PROB3TABLEINHERITED_H */

