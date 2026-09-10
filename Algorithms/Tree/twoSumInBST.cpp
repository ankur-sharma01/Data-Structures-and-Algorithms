LC 1214: Two sum BSTs


class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode*> s1; // For Tree 1 (Ascending order)
        stack<TreeNode*> s2; // For Tree 2 (Descending order)

        TreeNode* t1 = root1;
        TreeNode* t2 = root2;

        while (true) {
            // 1. Push all left nodes of Tree 1 (getting to smallest available value)
            while (t1) {
                s1.push(t1);
                t1 = t1->left;
            }

            // 2. Push all right nodes of Tree 2 (getting to largest available value)
            while (t2) {
                s2.push(t2);
                t2 = t2->right;
            }

            // If either stack runs out of nodes, no pair can sum to target
            if (s1.empty() || s2.empty()) 
                break;

            TreeNode* node1 = s1.top();
            TreeNode* node2 = s2.top();

            int currentSum = node1->val + node2->val;

            if (currentSum == target) {
                return true;
            } 
            else if (currentSum < target) {
                // Sum too small -> Advance Tree 1 iterator (get next larger value)
                s1.pop();
                t1 = node1->right; // Corrected: update happens before re-entering loop
            } 
            else {
                // Sum too large -> Advance Tree 2 iterator (get next smaller value)
                s2.pop();
                t2 = node2->left;
            }
        }

        return false;
    }
};


