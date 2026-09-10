#include<iostream>
using namespace std;

// use of maps and unordered maps basically.

// vector<int> v(100, 0) - vector with size 100 and all in initialized to zero.

// Q. Find maximum frequency of a number occuring?
int maxFreq(vector<int> &arr, int n) {
    unordered_map<int,int> count;

    int maxFre = 0;
    int maxAns = 0;

    for(int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
        // count is the value and arr[i] is the key - [{key, value}, {key, value}, ....]
        maxFre = max(maxFre, count[arr[i]]); // maxFre is updated everytime.
    }

    for(int i = 0; i < arr.size(); i++) {
        if(maxFre == count[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}