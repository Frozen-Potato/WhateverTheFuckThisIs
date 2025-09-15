#include "Book.h"
#include <iostream>

using namespace std;

Book::Book() : id(0), title(""), author(""), isAvailable(true){
    ++count;
}

Book::Book(int id,const string& title,const string& author)
    : id(id), title(move(title)), author(move(author)), isAvailable(true){
    ++count;
}

Book::~Book() {
    --count;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setAvailability(bool newStatus) {
    isAvailable = newStatus;
}

bool Book::operator==(const Book& rhs) const {
    return id == rhs.id;
}

ostream& operator<<(ostream& out, const Book& book) {
    out << "Book[ID=" << book.id
        << ", Title=" << book.title
        << ", Author=" << book.author
        << ", Available=" << (book.isAvailable ? "Yes" : "No")
        << "]";
    return out;
}
