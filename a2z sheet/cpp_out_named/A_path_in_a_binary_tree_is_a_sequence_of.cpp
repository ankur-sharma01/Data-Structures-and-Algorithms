/*
 * QUESTION:
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
 * A node can only appear in the sequence at most once. Note that the path does not need to pass through the rosum of tot.
 * The path sum of a path is the he node's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 *
 * Find it: https://www.google.com/search?q=A%20path%20in%20a%20binary%20tree%20is%20a%20sequence%20of%20nodes%20where%20each%20pair%20of%20adjacent%20nodes%20in
 */

// ---- write your solution below ----

class Solution {
public:
    int sum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr)
            return 0;

        // going post-order, looking for left, right child and comparing them so that maximum sum among the branches can be handed to the center node.
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));

        int currentPathSum = node->val + leftGain + rightGain;
        sum = max(sum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return sum;    
    }
};
