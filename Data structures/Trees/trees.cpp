#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// check video lecture for revision, aise smjh na aaye. Iterations smjhana is important and use of recurssion.

class Node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};

node *buildTree(node *root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left: " << endl;

    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right: " << endl;

    root->right = buildTree(root->right);

    return root;

}

// BFS - breadth first search
void levelordertraversal(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node *temp = q.front();

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

// their are different types of trees, like inorder, preorder, postorder.

void inorder(node *root){ // LNR
    // base case
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void postorder(node *root){ // LRN
    // base case
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}

void preorder(node *root){ // NLR
    // base case
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

void buildFromLevelOrder(node* &root){

    queue<node*> q;
    cout << "Enter data for root " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }

    }

}

void reverseLevelOrder(node* root){
    if (root == NULL) return;

    // for reverse level order traversal, we actually need to build a tree first.
    queue<node*> q;
    stack<node*> s; // We add a stack to reverse the order.

    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        s.push(temp); // Store the node in the stack

        // Push RIGHT child first so that Left comes out of the stack first.
        if (temp->right)
            q.push(temp->right);

        if (temp->left)
            q.push(temp->left);
    }

    // Now pop everything from stack and print
    while (!s.empty()) {
        node* temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }
}
// for checking no. of leaf node in any tree, just check for root->left == NULL && root->right == NULL condition.

int main(){

    node *root = NULL;

    // creating a tree.
    root = buildTree();

    return 0;
}