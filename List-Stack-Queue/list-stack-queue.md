## Theory

- **List**  
  A list is a sequence of nodes, each holding data and links (singly or doubly).  

  Types:  
  - Singly-linked list (each node has link to the next node) `std::forward_list`  
  - Doubly-linked list (each node maintains a prev and next) `std::list`  

  Both `List` and `Vector` are class templates with some common methods, for example:  
  - `int size()`  
  - `void clear()`  
  - `bool empty() const`  
  - `void push_back(const Object & x)`  
  - `void pop_back()`  
  - `const Object & back() const`  
  - `const Object & front() const`  

- **Stack**  
  A Stack is a list with restriction that insertion and deletion can only be performed at one end (LIFO).  

- **Queue**  
  A Queue is a list where insertion and deletion are done on opposite ends.


    