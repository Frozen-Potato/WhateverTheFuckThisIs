#include <string>
#include <iostream>

namespace libA {
    template <typename T>
    void print(T& x){
        using std::cout;
        cout << "This is libA print: " << x << "\n";
    }

    template <typename T>
    void printR(T&& x){
        using std::cout;
        cout << "This is libA print rvalue: " << x << "\n";
    }

    template <typename T>
    void typeOfArg(T& x){
        std::cout << "Type of arg (libA) :" << typeid(x).name() << "\n";
    }
}

namespace libB {
    std::string operator*(const std::string& ls, const std::string& rs) {
        std::string result;
        result.reserve(ls.size() * rs.size());
        for (int i = 0; i < ls.size(); ++i) {
            result += ls;
        }
        return result;
    }

    template <typename T>
    T multiply(T& x){
        return x*x;
    }

    template <typename T>
    void print(T& x){
        std::cout << "This is libB print: " << x << "\n";       
    };

    template <typename T>
    void typeOfArg(T& x){
        std::cout << "Type of arg (libB) :" << typeid(x).name() << "\n";
    }
}

int main() {
    using std::string;
    using libA::printR;
    int a = 1;
    string str = "abc";

    libA::print(a);
    libA::typeOfArg(a);

    libB::print(str);
    libB::typeOfArg(str);
    
    printR("this is rvalue");

    std::cout << "Using overload operator* to multiply string (custom logic): \n";
    string result =  libB::multiply(str);
    libB::print(result);

    return 1;
}