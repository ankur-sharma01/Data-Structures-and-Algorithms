// GFG Aggressive cows: Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.

// Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

// Input: arr[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.


class Solution {
public:
    bool fun(vector<int> &arr, int n, int k, int guess) {
        // code here
        // int n = arr.size();
        int usedCows = 1;
        int prevPos = arr[0];

        for(int i = 1; i < n; i++)
        {
            int dist = arr[i] - prevPos;
            if(dist < guess) continue;

            usedCows++;
            prevPos = arr[i];
        }

        if(usedCows >= k) return true;

        return false;
    }

    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int low = 1, high = arr[n-1] - arr[0];
        int res = -1;

        while(low <= high)
        {
            int guess = low + (high - low)/2;
            if(fun(arr, n, k, guess))
            {
                res = guess;
                low = guess + 1;
            } else
            {
                high = guess - 1;
            }
        }
        return res;
    }
};