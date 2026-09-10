// LC 852. Peak Index in a Mountain Array


// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

// Input: arr = [0,2,1,0]

// Output: 1 ---- index of the mountain peak

// jaise hi index change hua

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        // high = n-2; ---- but no need as loop will terminate before reaching there!
        int res = -1;
        
        while(low <= high)
        {
            int guess = low+(high-low)/2;
            
            if(arr[guess] < arr[guess+1])
            {
                low = guess + 1;
            }
            else
            {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
}; // OR : not using res, we will have to save the guess as to check.



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int guess = low + (high - low) / 2;

            if (nums[guess] < nums[guess + 1]) {
                // Peak must be to the right
                low = guess + 1;
            } else {
                // Peak is at 'guess' or to the left
                high = guess;
            }
        }
        return low; // 'low' and 'high' meet at a peak
    }
};


// how to store all the peaks?
vector<int> findAllPeaks(vector<int>& nums) {
    vector<int> peaks;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        bool leftSmaller = (i == 0) || (nums[i] > nums[i - 1]); // i == 0 is handling our base case as we don't have anthing for comparision.
        bool rightSmaller = (i == n - 1) || (nums[i] > nums[i + 1]); // base case handling!
        // rightSmaller and leftSmaller both should be true for a peak to exist, we check this for each index.

        if (leftSmaller && rightSmaller) {
            peaks.push_back(i);
        }
    }
    return peaks;
}