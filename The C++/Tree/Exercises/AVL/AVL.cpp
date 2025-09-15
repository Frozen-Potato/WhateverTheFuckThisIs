#include "AVL.h"

AVLTree::AVLTree() : root(nullptr) {}
AVLTree::~AVLTree() {
    chopTree(root);
};

void AVLTree::emptyTree(){
    chopTree(root);
    root = nullptr;
};

void AVLTree::chopTree(Node*& node) {
    if(!node) return;
    chopTree(node->left);
    chopTree(node->right);
    delete node;
    node = nullptr;
}

int AVLTree::height(Node* t) const {
    return t == nullptr ? 0 : t->height;
}

int AVLTree::getBalance(Node* t) const {
    return t == nullptr ? 0 : height(t->left) - height(t->right);
}

AVLTree::Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + getMax(height(x->left), height(x->right));
    y->height = 1 + getMax(height(y->left), height(y->right));

    return y;
}

AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = 1 + getMax(height(x->left), height(x->right));
    y->height = 1 + getMax(height(y->left), height(y->right));

    return x;

}

AVLTree::Node* AVLTree::leftRightRotate(Node* t) {
    t->left = leftRotate(t->left);
    return rightRotate(t);
}

AVLTree::Node* AVLTree::leftRotate(Node* t) {
    t->right = rightRotate(t->right);
    return leftRotate(t);
}

AVLTree::Node* AVLTree::insert(Node* t, int value){
    if (t == nullptr)
        return new Node(value);
    
    if (value < t->value) t->left = insert(t->left, value);
    else if (value > t->value) t->right = insert(t->right, value);
    else return t;

    t->height = 1 + getMax(height(t->left), height(t->right));

    int balance = getBalance(t);

    if (balance > 1 && value < t->left->value) return rightRotate(t);
    if (balance < -1 && value > t->right->value) return leftRotate(t);
    if (balance > 1 && value > t->left->value) return leftRightRotate(t);
    if (balance < -1 && value > t->right->value) return rightLeftRotate(t);

    return t;
}

void AVLTree::printTree(Node* node, ostream& out) const {
    if (!node) return;
    printTree(node->left, out);
    out << node->value << " ";
    printTree(node->right, out);
};

void AVLTree::printTree(ostream &out) const {
    printTree(root, out);
    out << endl;
}
