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

---

## Example

```cpp
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
```
