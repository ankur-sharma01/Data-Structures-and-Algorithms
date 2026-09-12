// LC 98. Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// EXAMPLE:
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.


// BRUTE FORCE: MAKE INORDER ARRAY FOR A TREE, TRAVERSE AND CHECK IF IT'S SORTED OR NOT!

// OPTIMAL APPROACH:
class Solution {
public:
    TreeNode* prev = nullptr;
    bool ans = true;
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        if (prev == nullptr)
        {
            prev = root;
        } else
        {
            if (root->val <= prev->val)
                ans = false;

            prev = root;
        }
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};