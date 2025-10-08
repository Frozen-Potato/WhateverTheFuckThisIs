# Day 1 – Improve the foundation of the [library](../../../Main%20Example/Library/) again

Having erected a respectable edifice of object-oriented timber in the first sprint, we now turn our attention to laying proper stone foundations beneath it. This second endeavour concerns itself not merely with polish, but with permanence, reinforcing our once-modest library into a sturdier institution of databases, protocols, and disciplined concurrency. In short, we tidy up the architecture before the whole contraption collapses under the weight of modernity.

---

## Main Purposes:
- Use-case Diagram
- Database Diagram (Entity-Relationship Diagram)
- Initial setup for adding Postgre (SQL) and Mongo(NonSQL)

---

## Objectives
- Add user class as pure virtual class and make member inherit (implement user interface)
- Add timestamp on user creation, borrow event and return event for log/history.
- Adding use-case diagram.
- Adding support for PostgreSQL

---

## Details planned objectives

### PostgreSQL
- Add User class as an Interface
- Install server + client libraries.
- Define schemas and data mapping for existing domain (`Book`, `Magazine`, `Member`).
- Create C++ adapters skeletons: `PostgresAdapter`.

---

## UML Exercise
1. Use Case Diagram.