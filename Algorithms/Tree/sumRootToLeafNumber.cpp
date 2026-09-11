// 129. Sum Root to Leaf Numbers
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.
// EXAMPLE:
// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25


class Solution {
public:
    int fun(TreeNode* root, int sum) {
        if(root == nullptr)
            return;

        sum = sum*10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return sum;

        int a = fun(root->left, sum);
        int b = fun(root->right, sum);

        return (a + b);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return fun(root, sum);
    }
};