#include <iostream>
using namespace std;

//each of the nodes of our list is a class
template <class T> class node {

    private:

        T data;

    public:

        node <T> *next;

        node(): data(NULL), next(NULL) {}
        node(T x): data(x), next(NULL) {}

        void set (T value) {

            data = value;
        }

        T get () {

            return (data);
        }
};

template <class T>
void print (node <T> *n) {

    while (n != NULL) {

        cout << n->get() << " ";
        n = n->next;
    }
    cout << endl;
}

int main () {

    node <int> *a = new node <int> (1);
    node <int> *b = new node <int> (2);
    node <int> *c = new node <int> (3);

    a->next = b;
    b->next = c;

    a->set(15);
    b->set(16);
    c->set(17);

    print(a);


    return (0);
}
