///* 
// * File:   Prob3Table.h
// * Author: Michael
// *
// * Created on June 11, 2014, 3:46 PM
// */
//
//#ifndef PROB3TABLE_H
//#define	PROB3TABLE_H
//
//#include <fstream>
//#include <iostream>
//
//using namespace std;
//
//template<class T>
//class Prob3Table {
//protected:
//    int rows;                                 //Number of rows in the table
//    int cols;                                 //Number of cols in the table
//    T *rowSum;                                //RowSum array
//    T *colSum;                                //ColSum array
//    T *table;                                 //Table array
//    T grandTotal;                             //Grand total
//    void calcTable(void);                     //Calculate all the sums
//public:
//    Prob3Table(char [],int,int);               //Constructor then Destructor
//    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
//    const T *getTable(void){return table;};
//    const T *getRowSum(void){return rowSum;};
//    const T *getColSum(void){return colSum;};
//    T getGrandTotal(void){return grandTotal;};
//};
//
//
//
//#endif	/* PROB3TABLE_H */
//
