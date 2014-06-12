///* 
// * File:   Prob3Table.cpp
// * Author: Michael
// *
// * Created on June 11, 2014, 6:29 PM
// */
//
//#include "Prob3Table.h"
//
//using namespace std;
//
//template<class T>
//Prob3Table<T>::Prob3Table(char file[], int rows, int cols) {
//    if( rows > 0 ){
//        this->rows = rows;
//    }
//    else {
//        this->rows = 0;
//    }
//    if( cols > 0 ){
//        this->cols = cols;
//    }
//    else{
//        this->cols = 0;
//    }
//    T cur;
//    ifstream ifile( file );
//    table=new T[rows*cols];
//    for ( int i = 0; i < rows; i++ ) {
//        for ( int j = 0; j < cols; j++ ){
//            ifile >> cur;
//            table[i * cols + j] = cur;
//        }
//    }
//    ifile.close();
//}
//
//template <class T>
//void Prob3Table<T>::calcTable(void)
//{
//    T temp=0;
//    rowSum = new T[rows];
//    for(int i=0; i < rows; i++) {
//        rowSum[i]=0;
//    }
//    colSum=new T[cols];
//    for(int i=0; i<cols; i++) {
//        colSum[i]=0;
//    }
//
//    for(int i=0; i<cols; i++) {
//        for(int j=0; j<rows; j++ ) {
//            temp=temp+table[j*cols+i];
//        }
//        colSum[i]=temp;
//        temp=0;
//    }
//
//    for(int i=0; i<rows; i++) {
//        for(int j=0; j<cols; j++ ) {
//            temp=temp+table[i*cols+j];
//        }
//        rowSum[i]=temp;
//        temp=0;
//    }
//
//    for(int i=0; i<cols; i++) {
//        grandTotal=grandTotal+colSum[i];
//    }
//    cout<<grandTotal;
//}
//
