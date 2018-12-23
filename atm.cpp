#include <iostream>
#include <math.h>
using namespace std;

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

void dispense_money (int money, banknotes *cash) {

    int dispensed[3] = {0, 0, 0};

    for (int i=0; money > 0; i++) {

        dispensed[i] = floor (money / cash[i].get_face_value());
        if (dispensed[i] > cash[i].get_quantity ())
            dispensed[i] = cash[i].get_quantity ();

        money = money - cash[i].get_face_value() * dispensed[i];
        cash[i].set_quantity (cash[i].get_quantity() - dispensed[i]);
    }

    for (int i=0; i < 3; i++) {

        if (dispensed[i] != 0) {

            if (dispensed[i] == 1)
                cout << dispensed[i] << " notebank of " << cash[i].get_face_value() << " COP" << endl;
            else
                cout << dispensed[i] << " notebanks of " << cash[i].get_face_value() << " COP" << endl;

        }
    }
}

int total_cash (banknotes *cash) {

    int total = 0;

    for (int i=0; i<3; i++)
        total += cash[i].get_face_value() * cash[i].get_quantity();

    return (total);
}

int main () {

    banknotes cash[3];
    cash[0] = banknotes (50, 3);
    cash[1] = banknotes (20, 2);
    cash[2] = banknotes (10, 3);

    int money;

    do {
        cout << "How much money do you want?" << endl;
        cin >> money;

        if (money % 10 != 0)
            cout << "Invalid value, multiples of 10" << endl;
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
