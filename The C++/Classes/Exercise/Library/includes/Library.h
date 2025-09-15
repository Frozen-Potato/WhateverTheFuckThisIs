#ifndef LIBRARY_H
#define LIBRARY_H

#include "Member.h"
#include "Book.h"

#include <algorithm>
#include <unordered_map>
#include <memory>

class Library {
    private:
        std::unordered_map<int, std::shared_ptr<Book>> books;
        std::unordered_map<int, std::shared_ptr<Member>> members;
    public:
        Library();
        ~Library();

        void addBook(int id, const std::string& title, const std::string& author);
        std::shared_ptr<Book> findBook(int id);
        void removeBook(int id);

        template<typename T, typename... Agrs>
        void addMember(int id, Agrs&&... args){
            members.emplace(id, std::make_shared<T>(std::forward<Agrs>(args)...));
        }

        std::shared_ptr<Member> findMember(int id);
        void removeMember(int id);

        void borrowBook(int bookId, int memberId);
        void returnBook(int bookId, int memberId);

        void listBook() const;
        void listMember() const;
};

#endif