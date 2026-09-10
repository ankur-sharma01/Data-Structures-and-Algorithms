#include<iostream>
using namespace std;

nums[5] = [-4,-1,0,3,10];
int n = nums.size();
int left = 0, right = n-1
vector<int> arr(n); // can't use arr[n] for space declaration. Also space is dynamic in vector. and using [] means a 2D vector and () means 1D vector.
int newIndex = nums.size() - 1;

while (left <= right) {

    int a = nums[left] * nums[left];

    int b = nums[right] * nums[right];

    if(a < b){
        arr[newIndex] = b;
        // newIndex--;
        right--;
    } else {
        arr[newIndex] = a;
        // newIndex--;
        left++;
    }
    newIndex--;
}
return arr; // just return the vector name.