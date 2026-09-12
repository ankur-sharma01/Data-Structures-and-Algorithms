// LC 543. Diameter of Binary Tree
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them
// EXAMPLE:
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].


class Solution {
public:
    int fun(TreeNode* root, int& res) {
        if (root == nullptr)
            return 0;

        // if (root->left == nullptr && root->right == nullptr)
        // {
        //     sum = 
        //     return;
        // }
        int left = fun(root->left, res);
        int right = fun(root->right, res);

        int sum = left + right; // left side jana and right side jana barri barri
        res = max(sum, res);
        return (1 + max(left,right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        fun(root, res);
        return res;
    }
};