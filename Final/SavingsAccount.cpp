/* 
 * File:   SavingsAccount.cpp
 * Author: Michael
 *
 * Created on June 11, 2014, 2:25 PM
 */


#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(float amt ) {
    if( amt > 0 ) { 
        Balance=amt;
    }
    else {
        Balance=0;
    }
    FreqDeposit = 0;
    FreqWithDraw = 0;    
}
void SavingsAccount::Transaction(float amt) {
    if ( amt > 0 ){
        Deposit( amt );
    }
    else {
        Withdraw( amt );
    }
}

float SavingsAccount::Total(float rate, int time){
    float total = Balance * pow( ( 1.0 + rate ), time );
    return total;
}

float SavingsAccount::TotalRecursive(float rate, int time ){
    if( time == 0 ) {
        return Balance;
    }
    else{
        return ( 1 + rate ) * TotalRecursive( rate, time - 1 );
    }
}

float SavingsAccount::Deposit( float amt ){
    FreqDeposit++;
    Balance+= amt;
    return Balance;
}

float SavingsAccount::Withdraw(float amt) {
    FreqWithDraw++;
    Balance-= amt;
    return Balance;
}

void SavingsAccount::toString(){
    cout << "Balance: " << Balance << " FreqWithdraws: " << FreqWithDraw << " FreqDeposit: " << FreqDeposit << endl;
}
