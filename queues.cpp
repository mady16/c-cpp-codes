#include <iostream>
using namespace std;

template <typename T>
class Queue {

    private:

        int size, tail;
        T * queue;

    public:

        Queue (int n) {

            size = n;
            queue = new T [size];
            tail = -1;

        }

        ~Queue () {

            delete [] queue;
        }

        void add (T e) {

            queue[++tail] = e;
        }

        void del () {

            for (int i=0; i<tail; i++)
                queue[i] = queue[i+1];

            tail--;
        }

        bool is_empty (){

            return (tail == -1);
        }

        bool is_full (){

            return (tail == size - 1);
        }

        T top_element () {

            if (is_empty()) cout << "Queue is empty. ";
            return queue[tail];
        }

        T element_at (int pos) {

            if (is_empty()) cout << "Queue is empty. ";
            return queue[pos-1];
        }

        void print () {

            if (is_empty()) cout << "Queue is empty. ";
            for (int i=0; i<=tail; i++) cout << queue[i] << " ";
            cout << endl;
        }
};

int main () {

    Queue <int> int_queue (5);
    for (int i=0; i<5; i++) int_queue.add(i+1);
    int_queue.print();
    int_queue.add(6);
    int_queue.print();
    int_queue.del();
    int_queue.print();
    for (int i=0; i<5; i++) int_queue.del();
    int_queue.print();

    return (0);
}
