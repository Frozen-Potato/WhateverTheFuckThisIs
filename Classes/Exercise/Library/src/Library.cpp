#include "Library.h"
#include <iostream>

Library::Library() {}

Library::~Library() {}

void Library::addBook(int id, const std::string& title, const std::string& author) {
    books.emplace(id, std::make_shared<Book>(id, author, title));
}

std::shared_ptr<Book> Library::findBook(int id) {
    auto it = books.find(id);
    return (it != books.end()) ? it->second : nullptr;
}

void Library::removeBook(int id) {
    books.erase(id);
}

std::shared_ptr<Member> Library::findMember(int id) {
    auto it = members.find(id);
    return (it != members.end()) ? it->second : nullptr;
}

void Library::removeMember(int id) {
    members.erase(id);
}

void Library::borrowBook(int bookId, int memberId) {
    auto book = findBook(bookId);
    auto member = findMember(memberId);
    if (book && member) {
        member->borrowBook(*book);
    }
}

void Library::returnBook(int bookId, int memberId) {
    auto book = findBook(bookId);
    auto member = findMember(memberId);
    if (book && member) {
        member->returnBook(*book);
    }
}

void Library::listBook() const {
    for (const auto& [id, book] : books) {
        std::cout << *book << std::endl;
    }
}

void Library::listMember() const {
    for (const auto& [id, member] : members) {
        std::cout << *member << std::endl;
    }
}
