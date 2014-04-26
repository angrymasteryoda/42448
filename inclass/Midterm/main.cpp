/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on April 21, 2014, 9:55 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

#include "Account.h"

using namespace std;

struct Employee {
    string name;
    float payrate;
    float hours;
    float pay;
};

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

void destroy( char* c );
void destroy( Employee* e );
void destroy( statsResult stat );
void destroy( int* i );
void print( Employee*, int );
void print( int *a, int s, int perLine );
void print( statsResult stat );
void swap1( int &n1, int &n2 );
void bubbleSort( int *arr, int s );
void makeModeArray( int *a, int size, statsResult &stat );
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

int factorial(int n);
int numModes( int *a, int size );
int maxFreq( int *a, int size );
int *blankArray( int s );
int *fillNumericArr( int size );
int *fillArr( int size );
int *copy(const int *a,int n);

float median( int *a, int size );
float mean ( int *a, int size );

string decrypt( int num[], int size );
string encrypt( int num[], int size );

int main( int argc, char** argv ) {
    srand( time( NULL ) );
    int problem;
    do{
        cout << "Enter a problem 1 - 6\n";
        cin >> problem;
        switch( problem ){
            case 1 :{
                problem1();
                break;
            }
            case 2 :{
                problem2();
                break;
            }
            case 3 :{
                problem3();
                break;
            }
            case 4 :{
                problem4();
                break;
            }
            case 5 :{
                problem5();
                break;
            }
            case 6 :{
                problem6();
                break;
            }
            default: {
                exit( 0xff );
            }
        }
    }
    while( problem < 6 );
    return 0;
     
}

void problem1(){
/*
1)  Develop an application using structures for a customer
that will determine if he/she has exceeded his/her checking 
account balance. For each customer, the following 
facts are available:

a. Account number (Five digits only, i.e. test for this)
b. Balance at the beginning of the month 
c. Total of all checks written by this customer this month 
     Loop until customer is through entering checks.
d. Total of all deposits credited to this customer's account this 
     month.  Loop until customer is through entering deposits.

The program should input each of these facts from input dialogs as 
integers, store in a structure, calculate the new balance, 
display the new balance and debit the account $12 if overdrawn. 
Also, if overdrawn, tell the customer the additional $12 fee 
has been accessed and what the balance would be with this fee included.*/
    
    cout << "Problem 1\n";
    Account acc;
    acc.accNum = new char[6];
    int i = 0;
    do{
        cout << "Enter your account number\n";
        cin >> acc.accNum;
    
        while( acc.accNum[i] != '\0'){
            i++;
        }
    }
    while( i != 5 );
    
    cout << "Enter the balance at the beginning of the month\n";
    cin >> acc.begBal;
    
    float blank = 0;
    
    do{
        cout << "Enter all the checks you wrote this month as positive numbers\n";
        cout << "To stop entering checks enter -1\n";
        cin >> blank;
        if( blank != -1 ){
            acc.withdraws += blank;
        }
    }
    while(blank != -1);
    blank = 0;
    do{
        cout << "Enter all the deposits you wrote this month as positive numbers\n";
        cout << "To stop entering checks enter -1\n";
        cin >> blank;
        if( blank != -1 ){
            acc.deposits += blank;
        }
    }
    while(blank != -1);
    
    acc.bal = acc.begBal - acc.withdraws + acc.deposits;
    
    if( acc.bal <= 0){
        cout << "You have over drafted your balance you will be charged an overdraft fee of $12\n";
        acc.bal -= 12;
    }
    cout << "Your new balance is " << acc.bal << endl;
    
    destroy( acc.accNum );
}

void problem2(){
/*Develop an application using an array of structures that will 
determine the gross pay for any number of employees input. The company pays 
"straight-time" for the first 20 hours worked, double time for 
all hours worked in excess of 20 hours but less than 40 hours, 
and triple time for any hours worked over 40 hours.

The program should be able to loop and input the employee's name, 
hours worked, and the rate of pay.  Once this has been done then 
the gross pay should be calculated.  Output all the pertinent information
with respect to the employee as a check and the process starts all over 
again until you input an invalid rate of pay or hours worked.  This
means a negative rate of pay or negative number of hours worked is
not acceptable. */
    
    int count = 0;
    cout << "enter the number of employees\n";
    cin >> count;
    Employee* employees = new Employee[count];
    for( int i = 0; i < count; i++ ){
        cout << "Enter an employees name (no longer than 50)\n";
        cin.ignore();
        getline( cin, employees[i].name );
        
        do{
            cout << "enter the pay rate\n";
            cin >> employees[i].payrate;
        }
        while ( employees[i].payrate < 0 );
        
        do{
            cout << "enter the number of hours worked\n";
            cin >> employees[i].hours;
        }
        while ( employees[i].hours < 0 );
        
        //calc pay
        if( employees[i].hours < 20 && employees[i].hours > 40 ){
            //double
            employees[i].pay = employees[i].hours + ( employees[i].payrate * 2 );
        }
        else if(employees[i].hours >= 40){
            //triple
            employees[i].pay = employees[i].hours + ( employees[i].payrate * 3 );
        }
        else{
            employees[i].pay = employees[i].hours + ( employees[i].payrate );
        }
    }
    
    print( employees, count );
    destroy( employees );
}

