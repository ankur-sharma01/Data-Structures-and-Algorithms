#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// The left side of the tree include no. smaller than the root node, and right side will be bigger than the root node.

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        node(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }

};

void inorder(Node *root){ // LNR
    // base case
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void postorder(Node *root){ // LRN
    // base case
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}

void preorder(Node *root){ // NLR
    // base case
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

// BFS - breadth first search
void levelordertraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node *temp = q.front();

        q.pop();

        if(temp == NULL){ 
            // previous level is completely traversed.
            cout << endl;
            
            if(!q.empty()){
                // queue still has some child.
                q.push(NULL);
            }

        } else{

            cout << temp->data << " ";

            if(temp->left){
            q.push(temp->left);
            }

            if(temp->right){
            q.push(temp->right);
            }
        }        
    }
}

Node* insertIntoBST(Node* root, int d) {
    // base case
    if(root == NULL) {
        root = new node(d);
        return root;
    }

    if(d > root->data) {
        // this->d = 
        root->right = insertIntoBST(root->right, d); // actually me ye traverse krega till the end of the node where the base case will get triggered and eventually new node will be added.
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root) {

    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// search in a binary search tree(BST):
// recursive way
bool searchBST(Node* &root, int x) {
    if(root == NULL) {
        return false;
    }

    if(root->data == x) {
        return true;
    }

    if(root->data > x) {
        // left part me
        return searchBST(root->left, x);
    } else {
        // right part me
        return searchBST(root->right, x);
    }
}

// iterative way
bool SearchBST(Node* &root, int x) {
    Node* temp = root;

    while(temp != NULL) {
        if(root->data == x) {
            return true;
        }
        if(root->data > x){
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
}

Node* maxValue(Node* root) {
    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* minValue(Node* root) {
    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// for deleting a node:
Node* deleteNode(Node* root, int val) {
    // base case
    if(root == NULL) return root;

    if(root->data == val) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child

        // LEFT CHILD
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // RIGHT CHILD
        if(root->right != NULL && root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }


        // 2 child: two options - use minimum value or 
        
        if(root->left != NULL && root->right != NULL) {
            int mini = minValue(root->right) -> data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }

    } else if(root->data > val) {
        root->left = deleteNode(root->left, val);
        return root;
    } else {
        // right part me hai
        root->right = deleteNode(root->right, val);
        return root;
    }
}

int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    takeInput(root);

    cout << "printing the BST: " << endl;
    levelordertraversal(root);

    return 0;
}