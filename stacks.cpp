/*Stacks are data structures with two main operations: push and pop.
They have the restriction that insertion and deletion of an element
can only be done from the last position of the stack (what we call the top)
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Stack {

    private:

        int size, top;
        float * stack;

    public:

        Stack (int n){  //class constructor

            size = n;
            top = -1;
            stack = new float [size]; //dynamically allocating array
        }

        ~Stack () { //class destructor

            delete [] stack;
        }

        void push (int e) {

            if (top == size - 1) cout << "Stack is full" << endl;
            else stack[++top] = e;
        }

        void pop () {

            if (is_empty()) cout << "Stack is empty" << endl;
            else top -= 1;
        }

        bool is_empty () {

            return (top == -1);
        }

        int top_element () {

            if (is_empty()) {
                cout << "Stack is empty: ";
                return (-1);
            }
            else return stack[top];
        }

        int element_at (int pos) {

            if (is_empty()) {
                cout << "Stack is empty: ";
                return (-1);
            }
            else return stack[pos];
        }

        void print () {

            for (int i=0; i<=top; i++) cout << stack[i] << " ";
            cout << endl;
        }

};

int main (){

    int stack_size = 10;
    Stack stack (stack_size);

    srand(time(NULL)); //seeds the pseudo-random number generator

    cout << "Is the stack empty? (1-yes, 0-no): " << stack.is_empty() << endl;
    for (int i=1; i<=stack_size-2; i++) stack.push(rand() % 100);
    stack.print();
    cout << "Element at position (3): " << stack.element_at(3) << endl;
    cout << "Element at top: " << stack.top_element() << endl;
    cout << "Calling the pop function... " << endl;
    stack.pop();
    stack.print();

    return (0);
}
