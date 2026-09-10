#include<iostream>
#include<unordered_map>

using namespace std;

vector<vector<int>> checkDuplicate(vector<int> &nums) {

    int cm = 0;
    int officer = 1;
    // int unique = 1;  (for less space complexity)

    while (officer < nums.size()) {
        if(nums[officer] == nums[officer-1]) {
            officer++;
            continue;
        } else {
            nums[cm + 1] = nums[officer];
            officer++
            cm++
            // unique++
        }
        
    }
    // return unique;
    return (cm + 1);
}

//      now the hashmap way;

// we store what we have seen until it ends and return the result at the end.

unordered_map<int,int> seen;
int cm = 0;

for(int officer = 0; officer < nums.size(); officer++) {

    if(seen.find(nums[officer]) == seen.end()) { // this conditions check do we got the number before and is stored or not.
        seen[nums[officer]] = true; // nums[officer] = key and 'true' is the value in hashmap.

        nums[cm] = nums[officer];
        cm++;
    }
}
return cm;
