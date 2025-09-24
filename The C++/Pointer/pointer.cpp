#include <iostream>
using namespace std;

void passByValue(int x){
    x+=5;
}

void passByReference(int& x){
    x+=5;
}

void passByPointer(int* x){
    *x+=5;
}

void print(int& x){
    cout << "[lvalue] = " << x << "\n";
}

void print(int&& x){
    cout << "[rvalue] = " << x << "\n";
}

void acceptBoth(const int& x){
    cout << "This can be either lvalue or rvalue : " << x << "\n";
}

int main() {
    int a = 5;
    int* p = &a;
    int** p1 = &p;

    cout << "a = " << a << endl;
    cout << "p = " << p << " (address of a)" << endl;
    cout << "p1 = " << p1 << " (address of p)" << endl;

    cout << "*p = " << *p << " (value of a)" << endl;
    cout << "*p1 = " << *p1 << " (value of p/address of a)" << endl;
    cout << "**p1 = " << **p1 << " (value of a)" << endl;

    passByValue(a);
    cout << "After pass-by-value: a = " << a << endl;
    passByReference(a);
    cout << "After pass-by-reference: a = " << a << endl;
    passByPointer(&a);
    cout << "After pass-by-pointer: a = " << a << endl;

    print(a);

    print(a + *p);

    acceptBoth(a);
    acceptBoth(a + *p);

    return 0;
}