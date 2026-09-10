// LC 235. Lowest Common Ancestor of a Binary Search Tree
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
// EXAMPLE:
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.


class Solution {
public:
    void fun(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (node == nullptr) return;
        if (node->val == p->val || node->val == q->val)
        {
            ans = node;
            return;
        }
        if (node->val < p->val)
        {
            fun(node->right, p, q, ans);
        }
        else if (node->val > q->val)
        {
            fun(node->left, p, q, ans);
        }
        else
        {
            ans = node;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        if (p->val < q->val)
        {
            fun(root, p, q, ans);
        } else
        {
            fun(root, q, p, ans);
        }

        return ans;
    }
};