// LC 653. Two Sum 4 - BST
// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
// EXAMPLE:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true


class Solution {
public:
    stack<TreeNode*> asc;
    stack<TreeNode*> dsc;

    TreeNode* getSmall() {
        if (asc.empty())
            return nullptr;

        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightChild = small->right;
        while (rightChild)
        {
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }

    TreeNode* getBig() {
        if (dsc.empty())
            return nullptr;

        TreeNode* big = dsc.top();
        dsc.pop();
        TreeNode* leftChild = big->left;
        while (leftChild)
        {
            dsc.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }

    bool fun(TreeNode* root, int k) {
        if (root == nullptr)
            return false;

        TreeNode* t = root;
        while (t)
        {
            asc.push(t);
            t = t->left;
        }

        t = root;
        while (t)
        {
            dsc.push(t);
            t = t->right;
        }
        
        TreeNode* i = getSmall();
        TreeNode* j = getBig();
        while (i && j && i != j && i->val <= j->val)
        {
            int sum = i->val + j->val;
            if (sum == k)
                return true;

            if (sum > k)
                j = getBig();
            else
                i = getSmall();
        }
        return false;
    }
};