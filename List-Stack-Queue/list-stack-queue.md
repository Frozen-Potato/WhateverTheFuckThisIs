## Theory

-**List**
    List is a sequence of node, each holding data and links (singly or doubly)
    Types:
        - Single-linked list (each node has link to the next node) ``std::forward_list``
        - Double-linked list (each node mantained a prev and next) ``std::list``
    Both ``List`` and ``Vector`` are class template with some common methods. Example: 
        - ``int size()``
        - ``void clear()``
        - ``bool empty() const``
        - ``void push_back(const Object & x)``
        - ``void pop_back()``
        - ``const Object & back() const``
        - ``const Object & front() const``
-**Stack**
    is a List with restriction of insertion and deletion can only be perform in one position, at the end of the list(LIFO)
-**Queue**
    Also a list but insertion and deletion are done on 2 opposite end.
    
    