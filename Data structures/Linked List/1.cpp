#include<iostream>
using namespace std;

class Node{

    public: int val;
            Node *next;

            // CONSTRUCTOR
    Node(int val){
        this -> val = val; // this is current context, just like in JS.
        this -> next = NULL;
    }

        // DESTRUCTOR
    ~Node(){
        int value = this -> val;
        // memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    cout << "Memory free for data. " << value << endl;
    }

};

// For insertion of node at the begning.
void insertnode(Node *&temp, int val){
    Node *current = new Node(val);
    current -> next = temp;
    temp = current;
}

void insertTail(Node *&tail, int val){
    Node *current = new Node(val);
    tail -> next = current;
    tail = current;
}

// void insertBetween(Node *&left, Node *&right, int val){
//     Node *current = new Node(val);
//     left -> next = current;
//     current -> next = right;
//     // left = right = current;
// }     -------------------------------------- CAUSING ERROR.


// Good if want to add after some specific node initialied before. Bad if want inclusion at some position.
void insertB(Node *&temp, int val){
    Node *current = new Node(val);
    current -> next = temp -> next;
    temp -> next = current;
}

// this will fix the position issue created above.
void insertBB(Node *&tail, Node *&head, int position, int val){

    // inserting at start:
    if(position == 1){
        insertnode(head, val);
        return;
    }

    Node *current = head;
    int count = 1;
    
    // inserting at tail:
    if(current -> next == NULL){
        insertTail(tail, val);
        return;
    }
    
    // inserting in between:

    while(count < position-1){
        current = current -> next;
        count++;
    }

    Node *temp = new Node(val);

    temp -> next = current -> next;
    current -> next = temp;
}

// void insertBB(Node *&left, Node *&right, int val){
//     Node *current = new Node(val);
//     left -> next = right;

// }


void print(Node *&head){
    Node *current = head;

    while(current != NULL){
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}

// TO GET LINKED LIST LENGTH:
int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}


// For deleting Node:
void deleteNode(int position, Node *&head, Node *&tail){ // destructor already made above.
    
    int length = getLength(head);
    // deleting first node:
    if(position == 1){
        Node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    } else if(position == length){
        Node* prev = head;
        // traversing to find prev node
        while(prev->next != tail) {
            prev = prev->next;   // move until prev is just before tail
        }
        delete tail;
        tail = prev;
        tail->next = NULL;
    }
    else {
        Node *current = head;
        Node *prev = NULL;

        int cnt = 1;
        while(cnt < position){ // to get previous and current positions.
            prev = current;
            current = current -> next;
            cnt++;
        }

        prev -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

int main(){

    Node *node1 = new Node(10); // Node() = constructor call.
    
    Node *node2 = new Node(20); // Node() = constructor call.
    node1 -> next = node2;
    Node *node3 = new Node(30); // Node() = constructor call.
    node2 -> next = node3;

    // will create head which will point to node1.
    Node *head = node1;
    Node *tail = node1;

    insertnode(head, 12);
    insertTail(node3, 40);
    insertB(node2, 35);
    print(head);
    
    insertBB(tail, head, 3, 45);
    print(head);

    // cout << head -> val << endl;
    // cout << tail -> val << endl;

    deleteNode(1, head, tail);
    print(head);
}