#include<iostream>
using namespace std;

// what is a heap? - heap is CBT (complete binary tree - completely filled binary tree except for last row(neccesarily filled from left side))

// The ability to initialize variables directly inside the class (like bool isTerminal = false;) was introduced in the C++11 standard. If your compiler is set to an older version (like C++98 or C++03), it won't recognize that syntax and will throw exactly the error you're seeing.

class heap {
    // max heap
    public:
        int arr[100];
        int size = 0;

        void insert(int val) {

            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1) {
                int parent = index/2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }
        }

        void Delete() {
            if(size == 0) {
                cout << "nothing to delete" << endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            // take root node to its correct position
            int i = 1;
            while(i<size) {
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if(leftIndex < size && arr[i] < arr[leftIndex]) {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else {
                    return;
                }
            }
        }

        void print() {
            for(int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// Heap sort - 1. build heap, heapify
//             2. heap sort

void heapsort(int arr[], int n) {
    int size = n;

    while(size > 1) {
        // swap
        swap(arr[size], arr[1]);

        size--;

        heapify(arr, size, 1);
    }
}

int main() {

}