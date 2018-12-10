#include <iostream>
using namespace std;

template <class T>
class n_matrix {

    private:

        int rows, columns;
        T ** matrix;

        void init () {

            for (int i=0; i<rows; i++)
                for (int j=0; j<columns; j++)
                    matrix [i][j] = 0;
        }

    public:

        n_matrix (int i, int j) {

            rows = i;
            columns = j;
            matrix = new T * [rows];
            for (int i=0; i<rows; i++) matrix[i] = new T[columns];
            init ();
        }

        ~n_matrix () {

            //we must start from one in order to mantain the reference to the array
            for (int i=1; i < rows; i++) delete [] matrix[i];
            delete [] matrix;
        }

        int get_rows() {

            return (rows);
        }

        int get_columns () {

            return (columns);
        }

        T get_value_at (int i, int j) {

            T value = matrix[i][j];
            return (value);
        }

        void set_value_at (T value, int i, int j) {

            matrix[i][j] = value;
        }

        void fill () {

            for (int i=0; i<rows; i++)
                for (int j=0; j<columns; j++) {

                    cout << "M[" << (i+1) << "][" << (j+1) << "]: ";
                    cin >> matrix[i][j];
                }
        }

        void invert_triangular () {

            for (int i=0; i<rows; i++)
                for (int j=0; j<columns; j++) {

                    if (j < i) {
                        T temp = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = temp;
                    }
                }
        }

        void set_equals (n_matrix M) {

            for (int i=0; i<rows; i++)
                for (int j=0; j<columns; j++) {

                    float value = M.get_value_at (i, j);
                    set_value_at (value, i, j);
                }
        }

        n_matrix sum (n_matrix & B) {

            n_matrix M(rows, columns);
            for (int i=0; i<rows; i++) {

                for (int j=0; j<columns; j++) {
                    float value = get_value_at(i,j) + B.get_value_at(i,j);
                    M.set_value_at(value, i, j);
                }
            }

            return (M);
        }

        n_matrix minus (n_matrix & B) {

            static n_matrix M(rows, columns);
            for (int i=0; i<rows; i++) {

                for (int j=0; j<columns; j++) {
                    float value = get_value_at(i,j) - B.get_value_at(i,j);
                    M.set_value_at(value, i, j);
                }
            }

            return (M);
        }

        n_matrix multiply (n_matrix & B) {

            n_matrix M(rows, B.columns);
            for (int i=0; i<rows; i++) {

                for (int j=0; j<columns; j++) {

                    float value = 0;
                    for (int k=0; k<columns; k++)
                        value += get_value_at(i,k) * B.get_value_at(k,j);

                    M.set_value_at(value, i, j);
                }
            }

            return (M);
        }

        void print () {

            for (int i=0; i<rows; i++){

                for (int j=0; j<columns; j++)
                    cout << matrix[i][j] << " ";
                cout << endl;
            }
            cout << endl;
        }
};

int main () {

    int m, n;
    cout << "Number of rows: ";
    cin >> m;
    cout << "Number of columns: ";
    cin >> n;

    n_matrix <int> A (m, n);
    A.fill();

    cout << endl << endl;

    n_matrix <int> B (m, n);
    B.fill();

    /*we pass the object by reference because the copy
    the compiler makes by value in the function has the same allocation as the original
    and its destructor is automatically called when the function ends, destroying
    the original object */
    n_matrix <int> C (m, n);
    /*we cannot just use "=" operator because the array of n_matrix class
    //instead we have to assign each value manually.*/
    C.set_equals(A.sum(B));

    n_matrix <int> D (m, n);
    D.set_equals(A.minus(B));

    n_matrix <int> E (m, n);
    E.set_equals(A.multiply(B));

    cout << endl;
    cout << "A original: " << endl;
    A.print();
    cout << "A inverted: " << endl;
    A.invert_triangular();
    A.print();
    cout << "A + B:" << endl;
    C.print();
    cout << "A - B:" << endl;
    D.print();
    cout << "A * B:" << endl;
    E.print();

    return (0);
}
