/* 
 * File:   SavingsAccount.h
 * Author: Michael
 *
 * Created on June 10, 2014, 8:03 PM
 */

#ifndef SAVINGSACCOUNT_H
#define	SAVINGSACCOUNT_H

using namespace std;

#include <cmath>
#include <iostream>

class SavingsAccount{
public:
    SavingsAccount( float );               //Constructor
    void  Transaction( float );            //Procedure
    float Total( float=0, int=0 );	         //Savings Procedure
    float TotalRecursive( float=0, int=0 );
    void  toString();                    //Output Properties
private:
    float Withdraw( float );               //Utility Procedure
    float Deposit( float );                //Utility Procedure
    float Balance;                       //Property
    int   FreqWithDraw;                  //Property
    int   FreqDeposit;                   //Property
};

#endif	/* SAVINGSACCOUNT_H */

