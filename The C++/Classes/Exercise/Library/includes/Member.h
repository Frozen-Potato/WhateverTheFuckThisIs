#ifndef MEMBER_H
#define MEMBER_H

#include "Media.h"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>

class Member {
public:
    int id;
    std::string name;
    std::vector<int> borrowedItems;

    Member();
    Member(int id, const std::string& name);
    virtual ~Member() = default;

    virtual int getBorrowLimit() = 0;

    void borrowItem(const std::shared_ptr<Media>& item);
    void returnItem(std::shared_ptr<Media>& item);

    bool hasBorrowed(int itemId) const;
    bool allBorrowedUnavailable(const std::unordered_map<int, std::shared_ptr<Media>>& libItems) const;

    const std::string& getName() const;
    bool operator==(Member& person);

    friend std::ostream& operator<<(std::ostream& out, const Member& mem);
};

#endif
