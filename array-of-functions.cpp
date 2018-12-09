#include <iostream>
using namespace std;

typedef int (*f)(int, int); //we define the type f as an int function with two int arguments

int add (int a, int b){

    return (a + b);
}

int sub (int a, int b){

    return (a - b);
}


int mul (int a, int b){

    return (a * b);
}


int div (int a, int b){

    return (a / b);
}

int mod (int a, int b){

    return (a % b);
}

int main () {

    f array[5] = {add, sub, mul, div, mod}; //creating the array of functions
    for (int i=0; i<5; i++) cout << "function " << (i+1) << ": " << array[i](3, 10) << endl;
    return (0);
}
