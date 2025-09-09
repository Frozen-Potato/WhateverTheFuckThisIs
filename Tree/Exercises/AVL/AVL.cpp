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
