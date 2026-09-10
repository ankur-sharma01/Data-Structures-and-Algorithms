// 113. Path Sum II
// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
// EXAMPLE:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22


class Solution {
public:
    void fun(TreeNode* root, int targetSum, int sum, vector<int>& diary, vector<vector<int>>& res) {
        if (root == nullptr)
            return;
        
        diary.push_back(root->val);
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr && sum == targetSum)
        {
            res.push_back(diary);
        }
        fun(root->left, targetSum, sum, diary, res);
        fun(root->right, targetSum, sum, diary, res);
        diary.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> diary;
        int sum = 0;
        if (root == nullptr)
            return {};

        fun(root, targetSum, sum, diary, res);
        return res;
    }
};