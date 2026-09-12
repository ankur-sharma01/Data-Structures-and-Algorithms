// LC 958. Check Completeness of a Binary Tree
// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
// EXAMPLE:
// Input: root = [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.


// only a single node is pushed at a time in a queue if we use .push
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
            return true;

        bool nullFound = false;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if (t == nullptr)
            {
                nullFound = true;
            } else
            {
                if (nullFound)
                    return false;

                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};