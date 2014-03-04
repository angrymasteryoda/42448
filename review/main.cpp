/* 
 * File:   main.cpp
 * Author: michael
 *
 * Created on February 24, 2014, 3:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

/*
 * 
 */
const int NUM7=4;

void p3_12();
void p4_10();
void p5_10();
void p7_7();
void fillN7(float sales[][NUM7], int s);
void printN7(float sales[][NUM7], int s);

int main( int argc, char** argv ) {
    p4_10();
    return 0;
}

void p3_12(){
    //set up the ticket prices
    const float at = 6.00, ct = 3.00;
    //tickets sold
    int ats, cts;
    //make the profit var
    float gross, income;
    string movie;
    //ask for info
    cout<<"Enter the movie name\n";
    cin>>movie;
    cout<<"Enter the amount of adult tickets sold\n";
    cin>>ats;
    cout<<"Enter the amount of child tickets sold\n";
    cin>>cts;
    gross = (ats * at) + (cts * ct);
    income = gross * .20;
    //format and print
    cout<<"Movie name:            "<<setw(10)<<movie<<
            "\nadult tickets sold   "<<setw(10)<<ats<<
            "\nchild tickets sold   "<<setw(10)<<cts<<
            "\ngross profit         "<<setw(8)<<"$"<<gross<<
            "\nnet profit           "<<setw(8)<<"$"<<income<<
            "\namount to distributor"<<setw(8)<<"$"<<gross - income<<endl;
}

void p4_10(){
    cout<< "enter a amount to buy ";
    int amt;
    cin >> amt;
    while(amt<1){
        cout<<"Cant buy 0 buy more than 0";
        cin>>amt;
    }
    cout << "discount of ";
    if ( amt >= 10 && amt < 20 ) {
        cout << "20%";
    }
    else if ( amt >= 20 && amt < 50 ) {
        cout << "30%";
    }
    else if ( amt >= 50 && amt < 100 ) {
        cout << "40%";
    }
    else if ( amt >= 100 ) {
        cout << "50%";
    }
    else{
        cout << "none";
    }
    cout<<endl;
}

void p5_10(){
        short years;
        int m;//month loop
        int tr=0,r=0;//rain
        cout<<"how many years of rainfall are you going to average\n";
        cin>>years;
        while(years<1){
            cout<<"Cant average zero years re-enter years\n";
            cin>>years;
        }
        
        //loop for years;
        for(int y=1;y<=years;y++){
            
            for(m=1;m<=12;m++){
                
                cout<<"How many inches of rain did you get in month "<<m<<endl;
                cin>>tr;
                while(tr<0){
                    cout<<"you cant have negative measures, re-enter the number of inches\n";
                    cin>>tr;
                }
                r+=tr;
            }
        }
        cout<<r<<endl;
        r=r/(years*12);
        cout<<"the average amount of rain is: "<<r<<"in\n";
        
}

void p7_7(){
  const int divs = 6;  
  float sales[divs][NUM7];
  fillN7(sales, divs);
  printN7(sales, divs);
}


void fillN7(float sales[][NUM7], int s){
    char random='n';
    cout<<"Enter y to fill out numbers or enter n to randomize it\n";
    cin>>random;
    if(random=='y'){
        for(int i=0; i<s; i++){
            cout<<"Division #"<<i+1<<endl;
            for(int x=0;x<NUM7; x++){
                cout<<"Enter the sales for quarter "<<x+1<<endl;
                cin>>sales[i][x];
            }
        }
    }else{
        for(int i=0; i<s; i++){
            for(int x=0;x<NUM7; x++){
                sales[i][x]=(rand()%99+10)+((rand()%98+10)/100.0f);
            }
        }
    }
    ofstream out;
    out.open("num7.txt");
    for(int i =0; i<s; i ++){
        for(int x=0; x<NUM7; x++){
            out<<sales[i][x]<<" ";
        }
        out<<endl;
    }
    out.close();
    
}

void printN7(float sales[][NUM7], int s){
    float sum[s];
    float diff=0;
    float com[s];//com short of company
    for(int i=0; i<s; i++){
        com[i]=0;
    }
    for(int i=0; i<s; i++){
        cout<<"Division "<<i+1<<endl;
        for(int x=0;x<NUM7; x++){
            if(x!=0){
                diff=sales[i][x]-sales[i][x-1];
            }
            cout<<setprecision(2)<<fixed<<"\tQuarter "<<x+1<<" $"<<sales[i][x]<<"\tDifference  $"<<diff<<endl;
            sum[i]+=sales[i][x];
            diff=0;
        }
    }
    //print sum for each division
    for(int i=0; i<s;i++){
        cout<<"Total sales for division "<<i+1<<" is $"<<sum[i]<<endl;
    }

}