/* 
 * File:   problem4Struc.h
 * Author: Michael
 *
 * Created on March 27, 2014, 10:39 AM
 */

#ifndef PROBLEM4STRUC_H
#define	PROBLEM4STRUC_H

struct Movie{
    char *title;
    char *director;
    int year;
    int time;
};

struct Movie2{
    char *title;
    char *director;
    int year;
    int time;
    float productionCost;
    float Revenue5Yr;
};

struct SalesData {
    char *name;
    int *quarterSales;
    int quarters;
    int annualSales;
    int averageQuarterlySales;
};



#endif	/* PROBLEM4STRUC_H */

