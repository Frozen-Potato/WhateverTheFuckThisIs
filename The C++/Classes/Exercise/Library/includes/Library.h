// #ifndef LIBRARY_H
// #define LIBRARY_H

// #include "Member.h"
// #include "Book.h"
// #include "Exceptions.h"

// #include <algorithm>
// #include <unordered_map>
// #include <memory>

// class Library {
//     private:
//         std::unordered_map<int, std::shared_ptr<Book>> books;
//         std::unordered_map<int, std::shared_ptr<Member>> members;
//     public:
//         Library();
//         ~Library();

//         void addBook(int id, const std::string& title, const std::string& author);
//         std::shared_ptr<Book> findBookById(int id);
//         std::shared_ptr<Book> findBookByName(std::string name);
//         void removeBook(int id);

//         template<typename T, typename... Args>
//         void addMember(int id, Args&&... args){
//             members.emplace(id, std::make_shared<T>(std::forward<Args>(args)...));
//         }

//         std::shared_ptr<Member> findMemberById(int id);
//         std::shared_ptr<Member> findMemberByName(std::string name);
//         void removeMember(int id);

//         void borrowBook(int bookId, int memberId);
//         void returnBook(int bookId, int memberId);
//         void removeDeadStock();
//         void upperCasified();

//         size_t countAvailableBooks() const;

//         std::vector<std::shared_ptr<Book>> getSortedByTitle() const;
//         std::vector<std::shared_ptr<Book>> getSortedByAuthorAndTitle() const;

//         void listBooks() const;
//         void listMembers() const;
// };

// #endif

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Member.h"
#include "Media.h"
#include "Exceptions.h"

#include <algorithm>
#include <unordered_map>
#include <memory>
#include <vector>
#include <mutex>

class Library {
private:
    std::unordered_map<int, std::shared_ptr<Media>> items;   // Media replaces Book
    std::unordered_map<int, std::shared_ptr<Member>> members;
    mutable std::mutex mtx;

public:
    Library();
    ~Library();

    void addBook(int id, const std::string& title, const std::string& author);
    void addMagazine(int id, const std::string& title, int issueNumber);

    std::shared_ptr<Media> findItemById(int id);
    std::shared_ptr<Media> findItemByName(const std::string& name);
    void removeItem(int id);

    template<typename T, typename... Args>
    void addMember(int id, Args&&... args) {
        members.emplace(id, std::make_shared<T>(std::forward<Args>(args)...));
    }

    std::shared_ptr<Member> findMemberById(int id);
    std::shared_ptr<Member> findMemberByName(const std::string& name);
    void removeMember(int id);

    void borrowItem(int itemId, int memberId);
    void returnItem(int itemId, int memberId);
    void removeUnavailableItems();
    void upperCasified();

    size_t countAvailableItems();

    std::vector<std::shared_ptr<Media>> getSortedByTitle();

    void listItems();
    void listMembers();
};

#endif
