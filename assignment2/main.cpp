/* 
 * File:   main.cpp
 * Author: michael
 *
 * Created on February 26, 2014, 4:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int *fillArray( int size );
int *fillNumericArr( int size );
int *blankArray( int s );
int *copy(const int *,int);
int* makeModeArray(int *a, int size );

int maxFreq( int *a, int size );
int numModes( int *a, int size );

float mean ( int *a, int size );
float median( int *a, int size );

void printArr( int *a, int s );
void printArr( int *a, int s, int perLine );
void bubbleSort( int*, int );
void swap1( int&, int& );
void destroy(int *);
void meanMedianMode();
void mode( int *a, int size);

//problems
void Menu();
int getN();
void problem1();
void problem2();
void problem3();
float dropLowest( int *arr, int s);
void problem4();
void problem5();
void problem6();
int* reverse(int *a, int s);
void problem7();
int* doubleArray( int *a, int s );
void problem8();
int* shiftedArray( int *a, int s );
void problem9();
int doSomething(int *x, int *y);

int main( int argc, char** argv ) {
   
    srand( time( NULL ) );
    
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            case 7:    problem7();break;
            case 8:    problem8();break;
            case 9:    problem9();break;
            case 10:   meanMedianMode();break;
            default:   exit(1);
        }
    } while(inN<11);    
    return 0;
}

void Menu() {
	cout<<"Type 1-10 for problem 1-10"<<endl;
	cout<<"Type 11 to exit \n"<<endl;
}
int getN() {
	int inN;
	cin>>inN;
	return inN;
}

void meanMedianMode(){
    const int SIZE = 25;
    int *array = fillNumericArr( SIZE );
    
    printArr( array, SIZE, 10 );
    int *sorted = copy( array, SIZE );
    bubbleSort( sorted, SIZE );
        
    cout << "Mean: " << setprecision(2) << fixed << mean( array, SIZE ) << endl;
    cout << "Median: " << setprecision(2) << fixed << median( sorted, SIZE ) << endl;
    cout << "Mode:\n";
    
    
    //printArr( sorted, SIZE, 10 );
    mode( sorted, SIZE );
    //cout<<numModes(sorted, SIZE);        
    
    destroy( array );
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

void mode( int *a, int size){
    int *b = makeModeArray(a, size);
    //printArr(b, b[0]+2);
    cout << "\tMax freq: " << b[1] << endl;
    cout << "\tNum of modes: " << b[0] << endl;
    cout << "\tModes: ";
    for( int i = 2; i < b[0] + 2; i++ ){
        cout << b[i];
        if ( i <= b[0] ) { cout << ", "; }
        else { cout << endl; }
    }
    cout << endl;
    destroy(b);
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

int* makeModeArray(int *a, int size ){
    int modes = numModes( a, size );
    int occurance = 1;
    int lastMode = std::numeric_limits<int>::max();
    
    int *result = blankArray(modes+2);
    
    *(result + 1) = maxFreq( a, size);
    *(result) = modes;
    
    int stupid = 2;
    for ( int i = 1; i < size; i++ ) {
        if ( *(a + i - 1) == *(a + i) ){
            occurance++;
            if ( occurance >= 2 ) {
                if ( lastMode != *(a + i - 1) ) {
                    //cout<< *(a+i-1)<<", ";

                    lastMode = *(a + i - 1);
                    //fuck u 
                    result[ stupid++ ] = a[i - 1];
                }
           }
        }
        else{
            occurance = 1;
        }
    }
    return result;
}

int *fillArray( int size ){
    int *a = new int [size];
    for ( int i = 0; i < size; i++ ) {
        *(a + i)= rand( ) % 90 + 10;
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

int *blankArray( int s ){
    int *a = new int[s];
    for( int i = 0; i < s; i++){
        *(a + i) = 0;
    }
    return a;
}
void printArr( int *a, int s ){
    printArr( a, s, -1 );
}

void printArr( int *a, int s, int perLine ) {
    for ( int i = 0; i < s; i++ ) {
        cout << *(a + i) << ", ";
        if ( i % 10 == ( perLine - 1 ) && perLine != -1 ){
            cout << endl;
        }
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

int *copy(const int *a,int n){
    //Copy a to b
    if( n <= 1 ) n = 2;
    int *b = new int[n];
    for( int i = 0; i < n; i++){
        *( b + i ) = *( a + i) ;
    }
    return b;
}

void destroy(int *a){
    delete [] a;
}


void problem1(){
    cout << "enter a size for array: ";
    int size;
    cin >> size;
    
    int *arr = fillArray( size );
    cout << endl << &arr << endl;
    
    destroy( arr );
}

void problem2(){
    cout << "Entering test scores from 10 - 30\n";
    int size = rand() % 20 + 10;
    
    int *arr = fillArray( size );
    
    bubbleSort( arr, size );
    
    cout << "test scores\n";
    printArr( arr, size, 10);
    cout << "average: " << mean( arr, size ) << endl;
    
    destroy( arr );
}

float dropLowest( int *arr, int s){
    
    int *res = copy( arr, s );
    int offset = 0;
    
    if ( arr[0] < arr[1] ) {
        offset = 1;
    }
    else if ( arr[0] == arr[1] ) {
        for(int i = 1; i < s - 1; i++ ){
            if ( arr[i] < arr[i + 1] ) {
                i = s;
            }
            else if ( arr[i] == arr[i + 1] ) {
                offset++;
            }
        }
    }
    
    float result = 0;
    
    for( int i = offset; i < s; i++ ){
        result += (float) *( arr + i );
    }
    
    result /= (float) s - offset;
    return result;         
}

void problem3(){
        cout << "Entering test scores from 10 - 30\n";
    int size = rand() % 20 + 10;
    
    int *arr = fillArray( size );
    
    bubbleSort( arr, size );
    
    cout << "test scores\n";
    printArr( arr, size, 10);
    cout << "average: " << dropLowest( arr, size ) << endl;
    
    destroy( arr );
}
void problem4(){
//lazy problem 8
    cout << "enter array size\n";
    int s;
    cin >> s;
    cout << "your array\n";
    int *a = fillArray( s );
    bubbleSort( a, s);
    printArr( a, s, 10);
    cout << "mode\n";
    mode( a, s );
    destroy( a );

}
void problem5(){
//lazy problem 9
    cout << "enter array size\n";
    int s;
    cin >> s;
    cout << "your array\n";
    int *a = fillArray( s );
    bubbleSort( a, s);
    printArr( a, s, 10);
    cout << "median: " << median( a, s ) << endl;
    destroy( a );
}
void problem6(){
//problem 10
    int s = rand() % 20 + 2;
    cout << "your array\n";
    int *a = fillArray( s );
    printArr( a, s, 10 );
    
    int *b = reverse( a, s );
    cout << "reversed\n";
    printArr( b, s, 10 );
    
    destroy( b );
    destroy( a );
}

int* reverse(int *a, int s){
    int *copyA = copy( a, s );
    int *b = new int[s];
    for( int i = 0; i < s; i++){
        b[(s - 1) - i] = copyA[i];
    }
    destroy( copyA );
    return b;
}
void problem7(){
//problem 11
    int s = rand() % 20 + 2;
    cout << "your array\n";
    int *a = fillArray( s );
    printArr( a, s, 10 );
    
    int *b = doubleArray( a, s );
    cout << "doubled\n";
    printArr( b, s * 2, 10 );
    
    destroy( b );
    destroy( a );
}

int* doubleArray( int *a, int s ){
    int *copyA = copy( a, s );
    int newS = s * 2;
    int *b = new int[newS];
    for( int i = 0; i < s; i++){
        b[i] = copyA[i];
    }
    for( int i = 0; i < s; i++){
        b[s + i] = copyA[i];
    }
    destroy( copyA );
    return b;
}
void problem8(){
//problem 11
    int s = rand() % 20 + 2;
    cout << "your array\n";
    int *a = fillArray( s );
    printArr( a, s, 10 );
    
    int *b = shiftedArray( a, s );
    cout << "shifted\n";
    printArr( b, s + 1, 10 );
    
    destroy( b );
    destroy( a );
}
int* shiftedArray( int *a, int s ){
    int *copyA = copy( a, s );
    int newS = s + 1;
    int *b = new int[newS];
    b[0] = 0;
    for( int i = 1; i < newS; i++){
        b[i] = copyA[i - 1];
    }
    destroy( copyA );
    return b;
}
void problem9(){
    int x = 1, y = 2;
    int *px = &x, *py = &y;
    cout << "x: " << x << " y: " << y << " x + y: " << x + y << endl;
    cout << "did a function\n";
    cout << "x: " << x << " y: " << y << " x + y: " << doSomething( px, py ) << endl;
}

int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}


