/* 
 * File:   Prob3Table.h
 * Author: Michael
 *
 * Created on June 11, 2014, 3:46 PM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H

#include <fstream>
#include <iostream>

using namespace std;

template<class T>
class Prob3Table {
protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
public:
    Prob3Table(char [],int,int);               //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template<class T>
Prob3Table<T>::Prob3Table(char filename[], int ro, int co) {
    if( ro > 0 ){
        rows = ro;
    }
    else {
        rows = 0;
    }
    
    if( co > 0 ) {
        cols = co;
    }
    else {
        cols = 0;
    }
    
    T cursor;
    table=new T[ rows * cols ];
    ifstream file( filename );
    for( int i = 0; i < rows; i++ ){
        for( int j = 0; j < cols; j++ ){
            file >> cursor;
            table[ i * cols + j ] = cursor;
        }
    }
    file.close();
}

/* int x[width][height];
 * x[a][b] = 2;
 * int x[width*height];
 * x[a*height+b] = 2;
 */

template <class T>
void Prob3Table<T>::calcTable(void) {
    T sum = 0;;
    colSum = new T[cols];
    rowSum = new T[rows];
    //row sums
    for( int i = 0; i < rows; i++ ){
        rowSum[i] = 0;
        for( int j = 0; j < cols; j++ ){
            sum += table[ i * cols + j ];
        }
        rowSum[i] = sum;
        sum = 0;
    }
    
    //col sums
    for( int i = 0; i < cols; i++ ){
        colSum[i] = 0;
        for( int j = 0; j < rows; j++ ){
            sum += table[ j * cols + i ];
        }
        colSum[i] = sum;
        sum = 0;
    }
    
    //total all
    grandTotal = 0;
    for( int i = 0; i < cols; i++ ){
        grandTotal += colSum[i];
    }
    
}
#endif	/* PROB3TABLE_H */

