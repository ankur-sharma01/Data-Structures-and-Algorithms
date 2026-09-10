#include<iostream>
using namespace std;

class Stack{

    //Properties

    public:
    int *arr;
    int size;
    int top;

    // Behaviour
    // Constructor:
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    // Functions

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        } else{
            cout << "stack overflow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        } else {
            cout << "stack underflow" << endl;
        }

    }

    int peek(){
        if(top >= 0 && top < size){
            return arr[top];
        } else {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        } else{
            return false;
        }
    }

    void printStack() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    
    cout << "Stack elements (Top to Bottom): " << endl;
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    }
};

int main(){
    
    Stack st(5); // 5 is the size of stack created.

    st.push(6);
    st.push(7);
    st.push(78);
    st.pop();

    cout << st.peek() << endl;
    st.printStack();
}