#ifndef MEMBER_H
#define MEMBER_H

#include "Book.h"
#include <string>

class Member {
    public:
        int id;
        std::string name;

        Member();
        Member(int id,const std::string& name);
        virtual ~Member() = default;

        virtual int getBorrowLimit();
        void borrowBook(Book& book);
        void returnBook(Book& book);

        friend std::ostream& operator<<(std::ostream& out,const Member& mem);
};

#endif