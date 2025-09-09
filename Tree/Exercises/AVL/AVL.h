#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <algorithm>

using namespace std;

class AVLTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        int height;
        Node(const int value, Node* lptr = nullptr, Node* rptr = nullptr, int h = 1)
            : value(value), left(lptr), right(rptr), height(h) {}
    };

    Node* root;

    int height(Node* node) const;
    int getBalance(Node* node) const;
    void printTree(Node* node, ostream& out) const;
    void chopTree(Node*& node);


    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* leftRightRotate(Node* t);
    Node* rightLeftRotate(Node* t);

    Node* insert(Node* node, int key);
    Node* minValueNode(Node* node) const;
    Node* remove(Node* node, int key);


public:
    AVLTree();
    ~AVLTree();

    void insert(int key);
    void remove(int key);
    void printTree(ostream &out = cout) const;
    void emptyTree();
};

#endif