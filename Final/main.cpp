/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on June 10, 2014, 9:39 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Employee.h"
#include "SavingsAccount.h"

using namespace std;

void menu();
void p1();
void p2();
void p3();
void p4();
void p5();

int main( int argc, char** argv ) {
    srand( time( NULL ) );
    int input;    
    p4();
    return 0;
    do{
        menu();
        cin >> input;
        
        switch( input ){
            case 1:
//                p1();
                break;
            case 2:
                //p2()
                break;
            case 3:
                p3();
                break;
            case 4:
                p4();
                break;
            case 5:
                p5();
                break;
            case 6:
                cout << "quiting\n";
                exit(0);
        }
    }
    while( input != 6);
    return 0;
}

void menu(){
    int count = 5;
    for( int i  = 0; i < count; i++ ){
        cout << "Press " << i+1 << " ----> For problem " << i+1 << endl;
    }
    cout << "Press 6 ----> to exit\n";
}

void p1(){
    char n = 5;
    unsigned char rndseq[] = { 16, 34, 57, 79, 144} ;
    int ntimes = 100000;
    Prob1Random a( n, rndseq );
    for(int i = 1; i <= ntimes; i++) {
        a.randFromSet();
    }
    int *x = a.getFreq();
    unsigned char *y = a.getSet();
    for(int i = 0; i < n; i++) {
        cout << ( y[i] - 0 ) << " occured " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;

    
//    char *y = a.getSet();
//    for(int i = 0; i < n; i++) {
//        cout << int( y[i] ) << ", ";
//    }
}   

void p2(){
//    cout << "The start of Problem 2, the sorting problem" << endl;
//    Prob2Sort<char> rc;
//    bool ascending = true;
//    ifstream infile;
//    infile.open( "Problem2.txt", ios::in );
//    char *ch2 = new char[10*16];
//    char *ch2p = ch2;
//    while( infile.get( *ch2 ) ) {
//        cout << *ch2;
//        ch2++;
//    }
//    infile.close();
//    cout << endl;
//    cout << "Sorting on which column"<<endl;
//    int column;
//    cin >> column;
//    char *zc = rc.sortArray( ch2p, 10, 16, column, ascending);
//    for(int i = 0; i < 10; i++ ) {
//        for(int j = 0; j < 16; j++ ) {
//            cout << zc[i*16+j];
//        }
//    }
//    delete []zc;
//    cout << endl;
}

void p3(){
}

void p4(){
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.TotalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;
}

void p5(){
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0), Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0), Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(60));
    Mary.toString();
}