void problem3(){
    const int SIZE = 25;
    int *array = fillArr( SIZE );
    
    print( array, SIZE, 10 );
    int *sorted = copy( array, SIZE );
    bubbleSort( sorted, SIZE );
    statsResult stat;
    stat.avg = mean( array, SIZE );
    stat.median = median( sorted, SIZE );
    
    makeModeArray( sorted, SIZE, stat );
    print( stat );
  
    destroy( stat );
    destroy( array );
    destroy( sorted );
}

void problem4(){
/*A company wants to transmit data over the telephone, but they are 
concerned that their phones may be tapped. All of their data is 
transmitted as four-digit integers. However, they utilize the digits 
0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
will encrypt their data so that it may be transmitted more securely.
Your application should read a four-digit integer with the numbers 
0 to 7 entered by the user in an input dialog and encrypt it as 
follows: Replace each digit by (the sum of that digit plus 3) modulus 8. 
Then swap the first digit with the second, and swap the third digit 
with the fourth. Then print the encrypted integer. Write a separate 
application that inputs an encrypted four-digit integer and decrypts 
it to form the original number.
Note:  sometimes errors occur and the digits 8, and 9 might appear.  
Detect this condition and flag the error.  Can't read in numbers 
individually.  All the digits must be read with one cin statement. */
    string num;
    int size = 4;
    cout << "Enter a 4 digit number from 0-7\n";
    cin >> num;
    int digits[size];
    bool invalid = false;
    for( int i = 0; i < size; i++ ){
        int tmp = num[i] - '0';
        if( tmp >= 0 && tmp < 8){
            digits[i] = tmp;
        }
        else{
            i = size;
            invalid = true;
            cout << "Invalid number\n";
        }
//        digits[i] = atoi( num[i] );
    }
    
    if( !invalid ){
        int mode;
        cout << "press 1 to encryt or 2 to decrpyt numbers\n";
        cin >> mode;
        
        string res;
        if(mode == 1){
            res = encrypt( digits, size );
        }
        else{
            res = decrypt( digits, size );
        }
        cout << "your result: " << res << endl;
    }
}

void problem5(){
    int num = 7;
    cout << "short limit on factorial is " << num << endl;
    num = 16;
    cout << "int limit on factorial is " << num << endl;
    num = 20;
    cout << "long limit on factorial " << num  << endl;
    num = 33;
    cout << "float limit on factorial " << num << endl;
    num = 100;
    cout << "float limit on factorial " << num << endl;
}

void problem6(){
    cout << 2.125 << endl;
    cout << "\t10.001 bin\n\t2.1 oct\n\t2.2 hex\n";
    
    cout << "\n0.06640625\n";
    cout << "\t0.00010001 bin\n\t0.042 oct\n\t0.11 hex\n";

    cout << "\n-2.125" << endl;
    cout << "\t10111100 00000000 00000000 00000010 bin\n\t0xBC000002\n";
    
    cout << "\n0.06640625\n";
    cout << "\t00001000 10000000 00000000 00000000 bin\n\t0x08800000\n";
    
    cout << "\n0x46666601\n\t4.39999961853\n";
    
    cout << "\n0x46666602\n\t70.3999023438\n";
}

string encrypt( int num[], int size ){
    string res = "0000";
    //swap numbers around
    swap1( num[0], num[1] );
    swap1( num[2], num[3] );
    
    for( int i = 0; i < size; i++){
        num[i] += 3;
        num[i] %= 8;
        res[i] = num[i] + 48;
    }
    return res;
}

string decrypt( int num[], int size ){
    string res = "0000";
    //swap numbers around
    swap1( num[1], num[0] );
    swap1( num[3], num[2] );
    
    for( int i = 0; i < size; i++){
        num[i] -= 3;
        if( num[i] < 0) {
            num[i] += 8;
        }
        res[i] = num[i] + 48;
    }
    return res;
}

int factorial(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }	
}

void print( Employee* d, int size ){
    for( int i = 0; i < size; i++ ){
        cout << "name: " << d[i].name << endl;
        cout << "payrate: " << fixed << setprecision(2) << d[i].payrate << endl;
        cout << "hours: "<< fixed << setprecision(2) << d[i].hours << endl;
        cout << "pay: " << fixed << setprecision(2) << d[i].pay << endl;
    }
}

