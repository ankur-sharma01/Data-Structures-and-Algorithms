// similar like circular queue.
#include<iostream>
using namespace std;

class DEQueue{
    public:
    int size;
    int *arr;
    int rear;
    int front;

    // constructor
    DEQueue(int n){
        int size = n;
        int arr = new int[size];
        front = rear = -1;
    }

    bool pushfront(int value){
        // check full:
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            cout << "queue is full" << endl;
            return false;
        } else if(front == -1){
            front = rear = 0;
        } else if(front == 0 && rear != size-1){
            front = n-1;
        } else{
            front--;
        }
        arr[front] = value;
        return true;
    }

    bool pushrear(int value){
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            return false;
        } else if(front == -1){
            front = rear = 0;
        } else if(rear == size-1 && front != 0){
            rear = 0;
        } else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popfront(){
        if(front == -1){
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ // single element
            front = rear = -1;
        } else if(front == size - 1){
            front = 0; // to maintain cyclic nature
        } else{
            front++; // normal flow
        }
        return ans;
    }

    int poprear(){
        if(front == -1){
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear){ // single element
            front = rear = -1;
        } else if(rear == 0){
            rear = size-1; // to maintain cyclic nature
        } else{
            rear--; // normal flow
        }
        return ans;
    }
};