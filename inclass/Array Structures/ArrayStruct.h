/* 
 * File:   ArrayStruct.h
 * Author: rcc
 *
 * Created on March 24, 2014, 1:21 PM
 */

#ifndef ARRAYSTRUCT_H
#define	ARRAYSTRUCT_H

struct ArrayStruct1d{
    int *array;
    int size;
};


struct ArrayStruct2d{
    int **array;
    int rows;
    int cols;
};
#endif	/* ARRAYSTRUCT_H */

