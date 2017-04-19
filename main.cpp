using namespace std;

#include <iostream>
#include "util/fraction.h"

/*
 * Charlton Smith May 19, 2016 @ 21:27
 */

int main() {
    fraction f(-2, 8);
    fraction a(4, 8);

    cout << "Relational Operators" << endl;
    if (f < a) {
        cout << "f is less a" << endl;
    }

    if (f > a) {
        cout << "f is more than a" << endl;
    }

    if (f == a) {
        cout << "f is equal to a" << endl;
    }

    if (f != a) {
        cout << "f is not equal to a" << endl;
    }

    if (f <= a) {
        cout << "f is less than or equal to a" << endl;
    }

    if (f >= a) {
        cout << "f is more than or equal to a" << endl;
    }
    cout << endl;

    cout << "Arithmetic Operators" << endl;
    cout << f << " + " << a << ": " << (f + a) << endl;
    cout << f << " - " << a << ": " << (f - a) << endl;
    cout << f << " * " << a << ": " << (f * a) << endl;
    cout << f << " / " << a << ": " << (f / a) << endl;
    cout <<endl;

    cout << "Arithmetic Assignment Operators" << endl;
    cout << f << " += " << a << ": "<< (f+=a) << endl;
    cout << f << " -= " << a << ": "<< (f-=a) << endl;
    cout << f << " *= " << a << ": "<< (f*=a) << endl;
    cout << f << " /= " << a << ": "<< (f/=a) << endl;
    cout <<endl;

    cout << "Adding w/ integers" << endl;
    cout << f << " + 1: " << f + 1 << endl;
    cout << f << " - 1: " << f - 1 << endl;
    cout << f << " * 2: " << f * 2 << endl;
    cout << f << " / 2: " << f / 2 << endl;
    cout << endl;


    fraction t(8,2);
    cout << "Creating fraction: " << t << endl;
    t.reduce();
    cout << "Reduced fraction: (8/2 / 2) = " << t << endl;
    cout << endl;

    cout << "Accepting Value w/ cin"<<endl;
    cout << "put a fraction in the format of a/b (1 input only): ";
    fraction b;
    cin >> b;
    cout << b << endl;
    cout << endl;

    cout << "convert to decimal" << endl;
    cout << b.convert() << endl;

    return 0;
}