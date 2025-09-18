#include <iostream>
#include <memory>

using namespace std;

struct Demo
{
    int value;
    Demo(int x) : value(x) { cout << "Struct " << value << "\n"; };
    ~Demo() { cout << "Detruct " << value << "\n"; };
};

int main(){
    unique_ptr<Demo> a = make_unique<Demo>(10);
    unique_ptr<Demo> b = move(a);

    shared_ptr<Demo> c = make_shared<Demo>(11);
    shared_ptr<Demo> d = c;
    cout << "c.use_count() = " << c.use_count() << "\n";
    cout << "d.use_count() = " << d.use_count() << "\n";
    
    return 0;
}
