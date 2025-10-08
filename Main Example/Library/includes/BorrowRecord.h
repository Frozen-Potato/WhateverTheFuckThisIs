#ifndef BORROW_RECORD_H
#define BORROW_RECORD_H

#include <chrono>
#include <optional>

struct BorrowRecord {
    int userId;
    int mediaId;
    std::chrono::system_clock::time_point borrowTime;
    std::optional<std::chrono::system_clock::time_point> returnTime;
};

#endif
