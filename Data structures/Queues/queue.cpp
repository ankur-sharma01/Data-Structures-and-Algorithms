// FIFO is the main thing here. (STACK had LIFO)
#include<iostream>
using namespace std;

class Queue{

    // properties:
    public:

    int size;
    int *arr;
    int top;
    int end;

    // constructor for implementing queue:
    Queue(int size){
        this -> size = size;
        // int arr = new int[size];
        arr = new int[size];
        top = -1;
        end = -1;
    }

    // add elements:

    void push(int element){
        if(size - top > 1){
            top++;
            end++;
            arr[top] = element;
            if(top > 0){end--;}
        }
        else {
            cout << "queue overflow" << endl;
        }
    }

    void pop(){
        if(top == -1 && end == -1){
            cout << "nothing to pop." << endl;
        }
        else if(end == top){
            // reseting
            top = -1;
            end = -1;
        }
        else if(end < size){
            end++;
        }
    }

    int peekbothside(){
        cout << arr[top] << " & " << arr[end] << endl;
    }
};

int main(){

    Queue qu(4);
    qu.push(14);
    qu.push(64);
    qu.push(45);
    qu.push(42);

    qu.peekbothside();
    qu.pop();
    qu.peekbothside();
}