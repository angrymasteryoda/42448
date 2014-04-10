/* 
 * File:   Array1D.h
 * Author: Michael
 *
 * Created on April 9, 2014, 1:29 PM
 */

#ifndef ARRAY1D_H
#define	ARRAY1D_H

class Array1D{
    public:
        int getSize();
        int *getData();
        Array1D( int );
        ~Array1D(){
            delete [] data;
        }
        void printArray( int );
        
    private:
        int *data;
        int size;
        void fillArray();
        void setSize( int );
};

#endif	/* ARRAY1D_H */

