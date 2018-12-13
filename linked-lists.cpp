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

        T get_data () {

            return (data);
        }
};

template <class T> class list {

    private:

        node <T> *head, *p, *last, *previous;

    public:

        list(): head(NULL), p(NULL), last(NULL), previous(NULL) {}

        ~list () {

            node <T> *n;
            for (p = head; p != NULL; p = p->next) {

                n = p->next;
                delete (p);
                p = n;
            }
            delete (n);
            cout << "list destroyed." << endl;
        }

        //inserts a node at the begining of the list
        void push (T x) {

            p = new node <T> (x);

            if (head == NULL) {

                head = p;
                last = head;
            }
            else {

                last->next = p;
                last = p;
            }

        }

        void print () {

            for (p = head; p != NULL; p = p->next)
                cout << p.get_data();
        }

        int size () {

            int size = 0;
            for (p = head; p != NULL; size++, p = p->next);
            return (size);
        }

        T operator [] (int index) {

            int i;
            for (i=0, p = head; i < index; p = p->next, i++);
            return (p->get_data());
        }
};

int main () {

    list <int> l;
    l.push(350);
    l.push(5);
    l.push(19);
    l.push(4);

    cout << l[2] << endl;
    cout << "size of the list: " << l.size() << endl;


    return (0);
}
