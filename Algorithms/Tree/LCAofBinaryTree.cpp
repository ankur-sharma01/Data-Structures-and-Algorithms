// 236. Lowest Common Ancestor of a Binary Tree

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
// EXAMPLE:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        // TreeNode* ans;
        if (root == nullptr)
            return 0;

        int left = fun(root->left, p, q, ans);
        int right = fun(root->right, p, q, ans);

        int self = 0;
        if (root == p || root == q)
            self = 1;

        int total = left + self + right;
        if (total == 2 && ans == nullptr)
            ans = root;

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        fun(root, p, q, ans);
        return ans;
    }
};