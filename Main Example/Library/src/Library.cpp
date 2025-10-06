// #include "Library.h"
// #include "Ultis.h"
// #include <iostream>

// Library::Library() {}

// Library::~Library() {}

// void Library::addBook(int id, const std::string& title, const std::string& author) {
//     books.emplace(id, std::make_shared<Book>(id, author, title));
// }

// std::shared_ptr<Book> Library::findBookById(int id) {
//     return Ultis::findById(books, id);
// }

// std::shared_ptr<Book> Library::findBookByName(std::string name) {
//     return Ultis::findByName(books, name, [](const Book& b){ return b.getName(); });
// }

// void Library::removeBook(int id) {
//     books.erase(id);
// }

// std::shared_ptr<Member> Library::findMemberById(int id) {
//     return Ultis::findById(members, id);
// }

// std::shared_ptr<Member> Library::findMemberByName(std::string name) {
//     return Ultis::findByName(members, name, [](const Member& m){ return m.getName(); });
// }

// void Library::removeMember(int id) {
//     members.erase(id);
// }

// void Library::borrowBook(int bookId, int memberId) {
//     auto book = findBookById(bookId);
//     auto member = findMemberById(memberId);

//     if (book && member) {
//         auto borrowOp = [member](const std::shared_ptr<Book>& b) {
//             if (!member) {
//                 throw GeneralFailure("No member provided");
//             }
//             if (!b) {
//                 throw GeneralFailure("No book provided");
//             }
//             member->borrowBook(b);
//         };
//     } else {
//         throw GeneralFailure("Book or Member not found");
//     };
// }

// void Library::returnBook(int bookId, int memberId) {
//     auto book = findBookById(bookId);
//     auto member = findMemberById(memberId);
//     if (book && member) {
//         member->returnBook(book);
//     } else {
//         throw GeneralFailure("Book or Member not found");
//     };
// }

// void Library::removeDeadStock(){
//     std::erase_if(books, [](const auto& pair){return !pair.second->getAvailability();});
// }

// size_t Library::countAvailableBooks() const {
//     return std::count_if(books.begin(), books.end(), [](auto& pair) {return pair.second->getAvailability();});
// }

// void Library::upperCasified() {
//     std::for_each(books.begin(), books.end(),[](auto& pair){
//         std::string title = pair.second->getName();
//         std::transform(title.begin(), title.end(), title.begin(), [](unsigned char c) { return std::toupper(c); } );
//         pair.second->setName(title);
//     });
// }

// std::vector<std::shared_ptr<Book>> Library::getSortedByTitle() const{
//     std::vector<std::shared_ptr<Book>> sorted;
//     sorted.reserve(books.size());

//     for (const auto& [id, book] : books) {
//         sorted.push_back(book);
//     }

//     std::sort(sorted.begin(), sorted.end(), [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b) { return a->getName() < b->getName();});

//     return sorted;
// };

// std::vector<std::shared_ptr<Book>> Library::getSortedByAuthorAndTitle() const{
//     std::vector<std::shared_ptr<Book>> sorted;
//     sorted.reserve(books.size());

//     for (const auto& [id, book] : books) {
//         sorted.push_back(book);
//     }

//     std::sort(sorted.begin(), sorted.end(), [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b) {
//         if (a->getAuthor() == b->getAuthor()) {
//             return a->getName() < b->getName();
//         }
//         return a->getAuthor() < b->getAuthor();
//     });

//     return sorted;
// };


// void Library::listBooks() const {
//     // for (const auto& [id, book] : books) {
//     //     std::cout << *book << std::endl;
//     // }
//     std::for_each(books.begin(), books.end(), [](const auto& pair) { std::cout << *pair.second << std::endl;});
// }

// void Library::listMembers() const {
//     // for (const auto& [id, member] : members) {
//     //     std::cout << *member << std::endl;
//     // }
//     std::for_each(members.begin(), members.end(), [](const auto& pair) { std::cout << *pair.second << std::endl;});
// }

#include "Library.h"
#include "Book.h"
#include "Magezine.h"
#include "Ultis.h"
#include <iostream>

Library::Library() {}
Library::~Library() {}

void Library::addBook(int id, const std::string& title, const std::string& author) {
    items.emplace(id, std::make_shared<Book>(id, title, author));
}

void Library::addMagazine(int id, const std::string& title, int issueNumber) {
    items.emplace(id, std::make_shared<Magazine>(id, title, issueNumber));
}

std::shared_ptr<Media> Library::findItemById(int id) {
    return Ultis::findById(items, id);
}

std::shared_ptr<Media> Library::findItemByName(const std::string& name) {
    return Ultis::findByName(items, name, [](const Media& m){ return m.getName(); });
}

void Library::removeItem(int id) {
    items.erase(id);
}

std::shared_ptr<Member> Library::findMemberById(int id) {
    return Ultis::findById(members, id);
}

std::shared_ptr<Member> Library::findMemberByName(const std::string& name) {
    return Ultis::findByName(members, name, [](const Member& m){ return m.getName(); });
}

void Library::removeMember(int id) {
    members.erase(id);
}

void Library::borrowItem(int itemId, int memberId) {
    std::scoped_lock lock(mtx);
    auto item = findItemById(itemId);
    auto member = findMemberById(memberId);

    if (item && member) {
        member->borrowItem(item);
    } else {
        throw GeneralFailure("Item or Member not found");
    }
}

void Library::returnItem(int itemId, int memberId) {
    std::scoped_lock lock(mtx);
    auto item = findItemById(itemId);
    auto member = findMemberById(memberId);

    if (item && member) {
        member->returnItem(item);
    } else {
        throw GeneralFailure("Item or Member not found");
    }
}

void Library::removeUnavailableItems() {
    std::erase_if(items, [](const auto& pair) { return !pair.second->getAvailability(); });
}

size_t Library::countAvailableItems() {
    return std::count_if(items.begin(), items.end(), [](const auto& pair) {
        return pair.second->getAvailability();
    });
}

void Library::upperCasified() {
    std::for_each(items.begin(), items.end(), [](auto& pair) {
        std::string title = pair.second->getName();
        std::transform(title.begin(), title.end(), title.begin(),
                       [](unsigned char c) { return std::toupper(c); });
        pair.second->setName(title);
    });
}

std::vector<std::shared_ptr<Media>> Library::getSortedByTitle() {
    std::vector<std::shared_ptr<Media>> sorted;
    sorted.reserve(items.size());

    for (const auto& [id, item] : items) {
        sorted.push_back(item);
    }

    std::sort(sorted.begin(), sorted.end(),
              [](const std::shared_ptr<Media>& a, const std::shared_ptr<Media>& b) {
                  return a->getName() < b->getName();
              });

    return sorted;
}

void Library::listItems() {
    std::for_each(items.begin(), items.end(),
                  [](const auto& pair) { std::cout << *pair.second << std::endl; });
}

void Library::listMembers() {
    std::for_each(members.begin(), members.end(),
                  [](const auto& pair) { std::cout << *pair.second << std::endl; });
}

