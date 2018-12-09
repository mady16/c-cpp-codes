#include <iostream>
#include <cmath>
using namespace std;

class complex {

    private:

        float real, imaginary;

    public:

        complex (): real(0), imaginary(0) {}

        complex (float R, float Im): real(R), imaginary(Im) {}

        ~complex () {}

        void print() {

            cout << real << " + i(" << imaginary << ")";
        }

        float real_part() {

            return (real);
        }

        float imaginary_part() {

            return (imaginary);
        }

        float norm () {

            float a = real_part();
            float b = imaginary_part();

            float N = a * a + b * b;
            return (sqrt(N));
        }

        complex sum (complex b) {

            float r = real_part() + b.real_part();
            float im = imaginary_part () + b.imaginary_part();
            complex c  (r, im);
            return (c);
        }

        complex multiply (complex n) {

            float a = real_part();
            float b = imaginary_part();
            float c = n.real_part();
            float d = n.imaginary_part();

            complex r (a*c - b*d, a*d + b*c);
            return r;
        }

        complex divided_by (complex n) {

            float a = real_part();
            float b = imaginary_part();
            float c = n.real_part();
            float d = n.imaginary_part();

            float real = (a*c + b*d) / (n.norm() * n.norm());
            float imaginary = (b*c - a*d) / (n.norm() * n.norm());

            complex r (real, imaginary);
            return (r);
        }
};

int main () {

    complex a (3, 2);
    complex b (4, -3);
    complex c, d, e;

    cout << "||a|| = " << a.norm() << endl;
    cout << "||b|| = " << b.norm() << endl;

    c = a.sum(b);
    d = a.multiply(b);
    e = a.divided_by(b);

    cout << "[";
    a.print();
    cout << "] + [";
    b.print();
    cout <<  "] = ";
    c.print();

    cout << endl;

    cout << "[";
    a.print();
    cout << "] * [";
    b.print();
    cout <<  "] = ";
    d.print();

    cout << endl;

    cout << "[";
    a.print();
    cout << "] / [";
    b.print();
    cout <<  "] = ";
    e.print();

    cout << endl;

    return (0);
}
