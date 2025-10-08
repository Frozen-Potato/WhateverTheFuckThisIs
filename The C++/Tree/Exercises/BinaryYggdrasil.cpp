#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    explicit Node(int x): data(x), left(nullptr), right(nullptr) {};
    Node(int x, Node* left, Node* right): data(x), left(left), right(right) {};
};

Node* buildTree(const vector<int>& a, vector<Node>& things) {
    things.clear(); //clear old data
    things.reserve(a.size()); //reserve space for node
    for (int val : a) things.emplace_back(val); // calling node(val) to contruct for every item in the vector a inside things

    for (size_t i = 0; i <  things.size(); ++i) {
        size_t L = 2*i + 1;
        size_t R = 2*i + 2;
        if (L < things.size()) things[i].left = &things[L];
        if (R < things.size()) things[i].right = &things[R];
    } // Set node left and right pointers

    return things.empty() ? nullptr : &things[0]; //return null if empty
}

void printInOrder(Node* root) {
    if(!root) return; //if node doesn't exists, happens when passed nodes is nullptr
    printInOrder(root->left); //Print left
    cout << root->data << " "; //Print the current passed node
    printInOrder(root->right); // Print right
}

int main()
{
    // Allocate on stack, lost when Yggdrasil out of scope, use when no need for pointer out of scope
    // Node Yggdrasil(1);
    // Node* root = &Yggdrasil;
    

    // Allocate in Heap, manual delete
    // Node* YggdrasilRoot = new Node(1);
    // delete YggdrasilRoot;

    // Using unique pointer, auto delete after pointer goes out of scope, still allocate in Heap, prefer in mordern C++
    // auto YggdrasilRoot = make_unique<Node>(1); 

    vector<int> a{3123,323,32,3,32,43,434,34,43};
    vector<Node> Yggdrasil;

    Node* YggdrasilRoot = buildTree(a, Yggdrasil);
    
    printInOrder(YggdrasilRoot);
    cout << "\n";

    cin.get();
    
    return 0;
}
