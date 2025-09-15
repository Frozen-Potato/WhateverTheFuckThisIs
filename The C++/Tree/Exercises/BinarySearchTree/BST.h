#ifndef BST_H
#define BST_H

#include <iostream>

class BST{
    public:
        BST();
        ~BST();


        bool isEmpty() const;
        void insert(int x);
        bool contains(int x) const; 
        void remove(int x);
        void printTree(std::ostream &out = std::cout) const;

        int findMin() const;                 
        int findMax() const;

        void makeEmpty();
    
    private:
        struct Node {
            int element;
            Node* left;
            Node* right;

            Node(int e, Node* l = nullptr, Node* r = nullptr)
                : element(e), left(l), right(r) {}
        };

        Node* root;

        void insert(int x, Node*& t);
        bool contains(int x, Node* t) const;
        void remove(int x, Node*& t);
        void makeEmpty(Node*& t);
        void printTree(Node* t, std::ostream &out) const;

        Node* findMin(Node* t) const;
        Node* findMax(Node* t) const;
};


#endif
