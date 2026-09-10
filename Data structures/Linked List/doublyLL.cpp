#include <iostream>
using namespace std;

class Node{
    public: int data;
            Node *next;
            Node *prev;

    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // DESTRUCTOR:
    ~Node(){
        int val = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory freed for " << val << endl;
    }
};

int getLength(Node *head){
    int length = 0;
    Node *temp = head;

    while(temp != NULL){
        length++;
        temp = temp -> next;
    }

    return length;
}

void insertHead(Node *&tail, Node *&head, int d){

    if(head == NULL){
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node *temp = new Node(d);
    // head -> prev = temp;
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}

void insertTail(Node *& head, Node *&tail, int d){
    if(tail == NULL){
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    Node *current = new Node(d);

    tail -> next = current;
    current -> prev = tail;

    tail = current;}
}

void insertPostion(Node *&head, Node *&tail, int position, int d){
    Node *temp = new Node(d);
    if(position == 1){
        insertHead(tail, head, d);
        return;
    }

    int length = getLength(head);
    Node *current = head;
    if (position == length || current -> next = NULL){
        insertTail(head, tail, d);
        return;
    }

    int count = 1;
    if (1 < position < length){

        while(count < position-1){
            current = current -> next;
            count++;
        }

        temp -> next = current -> next;
        current -> next -> prev = temp;
        current -> next = temp;
        temp -> prev = current;

    }
}

void deleteNode(int position, Node *&head){

    if(position == 1){

        Node *temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;

        delete temp;
    }
    else{
        
        Node *current = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position){
            prev = current;
            current = current -> next;
            count++;
        }

        current -> prev = NULL;
        prev -> next = current -> next;
        current -> next = NULL;

        delete current;
    }
}

int print(Node *head){
    Node *current = head;

    while(current != NULL){
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
}

int main(){

    Node *node1 = new Node(11);
    Node *head = node1;
    Node *tail = node1; // instialization here is necessary.

    print(head);
    // cout << getLength(head) << endl;

    insertHead(tail, head, 56);
    insertTail(head, tail, 50);

    print(head);
}