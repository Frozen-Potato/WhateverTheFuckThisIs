# Day 2 – Generic Programming and the STL

---

## Objectives
- Strengthen use of templates and generic utilities, add to an custom **Ultis** namespace for expandabillity and reusablity.
- Apply a wider range of STL algorithms.
- Practise functors and lambdas.
- Produce UML sequence and package diagrams.

---

## Details planned objectives

### 1. Template Utilities
- Implement:
  ```cpp
  template <typename Container>
  void printContainer(const Container& c);
  ```
- Use it to display members and books.

### 2. Generic Search
- Implement:
  ```cpp
  template <typename T>
  T* findById(const std::unordered_map<int,T>& map, int id);
  ```

### 3. STL Algorithms
- Use `std::find_if` in `findBook()`.
- Use `std::count_if` to tally available books.
- Use `std::erase_if` for removing unavailable books.
- Use `std::for_each` with lambdas to print members or books.
- Use `std::transform` to convert all titles to uppercase.

### 4. Functors and Lambdas
- Define a functor `BorrowOperation` that attempts to borrow a book.
- Replace the functor with a lambda inside `Library::borrowBook()`.

### 5. Sorting
- Use `std::sort` to order books by title with a custom comparator.
- Extend to multi-field comparison (e.g. sort by author, then title).

---

## UML
Draw a UML **sequence diagram** for `borrowBook()` and `returnBook()`.
