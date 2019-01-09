#include <iostream>
#include <stdlib.h>
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

        node <T> *head, *p, *last;

    public:

        list(): head(NULL), p(NULL), last(NULL) {}

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

        bool is_empty () {

            return (head == NULL);
        }

        //inserts a node at the beginning of the list
        void append (T x) {

            p = new node <T> (x);

            if (head == NULL) {

                head = p;
                last = head;
            }
            else {

                p->next = head;
                head = p;
            }
        }

        //inserts a node at the end of the list
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

        void pop () {

            if (is_empty())
                cout << "empty list.";
            else if (head == last)
                head = last = NULL;
            else {

                for (p = head; p->next != last; p = p->next);
                delete (last);
                last = p;
                last->next = NULL;
            }
        }

        void delete_at (int i) {

            if (is_empty())
                cout << "empty list.";
            else if (i < size()) {

                p = head;

                if (i == 0) {

                    head = p->next;
                    delete (p);
                }
                else {

                    for (int j=0; j < i-1; j++)
                        p = p->next;

                    node <T> *tmp = p->next;
                    if (tmp->next != NULL) {

                        p->next = tmp->next;

                    }
                    else {
                        last = p;
                        last->next = NULL;
                    }

                    delete (tmp);
                }
            }
            else
                cout << "Invalid index." << endl;
        }

        void print () {

            for (p = head; p != NULL; p = p->next)
                cout << p->get_data() << " ";

            cout << endl;
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

    //initializing random seed
    srand (time(NULL));

    list <int> l;

    cout << "Is the list empty? " << l.is_empty() << endl;
    l.push(rand() % 100);
    l.push(rand() % 100);
    l.push(rand() % 100);
    l.append(rand() % 100);
    l.push (rand() % 100);
    cout << "Is the list still empty? " << l.is_empty() << endl;
    cout << "l[2] = " << l[2] << endl << endl;
    cout << "size of the list: " << l.size() << endl;
    l.print ();

    l.pop ();
    l.print();

    l.delete_at (0);
    l.print ();
    l.delete_at (10);

    return (0);
}