void print( int *a, int s, int perLine ) {
    for ( int i = 0; i < s; i++ ) {
        cout << *(a + i) << ", ";
        if ( i % 10 == ( perLine - 1 ) && perLine != -1 ){
            cout << endl;
        }
    }
    cout << endl;
}

void print( statsResult stat ){
    cout << "Mean: " << setprecision(2) << fixed << stat.avg << endl;
    cout << "Median: " << setprecision(2) << fixed << stat.median << endl;
    cout << "Mode:\n";
        cout << "\tMax freq: " << stat.maxFreq << endl;
        cout << "\tNum of modes: " << stat.nModes << endl;
        cout << "\tModes: ";
        for( int i = 0; i < stat.nModes; i++ ){
            cout << stat.mode[i] <<  ", "; 
        }
        cout << endl;
}

void bubbleSort( int *arr, int s ) {
    bool swap = false;

    do {
        swap = false;
        for ( int i = 0; i < s - 1; i++ ) {
            if ( *(arr+i) > *(arr+(i + 1)) ) {
                swap1( *(arr + i), *(arr + (i + 1) ) );
                swap = true;
            }

        }
    }    while ( swap );
}

void swap1( int &n1, int &n2 ) {
    n1 ^= n2;
    n2 = n1 ^ n2;
    n1 ^= n2;
}

float mean ( int *a, int size ){
    float result = 0;
    
    for( int i = 0; i < size; i++ ){
        result += (float) *( a + i );
    }
    
    result /= (float) size;
    return result;            
}

float median( int *a, int size ){
    int *medianArr = copy( a, size);
    
    //printArr( medianArr, size );
    //bubbleSort( medianArr, size );
    //printArr( medianArr, size );
    
    float result = 0;
    
    if ( size % 2 != 0 ) { //odd number
        int i = floor( ( (float) size / 2 ) );
        result = (float) *( medianArr + i );
    }
    else{ //even
        int i = size / 2 - 1;
        result = ( (float) *( medianArr + i ) + (float) *( medianArr + i +1 ) ) / 2;
    }
    
    destroy( medianArr );
    return result;
}

void makeModeArray( int *a, int size, statsResult &stat ){
    int modes = numModes( a, size );
    int occurance = 1;
    int lastMode = std::numeric_limits<int>::max();
    
    int *result = blankArray(modes);
    
    stat.maxFreq = maxFreq( a, size);
    stat.nModes = modes;
    
    int stupid = 0;
    for ( int i = 1; i < size; i++ ) {
        if ( *(a + i - 1) == *(a + i) ){
            occurance++;
            if ( occurance >= 2 ) {
                if ( lastMode != *(a + i - 1) ) {
                    //cout<< *(a+i-1)<<", ";

                    lastMode = *(a + i - 1);
                    result[ stupid++ ] = a[i - 1];
                }
           }
        }
        else{
            occurance = 1;
        }
    }
    stat.mode = result;
}

int maxFreq( int *a, int size ){
    int count = 1;
    int max = 1;
    
    for ( int i = 1; i < size; i++ ){
        if ( *(a + i - 1) == *(a+i) ){
            count++;
            if ( count > max ){
                max = count;
            }
        }
        else{
            count = 1;
        }
    }
    return max;
}

int numModes( int *a, int size ){
    int count = 0;
    int lastMode = std::numeric_limits<int>::max();
    int occurance = 1;
    
    for ( int i = 1; i < size; i++ ) {
        if ( *(a + i - 1) == *(a + i ) ){
            occurance++;
            if ( occurance >= 2 ) {
                if ( lastMode != *(a + i - 1) ) {
                    count++;
                    //cout<< *(a+i-1)<<", ";
                    lastMode = *(a + i - 1);
                }
           }
        }
        else{
            occurance = 1;
        }
    }
    
    return count;
}

int *blankArray( int s ){
    int *a = new int[s];
    for( int i = 0; i < s; i++){
        *(a + i) = 0;
    }
    return a;
}

int *fillNumericArr( int size ){
    int *a = new int [size];
    for ( int i = 0; i < size; i++ ) {
        *(a + i) = i % 10;
    }
    return a;
}

int *fillArr( int size ){
    int *a = new int [size];
    for ( int i = 0; i < size; i++ ) {
        *(a + i) = rand() % 90 + 10;
    }
    return a;
}

int *copy(const int *a,int n){
    //Copy a to b
    if( n <= 1 ) n = 2;
    int *b = new int[n];
    for( int i = 0; i < n; i++){
        *( b + i ) = *( a + i) ;
    }
    return b;
}

void destroy( char* c ){
    delete [] c;
}

void destroy( Employee* e ){
    delete [] e;
}

void destroy( int* i ){
    delete [] i;
}

void destroy( statsResult stat ){
    delete [] stat.mode;
}
