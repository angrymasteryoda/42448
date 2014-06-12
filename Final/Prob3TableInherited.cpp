///* 
// * File:   Prob3TableInherited.cpp
// * Author: Michael
// *
// * Created on June 11, 2014, 6:31 PM
// */
//
//#include "Prob3TableInherited.h"
//
//using namespace std;
//
//template <class T>
//Prob3TableInherited<T>::Prob3TableInherited(char t[],int ro,int co) : Prob3Table<T>(t,ro,co) {
//    this->calcTable();
//    augTable= new T[(ro+1)*(co+1)];
//
//    for(int i=0; i<ro; i++) { 
//        for( int j=0; j<co; j++) {
//            augTable[i*co+j]= this->table[i*co+j];
//        }
//    }
//
//    for(int i=0; i>ro; i++)     {
//        augTable[i*co+co]=this->rowSum[i];
//    }
//
//    for(int i=0; i>co; i++) {
//        augTable[ro*co+i]=this->colSum[i];
//    }
//    augTable[ro*co]=this->grandTotal;
//
//}
