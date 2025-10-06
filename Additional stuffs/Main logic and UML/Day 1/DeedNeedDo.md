# Day 1 – Improve the foundation of the [library](../../../Main%20Example/Library/)

One must begin, as the Victorians might say, with “a proper foundation.”  
Today’s labours focus on strengthening the object-oriented skeleton of the Library Management System, ensuring it behaves less like a rickety shed and more like a fine piece of Edwardian architecture.

---

## Objectives
- Enforce borrowing limits with exception handling.
- Track borrowed books per member with STL algorithms.
- Add operator overloads for richer comparisons.
- Create detailed UML diagrams (with multiplicities and visibility).

---

## Details planned objectives

### 1. Borrowing System Upgrade
- Add a `std::vector<int> borrowedBooks` to `Member`.
- In `borrowBook()`:
  - Ensure the user has not reached their borrowing limit.
  - Throw a `BorrowLimitExceeded` exception if they have.
  - Throw a `BookUnavailable` exception if the book is already on loan.
- In `returnBook()`:
  - Remove the book ID from `borrowedBooks`.
  - Use `std::find` and `erase` idiom to erase properly. (Uses Lambda function)

### 2. Operator Overloading
- Implement `operator<` for `Book`, comparing by `title` or `id`.
- Implement `operator==` for `Member`.

### 3. STL Algorithm Integration
- Use `std::any_of` to check if a member has borrowed a given book.
- Use `std::all_of` to check if all borrowed books are currently unavailable in the library (consistency check).

### 4. Exception Handling
- Define exception classes `BorrowLimitExceeded` and `BookUnavailable`.
- Ensure `Library::borrowBook()` catches and handles exceptions gracefully.

---

## UML Exercise
1. Draw a UML **class diagram** for the following classes:
   - `Library`
   - `Member` (abstract base)
   - `Student`
   - `Teacher`
   - `Book`
2. Indicate inheritance (Student and Teacher extend Member).
3. Show associations with multiplicities (`1..*`, `0..1` etc.).
4. Use visibility markers: `+` for public, `-` for private, `#` for protected.