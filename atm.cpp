#include <iostream>
#include <math.h>
using namespace std;

#define N 3

class banknotes {

    private:

        int face_value;
        int quantity;

    public:

        banknotes() {}
        banknotes(int fv, int q): face_value(fv), quantity(q) {}

        int get_face_value () {

            return (face_value);
        }

        int get_quantity () {

            return (quantity);
        }

        void set_quantity (int new_q) {

            quantity = new_q;
        }
};

void return_money (banknotes *cash, int *dispensed) {

    for (int i=0; i < N; i++)
        cash[i].set_quantity(cash[i].get_quantity() + dispensed[i]);
}


int total_cash (banknotes *cash) {

    int total = 0;

    for (int i=0; i<N; i++)
        total += cash[i].get_face_value() * cash[i].get_quantity();

    return (total);
}

void dispense_money (int money, banknotes *cash) {

    int dispensed[N] = {0, 0, 0};

    for (int i=0; money > 0 && i < N; i++) {

        dispensed[i] = floor (money / cash[i].get_face_value());
        if (dispensed[i] > cash[i].get_quantity ())
            dispensed[i] = cash[i].get_quantity ();

        money = money - cash[i].get_face_value() * dispensed[i];
        cash[i].set_quantity (cash[i].get_quantity() - dispensed[i]);
    }

    if (money > 0) {

        return_money(cash, dispensed);
        cout << "ATM doesn't have notebanks to dispense that money" << endl;
    }

    else {

        for (int i=0; i < N; i++) {

            if (dispensed[i] != 0) {

                if (dispensed[i] == 1)
                    cout << dispensed[i] << " notebank of " << cash[i].get_face_value() << " COP" << endl;
                else
                    cout << dispensed[i] << " notebanks of " << cash[i].get_face_value() << " COP" << endl;

            }
        }
    }

    cout << "Total cash: " << total_cash(cash) << endl;
}

bool possible (int money, banknotes *cash) {

    bool flag = false;
    for (int i=0; i < N; i++)
        if (money % cash[i].get_face_value() == 0 && cash[i].get_quantity() != 0)
            flag = true;

    return (flag);
}

int main () {

    banknotes cash[N];
    cash[0] = banknotes (50, 3);
    cash[1] = banknotes (20, 3);
    cash[2] = banknotes (10, 3);

    cout << "Total cash: " << total_cash(cash) << endl;

    int money;

    do {
        cout << "How much money do you want?" << endl;
        cin >> money;

        if (!possible(money, cash))
            cout << "ATM doesn't have notebanks to dispense that money" << endl;
        else {

            if (money > total_cash(cash))
                cout << "ATM doesn't have enough money" << endl;
            else
                dispense_money(money, cash);
        }
    }
    while (money != 0);

    return (0);
}
