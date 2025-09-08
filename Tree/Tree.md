# Tree

## Theory

- A data type that resembles an upside-down tree.  
- A node with no children is a **leaf**.  
- The top node is the **root**.  
- A **Binary Tree** is a tree in which each node has no more than 2 children.  

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
