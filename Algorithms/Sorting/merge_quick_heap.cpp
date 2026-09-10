#include<iostream>
using namespace std;

// merge sort - divide into two parts and sort them individually.
// quick sort - choose pivot and divide the array into two parts, use recurssion for each part or use tco for right and recursion for left part.
// heap sort  - 

// merge sort vs. quick sort? --- in arrays : quick sort - no extra space allocation and random access possible, random access is a hassle for linked list in quick sort as linked list needs to be traversed.
//                                in linked list : merge sort - insertion of items in between is easy unlike arrays where adjacent memory is in work. merge sort also needs less random access.

// must see the TCO - TAIL CALL OPTIMIZATION in quick sort.

void merge(int *arr, int  st, int end) {
    int mid = (st + end)/2;

    int len1 = mid - st + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values:
    int mainArrayindex = st;
    for(int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayindex];
    }

    mainArrayindex = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayindex];
    }

    // merge 2 sorted arrays:
    int index1 = 0;
    int index2 = 0;
    mainArrayindex = 5;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayindex++] = first[index1++];
        } else {
            arr[mainArrayindex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrayindex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayindex++] = second[index2++];
    }
}

void mergeSort(int *arr, int st, int end) {
    
    // base case:
    if(st >= end) {
        return;
    }

    int mid = (st + end)/2;

    // left part sorting:
    mergeSort(arr, st, mid);

    // right part sorting;
    mergeSort(arr, mid+1, end);

    // merge:
    merge(arr, st, end);


}



int partition(int arr[], st, end) {

    int pivot = arr[st];
    
    int cnt = 0;

    for(int i = s+1; i <= end; i++) {
        if(arr[i] <= pivot) {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = st + end;
    swap(arr[pivotIndex], arr[st]);

    // left and right wala part:
    int i = st, j = end;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int arr[], int st, int end) {

    // base case
    if(st >= end) {
        return;
    }

    // partition
    int p = partition(arr, st, end);

    // left part sorting:
    quickSort(arr, s, p-1);

    // right part sorting:
    quickSort(arr, p+1, e);

    //                  OR --- [TCO]

    /*        while (st < end) {
                
                // 2. Partitioning: Places pivot in the right spot
                int p = partition(arr, st, end);

                // 3. The "Smaller Side" Strategy
                if (p - st < end - p) {
                    // Left side is smaller, recurse there
                    quickSort(arr, st, p - 1);
                    // Re-assign 'st' to handle the right side in the NEXT loop
                    st = p + 1; 
                } else {
                    // Right side is smaller, recurse there
                    quickSort(arr, p + 1, end);
                    // Re-assign 'end' to handle the left side in the NEXT loop
                    end = p - 1;
                }
            }  */

}

int main(){

    cin >> n;
    arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i] >> ", ";
    }



}