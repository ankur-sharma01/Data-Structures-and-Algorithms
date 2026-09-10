// GFG : Kth Smallest

// Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
// Note: The kth smallest element is determined based on the sorted order of the array.

// Examples :

// Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
// Output: 5
// Explanation: 4th smallest element in the given array is 5.


class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        int i;
        int n = arr.size();

        for(i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        for(i = k; i < n; i++)
        {
            if(arr[i] >= pq.top())
            {
                continue;
            } else
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};