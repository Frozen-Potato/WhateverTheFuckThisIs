#include "Member.h"
#include "Exceptions.h"
#include <iostream>

Member::Member() : id(0), name("Unnamed") {}

Member::Member(int id, const std::string& name) : id(id), name(std::move(name)) {}

void Member::borrowItem(const std::shared_ptr<Media>& item) {
    if (!item->getAvailability()) {
        throw BookUnavailable("Unavailable: " + item->getName());
    }

    if (borrowedItems.size() >= static_cast<size_t>(getBorrowLimit())) {
        throw BorrowLimitExceeded(name + " is not allowed to borrow more items");
    }

    item->setAvailability(false);
    borrowedItems.push_back(item->getId());
    std::cout << name << " borrowed " << *item << std::endl;
}

void Member::returnItem(std::shared_ptr<Media>& item) {
    auto it = std::find(borrowedItems.begin(), borrowedItems.end(), item->getId());
    if (it != borrowedItems.end()) {
        borrowedItems.erase(it);
        item->setAvailability(true);
        std::cout << name << " returned " << *item << std::endl;
    } else {
        throw GeneralFailure("Item not borrowed: " + item->getName());
    }
}

bool Member::allBorrowedUnavailable(const std::unordered_map<int, std::shared_ptr<Media>>& libItems) const {
    return std::all_of(borrowedItems.begin(), borrowedItems.end(), [&](int id) {
            auto it = libItems.find(id);
            return it != libItems.end() && !it->second->getAvailability();
        }
    );
}

bool Member::hasBorrowed(int itemId) const {
    return std::any_of(borrowedItems.begin(), borrowedItems.end(), [itemId](int id) { return id == itemId; });
}

const std::string& Member::getName() const {
    return name;
}

bool Member::operator==(Member& person) {
    return name == person.getName();
}

std::ostream& operator<<(std::ostream& out, const Member& mem) {
    out << "Member[ID=" << mem.id << ", Name=" << mem.name << "]";
    return out;
}
