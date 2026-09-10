// 2461. Maximum Sum of Distinct Subarrays With Length K

#include<iostream>
using namespace std;

// nums = [1,5,4,2,9,9,9], k = 3

// wrong approach -- k has been hard coded,(hehehe)
int i = 0;
int max_sum = 0;
while(i < nums.size() - 2){

    if(nums[i] != nums[i+1] != nums[i+2]){
        if(i == 0){
        nums[i-1] = 0; // can't set value of something which is not in the memory.
    }
    int sum = nums[i] + nums[i+1] + nums[i+2] - nums[i-1];
    if(max_sum < sum){
        max_sum = sum;
    }
    i++;
}
}
return max_sum;


// is done using hashset or hashmap. --- later on
// alternative --- doesn't check for duplicates.
int n = nums.size() - 1;
int low = 0;
int high = k - 1;
int max_sum = 0;

// for finding initial sum:
for(int i = low; i <= high; i++) {
        int sum = sum + nums[i];
}

// for sliding the window for functioning of the prog.:
while(high < n) {
    
    max_sum = max(max_sum, sum);

    low++;
    high++;

    if(h == n) break;

    sum = sum - nums[low-1];
    sum = sum + nums[high];
}
return max_sum;

// TODO:    THIS IS THE REAL SOLUTION.
// for duplicate check: using freq. to store the count.

long long max_sum = 0;
long long sum = 0;
vector<int> freq(100001, 0); // 100001 = size of the vector and every index is initialised with 0.
// using this as to store count of numbers appearing --- index will be the key and value will be the count.
int high = 0;
int low = 0;
int n = nums.size();

// actually we will sum the whole array and check for size criteria if it fits or not and increase reduce accordingly.

// int k; --- size for the window.
// int size = high - low + 1; --- calculates the size of the window.

for(high = 0; high < n; high++) {

    // int size = high - low + 1; // it doesn't get updated after removing duplicates.

    sum = sum + nums[high];
    freq[nums[high]]++;
    // high++; ---- IT'S A FOR LOOP, NOT A WHILE LOOP, NO NEED TO DO INC. MANUALLY


    // checking for duplicates:
    while(freq[nums[high]] > 1){
        sum = sum - nums[low];
        freq[nums[low]]--;
        low++;
    }

    int size = high - low + 1; // actual size is calculated over here.

    if(size > k){ // adjusting the window size.
        sum = sum - nums[low];
        freq[nums[low]]--; // reducing the count as now the low will not be in the current window frame.
        low++;
        size = high - low + 1;
    }

    if(size == k) {
        max_sum = max(max_sum, sum); // check only for size == k
    }
}
return max_sum;



// using hashmap: everythings same, we are using hashmap to store frequency in place of vector.
// also we are removing the index from hashmap if it's count becomes zero using erase feature.

long long max_sum = 0;
long long sum = 0;

unordered_map<int, int> freq; // only storing elements inside our window. 

int high = 0;
int low = 0;
int n = nums.size();

// actually we will sum the whole array and check for size criteria if it fits or not and increase reduce accordingly.

// int k; --- size for the window.
// int size = high - low + 1; --- calculates the size of the window.

for(high = 0; high < n; high++) {

    // int size = high - low + 1; // it doesn't get updated after removing duplicates.

    sum = sum + nums[high];
    freq[nums[high]]++;
    // high++; ---- IT'S A FOR LOOP, NOT A WHILE LOOP, NO NEED TO DO INC. MANUALLY


    // checking for duplicates:
    while(freq[nums[high]] > 1){
        sum = sum - nums[low];
        freq[nums[low]]--;
        // this is the erase feature we are using, program works good without this too, but memory leak and storage can be issues. also instead of calculating size manually we can actually use freq.size().
        if(freq[nums[low]] == 0) {
            freq.erase(nums[low]);
        }
        low++;
    }

    //no need of manually calculating size.
    // int size = high - low + 1; // actual size is calculated over here.

    if(freq.size() > k){ // adjusting the window size.
        sum = sum - nums[low];
        freq[nums[low]]--; // reducing the count as now the low will not be in the current window frame.

        // here also we need to check for hashmap and erase if nums[low] freq. is 0.
        if(freq[nums[low]] == 0) {
            freq.erase(nums[low]);
        }
        low++;
        // size = high - low + 1;
        // freq.size(); --- no need as size is automatically calculated.
    }

    if(freq.size() == k) {
        max_sum = max(max_sum, sum); // check only for size == k
    }
}
return max_sum;