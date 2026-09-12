// LC 99. Recover Binary Search Tree
// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
// EXAMPLE:
// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.


class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* g1first = nullptr;
    TreeNode* g1second = nullptr;
    TreeNode* g2first = nullptr;
    TreeNode* g2second = nullptr;
    int galat = 0;

    void fun(TreeNode* root) {
        if (root == nullptr)
            return;

        fun(root->left);
        if (prev == nullptr)
        {
            prev = root;
        } else
        {
            if (root->data < prev->data)
            {
                if (galat == 0)
                {
                    g1first = prev;
                    g1second = root;
                    galat++;
                } else
                {
                    g2first = prev;
                    g2second = root;
                    galat++;
                }
            }
            prev = root;
        }
        fun(root->right);
    }

    void recoverTree(TreeNode* root) {
        if (root == nullptr)
            return;
        fun(root);
        if (galat == 2)
            swap(g1first->val, g2second->val);

        if (galat == 1)
            swap(g1first->val, g1second->val);
    }
};

// optimal solution:

class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void fun(TreeNode* root) {
        if (root == nullptr)
            return;

        fun(root->left);
        if (prev != nullptr && root->val < prev->val)
        {
            if (first == nullptr)
                first = prev;

            second = root; // always update second whenever you come inside this if block.
        }
        prev = root;
        fun(root->right);
    }
        
    void recoverTree(TreeNode* root) {
        if (root == nullptr)
            return;

        fun(root);
        if (first != nullptr && second != nullptr)
            swap(first->val, second->val);
    }
};
