# Tree

## Theory

- A data type that resembles an upside-down tree.  
- A node with no children is a **leaf**.  
- The top node is the **root**.  
- A **Binary Tree** is a tree in which each node has no more than 2 children.

- **Binary Search Tree ADT** is a binary tree where:
  - The **left subtree** contains only keys **smaller** than the node’s key.  
  - The **right subtree** contains only keys **greater** than the node’s key.  
  - Both the left and right subtrees must also be **Binary Search Trees**.

- An **AVL Tree** is a **self-balancing Binary Search Tree**.  
- Named after inventors **Adelson-Velsky and Landis**.  
- The **balance factor** of a node = `height(left subtree) - height(right subtree)`.  
  - Balance factor ∈ {-1, 0, 1} → Tree is balanced.  
  - If balance factor goes outside this range → **rotations** are applied.  
- Rotations used:
  - **Right Rotation (LL case)**  
  - **Left Rotation (RR case)**  
  - **Left-Right Rotation (LR case)**  
  - **Right-Left Rotation (RL case)**  
- Guarantees **O(log n)** height → efficient search, insert, delete.

---

## Example

### Binary Tree

```cpp
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
```

### AVL Tree

```cpp
struct AVLNode {
    int val;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};
```
