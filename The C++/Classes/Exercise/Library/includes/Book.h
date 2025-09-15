#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
    private:
        int id;
        std::string title;
        std::string author;
        bool isAvailable;
    public:
        inline static size_t count = 0;

        Book();
        explicit Book(int id,const std::string& title,const std::string& author);
        Book(const Book& other);

        Book& operator=(const Book& other);                                                                                                                                                                                                                                     

        ~Book();

        bool getAvailability() const;
        void setAvailability(bool newStatus);
        bool operator== (const Book& rhs) const;
        friend std::ostream& operator<<(std::ostream& out, const Book& book);

};

#endif