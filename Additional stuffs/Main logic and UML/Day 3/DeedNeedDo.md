# Day 3 – More things

---

## Objectives
- Explore move semantics in classes.
- Add interfaces and polymorphic extensions.
- Implement design patterns: Factory and Singleton.
- Apply more advanced STL algorithms and containers.
- Extend UML with component, object, and activity diagrams.

---

## Details planned objectives

### 1. Move Semantics
- Add move constructor and move assignment operator to `Book`.
- Print messages when moves occur, to distinguish from copies.

### 2. Abstract Interfaces
- Create a pure virtual class `Media`.
- Make `Book` and a new class `Magazine` implement `Media`.
- Adjust `Library` to store a collection of borrowable items.

### 3. Advanced STL Algorithms
- Use `std::lower_bound` and `std::upper_bound` with sorted collections.

### 4. Driver Program
- Write a `main.cpp` that:
  - Creates a library, adds members and items.
  - Borrows and returns items.
  - Prints reports using template utilities and STL algorithms.

---

## UML Exercise
- Draw a UML **class diagram** with the `Media` interface and `Magazine`.
- Draw the updated class diagram for Library