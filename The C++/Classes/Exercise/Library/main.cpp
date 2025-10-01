#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include "Ultis.h"
#include <iostream>
#include <thread>

void borrowTask(Library& lib, int memberId, int itemId) {
    try {
        lib.borrowItem(itemId, memberId);
        std::cout << "Member " << memberId << " borrowed item " << itemId << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error (Member " << memberId << "): " << e.what() << "\n";
    }
}

int main() {
     Library lib;

    // Add books
    lib.addBook(1, "The C++ Programming Language", "Bjarne Stroustrup");
    lib.addBook(2, "Effective Modern C++", "Scott Meyers");
    lib.addBook(3, "Clean Code", "Robert C. Martin");
    lib.addBook(4, "The C++ Programming Language v 2", "Bjarne Stroustrup");
    lib.addBook(5, "Effective Modern C++ v 2", "Scott Meyers");
    lib.addBook(6, "Clean Code v 2", "Robert C. Martin");

    // Add magazines
    lib.addMagazine(10, "C++ Weekly", 42);
    lib.addMagazine(11, "Software Design", 7);

    // Add members
    lib.addMember<Student>(100, 100, "Alice");
    lib.addMember<Teacher>(200, 200, "Prof. Bob");

    std::cout << "\n--- Listing Items ---\n";
    lib.listItems();

    std::cout << "\n--- Listing Members ---\n";
    lib.listMembers();

    std::cout << "\n--- Borrowing Items ---\n";
    try {
        lib.borrowItem(1, 100);   // Alice borrows book 1
        lib.borrowItem(2, 200);   // Bob borrows book 2
        lib.borrowItem(10, 200);  // Bob borrows magazine 10
    } catch (const std::exception& ex) {
        std::cerr << "Borrow error: " << ex.what() << "\n";
    }

    std::cout << "\n---Also borrow but this time with thread ---\n";
    // Threads simulate concurrent borrowing
    std::vector<std::thread> threads;
    threads.emplace_back(borrowTask, std::ref(lib), 100, 5);
    threads.emplace_back(borrowTask, std::ref(lib), 200, 5); // Race on the same book
    threads.emplace_back(borrowTask, std::ref(lib), 100, 2);

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "\n--- Listing Items After Borrow ---\n";
    lib.listItems();

    std::cout << "\n--- Returning Items ---\n";
    try {
        lib.returnItem(1, 100);   // Alice returns book 1
        lib.returnItem(2, 200);   // Bob returns book 2
    } catch (const std::exception& ex) {
        std::cerr << "Return error: " << ex.what() << "\n";
    }

    std::cout << "\n--- Listing Items After Return ---\n";
    lib.listItems();

    // operator== for items (here, compare books)
    auto b1 = lib.findItemById(1);
    auto b2 = lib.findItemById(2);

    // polymorphism: getBorrowLimit
    auto alice = lib.findMemberById(100);
    auto bob   = lib.findMemberById(200);
    if (alice) std::cout << "Alice borrow limit: " << alice->getBorrowLimit() << "\n";
    if (bob)   std::cout << "Bob borrow limit: " << bob->getBorrowLimit() << "\n";

    // STL utilities and reports
    std::cout << "\n--- Available Items Count ---\n";
    std::cout << "Available: " << lib.countAvailableItems() << "\n";

    std::cout << "\n--- Sorted Items by Title ---\n";
    auto sorted = lib.getSortedByTitle();
    Ultis::printContainer(sorted);


    std::cout << "\n--- Potato high on caffein @2AM ---\n";
    return 0;
}
