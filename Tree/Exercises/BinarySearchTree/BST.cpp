#include "BST.h"
using namespace std;

class BST {
    struct BiNode {
        int value;
        BiNode* left;
        BiNode* right;
        explicit BiNode(int x, BiNode* lptr = nullptr, BiNode* rptr = nullptr) : value(x), left(nullptr), right(nullptr) {};
    };

    BiNode* root;

    BiNode* findMin(BiNode* node) const {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    BiNode* findMax(BiNode* node) const {
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

    void insert(int x, BiNode*& node) {
        if (!node) node = new BiNode(x);
        else if (x < node->value) insert(x, node->left);
        else if (x > node->value) insert(x, node->right);
    }

    void remove(int x, BiNode*& node) {
        if(!node) return;
        if (x < node->value) remove(x, node->left);
        else if (x > node->value) remove(x, node->right);
        else if (node->left && node->right) {
            node->value = findMin(node->right)->value;
            remove(node->value, node->right);
        } else {
            BiNode* oldNode = node;
            node = (node->left) ? node->left : node->right;
            delete oldNode;
        }
    }

    bool contains(int x, BiNode* node) const {
        if(!node) return false;
        if (x < node->value) return contains(x, node->left);
        else if (x > node->value) return contains(x, node->right);
        else return true;
    }

    void emptifying(BiNode*& node) {
        if(!node) return;
        emptifying(node->left);
        emptifying(node->right);
        delete node;
        node = nullptr; //prevent node point to old address after delete
    }

    void printTree(BiNode* node, ostream& out) const {
        if (!node) return;
        printTree(node->left, out);
        out << node->value << " ";
        printTree(node->right, out);
    };

    public:
        BST() : root(nullptr) {}
        ~BST() { emptifying(root); }
        void insert(int x) { insert(x, root); };
        void remove(int x) { remove(x, root); };
        bool contains(int x) const { return contains(x, root); };
        bool isEmpty() const { return root == nullptr; };
        int findMin() const { return findMin(root)->value; };
        int findMax() const { return findMax(root)->value; };
        void makeEmpty() { emptifying(root); };
        void printTree(ostream& out = cout) const {
            if(isEmpty()) out << "Yggdrasil is dead";
            else printTree(root, out);
            out << "\n";
        };
};