// intro: traversal

// In-order
class Solution {
public:
    void fun(Node* node) {
        if (node == nullptr)
            return;

        fun(node->left);
        cout << node->data;
        fun(node->right);

        return;
    }

    void leetcode(Node* root) {
        fun(root);
        return;
    }

};

// Pre-order (data, left, right)
class Solution {
public:
    void fun(Node* node) {
        if (node == nullptr)
            return;

        cout << node->data;
        fun(node->left);
        fun(node->right);
        return;
    }

    void leetcode(Node* root) {
        fun(root);
        return;
    }
};

// Post-order (left, right, data)
class Solution {
public:
    void fun(Node* node) {
        if (node == nullptr)
            return;

        fun(node->left);
        fun(node->right);
        cout << node->data;
    }

    void leetcode(Node* root) {
        fun(root);
        return;
    }
};