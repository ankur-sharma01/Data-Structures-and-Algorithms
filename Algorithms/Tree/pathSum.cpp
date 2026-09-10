// 112. Path Sum
// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children.
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown.


class Solution {
public:
    void fun(TreeNode* root, int currentSum, int targetSum, bool& res) {
        if (root == nullptr || res)
            return;

        currentSum += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (currentSum == targetSum)
            {
                res = true;
            }
            return;
        }

        fun(root->left, currentSum, targetSum, res);
        fun(root->right, currentSum, targetSum, res);

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int currentSum = 0;
        bool res = false;
    
        fun(root, currentSum, targetSum, res);
        return res;
    }
};