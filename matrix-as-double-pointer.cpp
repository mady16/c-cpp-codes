#include <iostream>
using namespace std;

int ** create_matrix (int rows, int columns) {

    int ** matrix;
    matrix = new int * [rows];

    for (int i=0; i<rows; i++){

        matrix [i] = new int [columns];

        for (int j=0; j<columns; j++)
            matrix [i][j] = 0;
    }

    return (matrix);
}

void print (int ** matrix, int rows, int columns) {

    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++)
            cout << matrix [i][j] << " ";
        cout << endl;
    }
}

int main () {

    int ** matrix;  //creating matrix as a pointer to a pointer
    int rows = 3;
    int columns = 3;
    matrix = create_matrix (rows, columns);
    print (matrix, rows, columns);
    return (0);
}
