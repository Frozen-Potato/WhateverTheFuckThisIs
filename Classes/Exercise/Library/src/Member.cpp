#include "Member.h"
#include "Book.h"
#include <iostream>

Member::Member() : id(0), name("Unnamed") {}

Member::Member(int id,const std::string& name) : id(id), name(std::move(name)) {}

int Member::getBorrowLimit() {
    return 0;
}

void Member::borrowBook(Book& book) {
    if (book.getAvailability()) {
        book.setAvailability(false);
        std::cout << name << " borrowed " << book << std::endl;
    } else {
        std::cout << "Book not available!" << std::endl;
    }
}

void Member::returnBook(Book& book) {
    book.setAvailability(true);
    std::cout << name << " returned " << book << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Member& mem) {
    out << "Member[ID=" << mem.id << ", Name=" << mem.name << "]";
    return out;
}
