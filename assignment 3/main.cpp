/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on March 26, 2014, 1:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "structures.h"


using namespace std;

void menu( int );
void menu( int, int );
int getInt();

void problem1();
int countChars( char * );
void problem2();
void reverseStr( char *str );
void problem3();
void problem4();
void printMovie( Movie m );
void problem5();
void printMovie( Movie2 m );
void problem6();
void printSales( SalesData s );

void destroyCA( char *a );
void destroyIA( int *a );
void destroyFA( float *a );
void destroyMovie( Movie m );
void destroyMovie( Movie2 m );
void destroySales( SalesData s );

int main(int argc, char** argv) {

    srand( time( NULL ) );
    
    int input;
    
    do{
        menu( 10 );
        input = getInt();
        switch( input ){
            case 1:     problem1();break;
            case 2:     problem2();break;
            case 3:     problem3();break;
            case 4:     problem4();break;
            case 5:     problem5();break;
            case 6:     problem6();break;
            default:   exit(250);
        }
    } while( input < 11);    
    
    return 0;
}

void menu(int e){ menu( 1, e); }
void menu(int s, int e){
    cout << "Enter a number from " << s << " - " << e << ". Enter " << e + 1 << " to end\n";
}

int getInt(){
    cout << "Enter a number: ";
    int n;
    cin >> n;
    return n;
    
}
//chap 10 1
void problem1(){
    cout << "Enter a string\n";
    int size = 100;
    char str[size];
    cin.ignore();
    cin.getline( str, size );
    
    cout << "the length is: " << countChars( str ) << endl;
}

int countChars( char *str ) {
    int i = 0, count = 0;
    while( str[i++] != '\0' ){
        count++;
    }
    return count;
}
//chap 10 2
void problem2(){
    cout << "Enter a string\n";
    int size = 100;
    char str[size];
    cin.ignore();
    cin.getline( str, size );
    
    reverseStr( str );
}

void reverseStr( char *str ){
    int size = countChars( str );
    char reversed[size];
    
    int j = 0;
    for( int i = size - 1; i >= 0; i--){
        reversed[i] = str[j++];
    }
    
    for( int i = 0; i < size; i++){
        cout << reversed[i];
    }
    cout << endl;
}
//chap 10 3
void problem3(){
    cout << "Enter a string\n";
    int size = 100;
    char str[size];
    cin.ignore();
    cin.getline( str, size );
    
    int i = 0, count = 1;
    while( str[i++] != '\0' ){
        if ( str[i] == ' ' ) {
            count++;
        }
    }
    cout << count << endl;
}
//chap 11 1
void problem4(){
    Movie m1;
    Movie m2;
    char director[16] = "Michael Risher";
    m1.director = director;
    m2.director = director;
    m1.title = "title1";
    m2.title = "title2";
    m1.year = 2014;
    m2.year = 2014;
    m1.time = 120;
    m2.time = 60;
    
    printMovie( m1 );
    printMovie( m2 );
}

void printMovie( Movie m ){
    cout << m.title << " directed by: " << m.director << endl;
    cout << "year: " << m.year << " running time " << m.time << " minutes" << endl;
}

void printMovie( Movie2 m ){
    cout << m.title << " directed by: " << m.director << endl;
    cout << "year: " << m.year << " running time " << m.time << " minutes" << endl;
    cout << "Production cost " << m.productionCost << " 5 year revenue " << m.Revenue5Yr << endl;
}

//chap 11 2
void problem5(){
    Movie2 m1;
    Movie2 m2;
    char director[16] = "Michael Risher";
    m1.director = director;    m2.director = director;
    m1.title = "title1";    m2.title = "title2";
    m1.year = 2014;    m2.year = 2014;
    m1.time = 120;    m2.time = 60;
    m1.productionCost = 124625783; m2.productionCost = 62312891.5;
    m1.Revenue5Yr = 155782228.75; m2.Revenue5Yr = 155782228.75;
    
    printMovie( m1 );
    printMovie( m2 );
    
    destroyMovie( m1 );
    destroyMovie( m2 );
}

//chap 11 3
void problem6() {
    SalesData sales;
    cout << "enter a division name\n";
    char input[100];
    cin.ignore();
    cin.getline( input, 100 );
    sales.name = input;
    sales.quarters = 4;
    sales.quarterSales = new int[sales.quarters];
    sales.annualSales = 0;
    sales.averageQuarterlySales = 0;
    for( int i = 0; i < sales.quarters; i++ ){
        cout << "Enter sales for quarter " << i + 1 << ": ";
        cin >> sales.quarterSales[i];
        sales.annualSales += sales.quarterSales[i];
    }
    sales.averageQuarterlySales = sales.annualSales / sales.quarters;
    
    printSales( sales );
    
    destroySales( sales );
}

void printSales( SalesData s ){
    cout << "name: " << s.name << endl;
    for( int i = 0; i < s.quarters; i++ ){
        cout << "quarter " << i + 1 << ": " << s.quarterSales[i] << endl;
    }
    cout << "annual sales: " << s.annualSales << endl;
    cout << "average quarterly sales: " << s.averageQuarterlySales << endl;
}

void destroySales( SalesData s ){
    delete [] s.name;
    delete [] s.quarterSales;
}
void destroyMovie( Movie2 m ){
    delete [] m.director;
    delete [] m.title;
}
void destroyMovie( Movie m ){
    delete [] m.director;
    delete [] m.title;
}
void destroyCA( char *a ){
    delete [] a;
}
void destroyIA( int *a ){
    delete [] a;
}
void destroyFA( float *a ){
    delete [] a;
}
