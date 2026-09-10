// Q. No. 209

#include<iostream>
using namespace std;


// THIS IS CORRECT APPROACH USING FIXED SIZE WINDOW ---- BUT FAILS IN TIME COMPLEXITY, NEED TO USE VARIABLE SLIDING WINDOW.
int k = 1; // our window size for finding subarrays.
int n = nums.size();
int high = 0;

while(k < n) {
    int sum = 0;
    int low = 0;

    for(high = 0; high < n; high++){
        sum = sum + nums[high];
        
        int size = high - low + 1;
        if(size > k) {
            sum = sum - nums[low];
            low++;
        }

        if(sum >= target) {
            return k;
        }
    }
    k++;
}
return 0;

// VARIABLE SLIDING WINDOW: sliding low and high such that the sum of elements become greater or equal to target.

int n = nums.size();
int high = 0, low = 0;
long long sum = 0;
int min_size = INT_MAX;

// brute force method to check for if their is no such pair which is greater than or equal to target.
for(int i = 0; i < n; i++) {
    sum += nums[i];
}
if(sum < target) {
    sum = 0;
    min_size = 0;
    return min_size;
}
sum = 0; // resetting sum for next block.

// a very clean approach can be by adding ternary(?) operator at last which checks if the min_size value is changed from initial value or not.
for(high = 0; high < n; high++) {

    int size = high - low + 1;
    sum = sum + nums[high]; // hiring

    // firing:
    while(sum >= target) {
        size = high - low + 1;
        if(size < min_size) {
            min_size = size;
        }
        sum = sum - nums[low];
        low++;
    }
}
return min_size;
// return (min_size == INT_MAX) ? 0 : min_size; ---- highly optimized for this solution. No full array sum check required.