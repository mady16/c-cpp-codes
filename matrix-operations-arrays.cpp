#include <iostream>
using namespace std;

const int N = 3;

void sum (int a [][N], int b [][N], int c [][N]) {

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            c[i][j] = a[i][j] + b [i][j];
}

void subtr (int a [][N], int b [][N], int c [][N]) {

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            c[i][j] = a[i][j] - b [i][j];
}

void scalar_prod (int lambda, int a [][N], int c [][N]) {

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            c[i][j] = lambda * a[i][j];
}

void matrix_prod (int a [][N], int b [][N], int c [][N]) {

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {

            int value = 0;
            for (int k=0; k<N; k++)
                value += a[i][k] * b[k][j];
            c[i][j] = value;
        }
}

void invert_triangular (int a [][N], int c [][N]) {

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            c[i][j] = a[j][i];
}

void print (int m [][N]) {

    for (int i=0; i<N; i++) {

        for (int j=0; j<N; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

int main () {

    int A[N][N] = {{3, 2, 1},{4, 5, 6},{4, 5, 6}};
    int B[N][N] = {{2, 1, 6},{7, 2, 3},{3, 1, 9}};
    int C[N][N];

    cout << "print function: " << endl;
    print (A);
    cout << endl;
    print (B);

    cout << endl << "sum function: " << endl;
    sum (A, B, C); //arrays pass by reference
    print (C);

    cout << endl << "subtraction function: " << endl;
    subtr (A, B, C); //arrays pass by reference
    print (C);

    cout << endl << "scalar product function: " << endl;
    scalar_prod (5, A, C); //arrays pass by reference
    print (C);

    cout << endl << "matrix product function: " << endl;
    matrix_prod (A, B, C); //arrays pass by reference
    print (C);

    cout << endl << "invert triangular function: " << endl;
    invert_triangular (A, C); //arrays pass by reference
    print (C);

    return (0);
}
