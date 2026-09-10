// LC 700. Search in a Binary Search Tree
// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
// EXAMPLE:
// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]


class Solution {
public:
    void fun(TreeNode* node, int val, TreeNode*& ans) {
        if (node == nullptr)
            return;

        if (node->val == val)
        {
            ans = node;
            return;
        }

        if (node->val > val)
        {
            fun(node->left, val, ans);
        } else
        {
            fun(node->right, val, ans);
        }

        return;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        fun(root, val, ans);
        return ans;
    }
};