#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define SIZE 10

bool recursive_binary_search (vector <int> data, int target, int min, int max) {

    int mean;
    bool flag = false;

    if (min <= max) {

        mean = (min + max) / 2;

        if (target == data[mean])
            flag = true;

        else if (target < data[mean])
            flag = recursive_binary_search(data, target, min, mean - 1);

        else
            flag = recursive_binary_search(data, target, mean + 1, max);
    }

    return (flag);
}

bool iterative_binary_search (vector <int> data, int target, int min, int max) {

    int mean;
    bool flag = false;

    while (min <= max) {

        mean = (min + max) / 2;

        if (target == data[mean]) {
            flag = true;
            min = max + 1;
        }

        else if (target < data[mean])
            max = mean - 1;

        else
            min = mean + 1;
    }

    return (flag);
}

int * create_array () {

    //static because of the lifetime of variables in functions
    static int array [SIZE];
    srand (time(NULL)); //initializing random

    for (int i=0; i<SIZE; i++)
        array[i] = rand() % 100;

    return (array);
}

void print_data (vector <int> data) {

    for (int i=0; i<SIZE; i++)
        cout << data[i] << " ";
}

int main () {

    int * data = create_array ();
    vector <int> data_vector (data, data + SIZE); //creates an stl vector based on the array data
    sort (data_vector.begin(), data_vector.end()); //sorts the stl vector
    print_data(data_vector);

    //asking input and giving output
    int target;
    cout << endl << "Number to find: ";
    cin >> target;
    bool found = recursive_binary_search(data_vector, target, 0, SIZE - 1);
    cout << "The recursive method found: " << found << endl;
    found = iterative_binary_search(data_vector, target, 0, SIZE - 1);
    cout << "The iterative method found: " << found << endl;

    return (0);
}
