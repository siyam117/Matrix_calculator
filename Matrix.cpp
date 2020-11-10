#include <iostream>
#include <vector>
#include "Matrix.h"
#include <fstream>
#include <iterator>
#include <sstream>
using namespace std;

int counter = 0;

Matrix::Matrix(){

}


int Matrix::fill_from_file(char *path){
    counter++;

    ifstream file(path);
    string line;

    if (!file){
        cout << "operand " << counter << " doesn't exist";
        exit(-1);
    }
    else{

    
    
    while (getline(file, line)){
        vector<int> temp;
        istringstream iss(line);

        int num;
        while (iss >> num){
            temp.push_back(num);          // fills matrix with value from file
            C++;
        }

        _matrix.push_back(temp);
        R++;
    }
    }

return 0;
}




int Matrix::store_in_file(char *path){
    
    ofstream file(path);
    ostream_iterator<int> output_iterator(file, " ");
    for ( int i = 0 ; i < _matrix.size() ; i++ ) {
        copy(_matrix.at(i).begin(), _matrix.at(i).end(), output_iterator);
        file << '\n';
    }
        return 0;
}




int Matrix::index(int row, int column){
    if(row > R-1 || column > C/R - 1 ){
        cout << "index out of range";
        return -1;
    }
    else{
        cout << _matrix[row][column];
    }
    
    return 0;
}


//returns rows
int Matrix::rows(){
    cout << R << "\n";
    return 0;
}

//returns columns
int Matrix::columns(){
    cout << C/R;
    return 0;
}

//adds matrix to matrix
int Matrix::add(Matrix *m,char *path){
    _matrix2 = _matrix;
    
    m->fill_from_file(path);

    if (R != m->R || C != m->C ){
        cout << "Vectors not the same size";
        return -1;
    }
    else{
    for(int i = 0; i<R;i++){
        for(int j = 0;j<C/(R); j++){
           m->_matrix[i][j] = m->_matrix[i][j] + _matrix2[i][j];
    }
    }
    _matrix = m->_matrix;
    }

    row_count = R + 1;
    col_count = C/R + 1;
    return 0;

}

//adds scalar to matrix
int Matrix::add(int val){

    for(int i = 0; i<R;i++){
        for(int j = 0;j < C/R; j++){
           _matrix[i][j] += val;
    }
    }

    row_count = R + 1;
    col_count = C/R + 1;
    return 0;
}


//multiplies matrix by scalar value
 int Matrix::mult(int val){
    for(int i = 0; i<R;i++){
        for(int j = 0;j<C/(R); j++){
           _matrix[i][j] *= val;
    }
    }
    row_count = R;
    col_count = C/R;
    return 0;
 }

 int Matrix::mult(Matrix *m,char *path){
    _matrix2 = _matrix;
    
    m->fill_from_file(path);

    if (R != m->C/m->R){
        cout << "Vectors not the right size";
        return -1;
    }
    else{

        row_count = m-> R;
        col_count = m-> C/R;


       
        for(int i = 0; i<R;i++){
            for(int j = 0;j<C/R; j++){
                _matrix[i][j] = 0;
                for (int k = 0; k < C/R; k++){
                    _matrix[i][j] = _matrix[i][j] + m->_matrix[k][j] *  _matrix2[i][k];
                    
                }
            }
        }
    }

    row_count = R;
    col_count = m->C/m->R;
    return 0;
 }
 

//prints matrix on console
void Matrix::print(){



    for(int i = 0; i<row_count;i++){
        for(int j = 0;j < row_count; j++){
          cout <<  _matrix[i][j] << " ";
    }
    cout << "\n";
    }

  
}






    

    
    