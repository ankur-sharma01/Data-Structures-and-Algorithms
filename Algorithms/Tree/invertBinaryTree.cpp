// LC 226. Invert Binary Tree

// Given the root of a binary tree, invert the tree, and return its root.
// EXAMPLE:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// or:

class Solution {
public:
    void fun(TreeNode* root) {
        if (root == nullptr)
            return;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return;
    }

    TreeNode* invertTree(TreeNode* root) {
        fun(root);
        return root;
    }
};