#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>

int main() {
    Library lib;

    // Add some books
    lib.addBook(1, "The C++ Programming Language", "Bjarne Stroustrup");
    lib.addBook(2, "Effective Modern C++", "Scott Meyers");
    lib.addBook(3, "Clean Code", "Robert C. Martin");

    // Add members 
    lib.addMember<Student>(100, 100, "Alice");
    lib.addMember<Teacher>(200, 200, "Prof. Bob");

    std::cout << "\n--- Listing Books ---\n";
    lib.listBook();

    std::cout << "\n--- Listing Members ---\n";
    lib.listMember();

    std::cout << "\n--- Borrowing Books ---\n";
    lib.borrowBook(1, 100); 
    lib.borrowBook(1, 200); 
    lib.borrowBook(2, 200); 

    std::cout << "\n--- Listing Books After Borrow ---\n";
    lib.listBook();

    std::cout << "\n--- Returning Books ---\n";
    lib.returnBook(1, 100); 
    lib.returnBook(2, 200); 

    std::cout << "\n--- Listing Books After Return ---\n";
    lib.listBook();

    // operator== for books
    auto b1 = lib.findBook(1);
    auto b2 = lib.findBook(2);
    if (b1 && b2) {
        std::cout << "\nBook 1 == Book 2 ? " << ((*b1 == *b2) ? "Yes" : "No") << "\n";
    }

    // polymorphism: getBorrowLimit
    auto alice = lib.findMember(100);
    auto bob   = lib.findMember(200);
    if (alice) std::cout << "Alice borrow limit: " << alice->getBorrowLimit() << "\n";
    if (bob)   std::cout << "Bob borrow limit: " << bob->getBorrowLimit() << "\n";

    std::cout << "\n--- Potato high on caffein @2AM ---\n";
    return 0;
}
