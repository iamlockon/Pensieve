# Morris (Inorder) Traversal

# Overview

Morris traversal can achieve O(1) space complexity by modifying the binary tree temporarily. For each node, it first check if left child exists, find predecessor of it if so, and point the right child of the predecessor to the node. This modification serves two purposes:

1. When we finish the left subtree, we can go back to the current node in O(1).
2. When we find predecessors, it can be used to determine if we have finished current left subtree.

# Summary

Let tree size be n:

Space: O(1)
Time: O(n), we traverse all nodes twice.

# Implementation

## C++

struct Node {
    Node* left, right;
    int val;
}

```c++
vector<int> morris(Node* root) {
    vector<int> res;
    Node* prev, tmp;
    tmp = root;
    while (root != nullptr) {
        if (root->left) {
            prev = root->left;
            while (prev->right != nullptr && prev->right != root) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = root;
                root = root->left;
            } else { // prev->right == root, we already traverses all nodes in root
               res.push_back(root->val);
               prev->right = nullptr; // restore node
               root = root->right; 
            }
        } else {
            res.push_back(root->val);
            root = root->right;
        }
    }
    root = tmp; // restore tree root
    return res;
}
```

# Resource

https://www.educative.io/edpresso/what-is-morris-traversal