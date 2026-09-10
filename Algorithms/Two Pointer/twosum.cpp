#include<iostream>
using namespace std;

//  TWO POINTER MEANS MOVING TWO POINTERS AT ONCE TOGETHER AND NOT IN DIFFERENT DIFFERENT LOOP.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        

    }
};

// when finding multiple solutions and to avoid duplicates in that we have to actually do both - i++ & j--, as compliment pair won't change if we just shift one.

// arr[10000] = [0,4,3,4,5,6,....]

// if sorted:
while(i < j) {
    int sum = arr[i] + arr[j];
    if(sum == target) {
        return {i,j};
    }
    if(sum < target) {
        i++;
    } else if(sum > target) {
        j--;
    }
}
return {};


// if not sorted:
unordered_map<int, vector<int>> &seen;
vector<vector<int> result>>;
// nums , target
for(int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];

    if(seen.find(complement) != seen.end()) {
        for(int pastindex : seen[complement]) {
            results.push_back({pastindex, i})
        }
    }

    seen[nums[i]].push_back(i);
}
return results;






#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> allTwoSums(vector<int>& nums, int target) {
    // A cabinet (map) where each folder (key) holds a list of doors (indices)
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
        
        int complement = target - nums[i];

        // 1. SEARCH: Look in the cabinet for the partner's folder
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
            }
        seen[nums[i]] = i; // creating entry if not found before.
    }
    return {};
}