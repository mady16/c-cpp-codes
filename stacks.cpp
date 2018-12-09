/*Stacks are data structures with two main operations: push and pop.
They have the restriction that insertion and deletion of an element
can only be done from the last position of the stack (what we call the top)
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

template <typename T> //passing the data type as a parameter
class Stack {

    private:

        int size, top;
        T * stack; //array storing the stack data

    public:

        Stack (int n){  //class constructor

            size = n;
            top = -1;
            stack = new T [size]; //dynamically allocating array
        }

        ~Stack () { //class destructor

            delete [] stack;
        }

        void push (T e) {

            if (is_full()) cout << "Stack is full." << endl;
            else stack[++top] = e;
        }

        T pop () {

            if (is_empty()) cout << "Stack is empty.    " << endl;
            else top -= 1;
	    return stack[top+1];
        }

        bool is_empty () {

            return (top == -1);
        }

        bool is_full () {

            return (top == size-1);
        }

        T top_element () {

            if (is_empty()) cout << "Stack is empty. ";
            return stack[top];
        }

        T element_at (int pos) {

            if (is_empty()) cout << "Stack is empty. ";
            return stack[pos-1];
        }

        void print () {

            if (is_empty()) cout << "Stack is empty. ";
            for (int i=0; i<=top; i++) cout << stack[i] << " ";
            cout << endl;
        }

};

int main (){

    int stack_size = 10;
    Stack <float> stack (stack_size); //specifying the type of the elements in the stack

    srand(time(NULL)); //seeds the pseudo-random number generator

    cout << "Is the stack empty? (1-yes, 0-no): " << stack.is_empty() << endl;
    for (int i=1; i<=stack_size-2; i++) stack.push(rand() % 100);
    stack.print();
    cout << "Element at position (3): " << stack.element_at(3) << endl;
    cout << "Element at top: " << stack.top_element() << endl;
    cout << "Calling the pop function... " << stack.pop() << endl;
    stack.print();

    cout << endl;

    string str1 ("Hello");
    string str2 ("World");
    Stack <string> string_stack (2);
    string_stack.push(str1);
    string_stack.push(str2);
    string_stack.print();

    Stack <string> stack1 (3);
    stack1.element_at(1); //as the stack is empty it will return trash.

    return (0);
}
