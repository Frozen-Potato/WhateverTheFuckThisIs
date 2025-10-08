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

std::shared_ptr<User> Library::findUserById(int id) {
    return Ultis::findById(users, id);
}

std::shared_ptr<User> Library::findUserByName(const std::string& name) {
    return Ultis::findByName(users, name, [](const User& m){ return m.getName(); });
}

void Library::removeUser(int id) {
    users.erase(id);
}

void Library::borrowItem(int itemId, int userId) {
    std::scoped_lock lock(mtx);
    auto item = findItemById(itemId);
    auto user = findUserById(userId);

    if (item && user) {
        auto member = std::dynamic_pointer_cast<Member>(user);
        if (member) {
            member->borrowItem(item);
            borrowHistory.emplace_back(userId, itemId);
        } else {
            throw GeneralFailure("This user type cannot borrow items");
        }
    } else {
        throw GeneralFailure("Item or User not found");
    }
}


void Library::returnItem(int itemId, int userId) {
    std::scoped_lock lock(mtx);
    auto item = findItemById(itemId);
    auto user = findUserById(userId);

    if (item && user) {
        auto member = std::dynamic_pointer_cast<Member>(user);
        if (member) {
            member->borrowItem(item);
            auto it = std::find_if(borrowHistory.begin(), borrowHistory.end(), [&](const BorrowRecord& rec) {
                return rec.userId == userId && rec.mediaId == itemId && !rec.returnTime.has_value();
            });

            if (it != borrowHistory.end()) {
                it->returnTime = std::chrono::system_clock::now();
            }
        } else {
            throw GeneralFailure("This user type cannot return items");
        }
    } else {
        throw GeneralFailure("Item or User not found");
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

void Library::listUsers() {
    std::for_each(users.begin(), users.end(),
                  [](const auto& pair) { std::cout << *pair.second << std::endl; });
}

