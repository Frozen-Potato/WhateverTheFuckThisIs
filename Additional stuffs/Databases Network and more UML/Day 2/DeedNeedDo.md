# Day 2 – Data Intergration

---

## Main Purposes:
- Use-case Diagram
- Database Diagram (Entity-Relationship Diagram)
- Initial setup for adding Postgre (SQL) and Mongo(NonSQL)

---

## Objectives
- Implement the first working persistence for media and members using PostgreSQL.
- Log borrow/return actions to MongoDB.
- Ensure consistency: write to Mongo **only after** successful SQL transaction.

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

## QA
How to do enviroment variable ?