#include<iostream>
using namespace std;

// bubble sort - compare adjacent elements and swap.
// selection sort - minimum swaps, comparision takes place and swaps only if needed.
// insertion sort - 

// also, if name used as argument for function is same as global variable, you need to use --------- ::(variable name) to use/access global variable.
class Sorting{
    public:
        
        int arr[7];
        int n = arr.size();

        void bubble(int arr[]) {
            // one element is compared at once to it's adjacent, that's we use two loops for this.
            // largest element is shifted to the end.
            bool swapped = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++){
                    if(arr[j] > arr [j+1]){
                        swap(arr[j], arr[j+1]);
                        swapped = true;
                    }
                }
                if(!swapped) break;
            }
        }

        void selection(int arr[]) {
            // swaps happen only when needed, less write to disk, saves hardware. other time just compares.
            for(int i = 0; i < n-1; i++) {
                // n-1 as last element will already be sorted.

                int minIndex = i;

                for(int j = i+1; j < n; j++) {

                    if(arr[j] < arr[minIndex]) {
                        // or another condition which can work here is (!arr[j] > arr[minIndex])
                        j = minIndex;

                    }
                }

                swap(arr[i], arr[minIndex]);

            }
        }

        void insertion(int arr[]) {
            // cin >> n >> endl;
            // int arr[n]; ----- actually we don't need this here as already declared globally.
            
            for(int i = 1; i < n-1; i++) {
                int temp = arr[i];
                int j = i-1;
                for(j >= 0; j--) {

                    if(arr[i] > temp) {
                        // shift
                        arr[j+1] = arr[j];
                    }
                    else {
                        break;
                    }
                }
                arr[j+1] = temp;
            }
        }
};