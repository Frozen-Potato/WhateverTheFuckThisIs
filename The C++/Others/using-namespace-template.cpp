#include <string>
#include <iostream>
#include <vector>
#include <sstream>

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

    std::string operator*(const std::string& s, const int& x){
        std::string result;
        result.reserve(s.size() * x);
        for (int i = 0; i < x; ++i) result += s;
        return result;
    }

    std::string operator*(const int& x, const std::string& s){
        return s * x;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const std::vector<T>& x){
        out << "[";
        for(const auto& i : x){
            out << "\"" << i << "\" ";
        }
        out << "]";
        return out;
    }

    template <typename T>
    T multiply(const T& x){
        return x*x;
    }

    template <typename T, typename R>
    auto multiply(const T& x,const R& y) {
        return x*y;
    }

    template<typename T>
    std::string multiply(const std::vector<T>& x){
        std::ostringstream oss;
        oss << "It is stupid to multiply a vector: " << x << " to itself :P";
        return oss.str();
    }

    template <typename T>
    void print(T& x){
        std::cout << "This is libB print: [lvalue] " << x << "\n";       
    };

    template <typename T>
    void print(T&& x){
        std::cout << "This is libB print: [rvalue] " << x << "\n";       
    };

    template <typename T>
    void typeOfArg(T& x){
        std::cout << "Type of arg (libB) :" << typeid(x).name() << "\n";
    }
}

int main() {
    using std::string;
    using libA::printR;
    int a = 3;
    string str = "abc";
    std::vector<string> arr = {"lol", "fuck u"};
    std::vector<std::vector<int>> arr2 = {{1,2,4}, {2,2,3}};

    libA::print(a);
    libA::typeOfArg(a);

    libB::print(str);
    libB::typeOfArg(str);
    
    printR("this is rvalue");

    std::cout << "Using overload operator* to multiply string (custom logic): \n";

    string dumbResult = libB::multiply(str, a);
    libB::print(dumbResult);
    string result =  libB::multiply(str);
    libB::print(result);
    libB::print(libB::multiply(str, 4));
    libB::print(libB::multiply(std::vector<int> {1,2,3}));
    libB::print(libB::multiply(arr));
    libB::print(libB::multiply(arr2));
    return 1;
}