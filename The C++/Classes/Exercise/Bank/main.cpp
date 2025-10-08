#include "BankAccount.h"
#include <iostream>

void printReadonly(const Account& acc) {
    std::cout << "Readonly balance: " << acc.balance() << "\n";
}

int main() {
    std::cout << "Bank name: " << BankAccount::name() << "\n\n";

    // Default constructor
    BankAccount a;
    std::cout << "Created account a (default contructor)\n";

    // Parameterized constructor
    BankAccount b(500.0);
    std::cout << "Created account b (init=500)\n";

    // Delegating constructor
    BankAccount c("starter");
    std::cout << "Created account c (promo)\n";

    // Copy constructor
    BankAccount d = b;
    std::cout << "Copied account b -> d\n";

    // Move constructor
    BankAccount e = std::move(c);
    std::cout << "Moved account c -> e\n";

    // Operator+=
    b += 200.0;
    std::cout << "Deposited 200 into b\n";

    // Deposit and Withdraw
    a.deposit(100.0);
    a.withdraw(40.0);

    // Operator+
    BankAccount f = b + 50.0;
    BankAccount g = 25.0 + b;

    // Equality operator
    std::cout << "Is b == d? " << (b == d ? "yes" : "no") << "\n";

    // Const correctness
    printReadonly(b);
    std::cout << "b.getBalance() = " << b.getBalance() << "\n";

    // Polymorphism
    Account* poly = &b;
    poly->applyMonthly(); // calls BankAccount::applyMonthly

    // Operator<<
    std::cout << "\n--- Accounts ---\n";
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "d: " << d << "\n";
    std::cout << "e: " << e << "\n";
    std::cout << "f: " << f << "\n";
    std::cout << "g: " << g << "\n";

    // Friend class Auditor
    std::cout << "\n--- Auditor peek ---\n";
    Auditor::peek(b);

    // Static member
    std::cout << "\nLive accounts: " << BankAccount::count << "\n";

    return 0;
}
