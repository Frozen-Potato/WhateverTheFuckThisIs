# Day 4 – Even more

---

## Objectives
- Explore C++17/20/23 features that enrich generic programming.
- Work with basic concurrency.

---

## Details planned objectives

- Use `auto`, `decltype`, and `decltype(auto)` in templates.
- Experiment with if `constexpr` in template logic.
- Use `std::thread` to simulate multiple members borrowing simultaneously.
- Use `std::mutex` or `std::scoped_lock` to protect access to the Library

---

## UML Exercise
1. Draw a *state diagram* for Book:
  - Available → Borrowed → Returned → Archived.
2. Draw a *deployment diagram*:
  - Show Library as server and Members as clients.