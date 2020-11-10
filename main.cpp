#include <iostream>
#include <vector>
#include "Matrix.h"
#include <fstream>
#include <iterator>
#include <cmath>
#include <stdio.h>
#include <string.h>



using namespace std;

int main(int argc, char* argv[]){
    Matrix ma;
    Matrix *matrixpointer = new Matrix();
    if( argc != 5 )
    {
        printf("invalid number of arguments.\n");
    }
    else{

        if (strcmp(argv[2] , "+" ) != 0 && strcmp(argv[2] , "x" ) != 0){
            cout << "incorrect operation";
            exit(-1);
        }
        char *ptr;
        long op2 = strtol(argv[3],&ptr,10);

        if(strcmp(argv[2] , "+" ) == 0){
            char *ptr;
            long arg3 = strtol(argv[3],&ptr,10);
            if (*ptr == '\0'){
                ma.fill_from_file(argv[1]);
                int val = atoi(argv[3]);
                ma.add(val);
                ma.print();
                ma.store_in_file(argv[4]);
            
            }
            else{
                ma.fill_from_file(argv[1]);
                int val = atoi(argv[3]);
                ma.add(matrixpointer,argv[3]);
                ma.print();
                ma.store_in_file(argv[4]);
                
            }
        }

        if(strcmp(argv[2] , "x" ) == 0){
            char *ptr;
            long arg3 = strtol(argv[3],&ptr,10);
            if (*ptr == '\0'){
                ma.fill_from_file(argv[1]);
                int val = atoi(argv[3]);
                ma.mult(val);
                ma.print();
                ma.store_in_file(argv[4]);
            
            }
            else{
                ma.fill_from_file(argv[1]);
                int val = atoi(argv[3]);
                ma.mult(matrixpointer,argv[3]);
                ma.print();
                ma.store_in_file(argv[4]);
                
            }
        }
    }
return 0;
}