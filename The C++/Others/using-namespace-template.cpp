#include <string>
#include <iostream>
#include <vector>
#include <sstream>

namespace libA {
    template <typename T>
    void print(T& x){
        using std::cout;
        cout << "Using libA print: " << x << "\n";
    }

    template <typename T>
    void printR(T&& x){
        using std::cout;
        cout << "Using libA print rvalue: " << x << "\n";
    }

    template <typename T>
    void typeOfArg(T& x){
        std::cout << "Type of arg (libA): " << typeid(x).name() << "\n";
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
        std::cout << "Using libB print: [lvalue] " << x << "\n";       
    };

    template <typename T>
    void print(T&& x){
        std::cout << "Using libB print: [rvalue] " << x << "\n";       
    };

    template <typename T>
    void print(const std::string& str,T& x){
        std::cout << "[lvalue] Using libB print: " << str << " = " << x << "\n";       
    }

    template <typename T>
    void print(const std::string& str,T&& x){
        std::cout << "[rvalue] Using libB print: " << str << " = " << x << "\n";       
    }

    template <typename T>
    void typeOfArg(T& x){
        std::cout << "Type of arg (libB): " << typeid(x).name() << "\n";
    }
}

template <typename T>
class ex {
    T value;
    public:

        ex() : value{} {};
        ex(const T& x) : value(x) {};
        ex(const ex& other) : value(other.value) { std::cout << "Call Copy Ctor\n"; };
        ex(ex&& other) noexcept : value(std::move(other.value)) { std::cout << "Call Move Ctor\n"; };

        ex& operator=(const ex& other) noexcept {
            if (this != &other){
                value = other.value;
            }
            return *this;
        }

        ex& operator=(ex&& other) noexcept {
            if (this != &other) {
                value = std::move(other.value);
            }
            return *this;
        }   

        ~ex() = default;

        void show(const std::string& str) {
            libB::print(str, value);
        };
};

template <>
class ex<std::string> {
    std::string value;
    public:

        ex() : value("") {};
        ex(const std::string& x) : value(x) {};
        ex(const ex& other) : value(other.value) { std::cout << "Call String Copy Ctor\n"; };
        ex(ex&& other) noexcept : value(std::move(other.value)) { std::cout << "Call String Move Ctor\n"; };

        ex& operator=(const ex& other) noexcept {
            if (this != &other){
                value = other.value;
            }
            return *this;
        }

        ex& operator=(ex&& other) noexcept {
            if (this != &other) {
                value = std::move(other.value);
            }
            return *this;
        }   

        ~ex() = default;

        void show(const std::string& label) {
            libB::print(label, value + " (length: " + std::to_string(value.size()) + ")");
        };
};

int main() {
    using std::string;
    using libA::printR;
    int a = 3;
    string str = "abc";
    std::vector<string> arr = {"lol", "fuck u"};
    std::vector<std::vector<int>> arr2 = {{1,2,4}, {2,2,3}};

    std::cout << "Same print, different namespace libA vs libB: \n";

    libA::print(a);
    libA::typeOfArg(a);

    libB::print(str);
    libB::typeOfArg(str);
    
    std::cout << "--Using a linebreak--\n";

    printR("Using rvalue");

    std::cout << "--Using a linebreak--\n";

    std::cout << "Using overload operator* to apply custom logic: \n";

    string dumbResult = libB::multiply(str, a);
    libB::print("string * int[lvalue]", dumbResult);
    string result =  libB::multiply(str);
    libB::print("string * string", result);
    libB::print("string * int[rvalue]",libB::multiply(str, 4));
    libB::print("vector[rvalue] * vector[rvalue]",libB::multiply(std::vector<int> {1,2,3}));
    libB::print("vector[lvalue] * vector[lvalue]",libB::multiply(arr));
    libB::print("vector<vector>[lvalue] * vector<vector>[lvalue]",libB::multiply(arr2));

    std::cout << "--Using a linebreak--\n";
    std::cout << "Class template T with specialization for std::string\n";
    ex C(2);
    C.show("C");
    
    ex D = C;
    C.show("C");
    D.show("D");

    std::cout << "With specialization for std::string\n";
    ex<std::string> E("Holy fuck");
    E.show("E");

    ex F = std::move(E);
    E.show("E");
    F.show("F");
    return 1;
}