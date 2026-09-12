// LC 102. Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        // will be using queue
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> currentLevel;

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                res.push_back(currentLevel);
                currentLevel.clear();
                if (!q.empty())
                    q.push(nullptr);
            }
            else
            {
                currentLevel.push_back(temp->val);

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
        }
        return res;
    }
};

// another solution:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root == nullptr) return res;

        q.push(root);
        while(!q.empty())
        {
            vector<int> currentLevel;
            int size = q.size();
            while (size--)
            {
                TreeNode* temp = q.front();
                q.pop(); 
                currentLevel.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.push_back(currentLevel);
            // TODO:
            // currentLevel.pop_back(); // not needed if we declare currentLevel inside the while block, also if we declare it outside we will have to use .clear() as .pop_back() just pops the last element and we have to clear it totaly.
        }
        return res;
    }
};