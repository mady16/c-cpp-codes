#include <iostream>
using namespace std;

//each of the nodes of our list is a class
template <class T> class node {

    public:

        T data;
        node <T> *next;

        node(): data(NULL), next(NULL) {}
        node(T x): data(x), next(NULL) {}
};

template <class T> class list {

    private:

        node <T> *head, *p, *last, *previous;

    public:

        list(): head(NULL), p(NULL), last(NULL), previous(NULL) {}

        void push (T x) {

            p = new node <T> (x);
            p.next = head;
            head = p;
        }

};

int main () {

    node <int> *a = new node <int> (1);
    node <int> *b = new node <int> (2);
    node <int> *c = new node <int> (3);

    a->next = b;
    b->next = c;


    return (0);
}
