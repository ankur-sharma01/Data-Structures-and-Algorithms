// LC 191: Number of 1 Bits
// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
// Example 1:
// Input: n = 11
// Output: 3
// Explanation:
// The input binary string 1011 has a total of three set bits.


// TLE EXCEEDED:
class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n > 0)
        {
            int bit = n%2;
            if (bit == 1)
            {
                res++;
                n = n/2;
            }
        }
        return res;
    }
};

// OPTIMAL SOLUTION:
class Solution {
public:
    int hammingWeight(int n) {
        // Brian Kernighan’s Algorithm
        // we are actually operating on binary bits of n.
        int res = 0;
        while (n > 0)
        {
            res++;
            n = n&(n-1);
        }
        return res;
    }
};


// LC 136: Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
// EXAMPLE:
// Input: nums = [2,2,1]
// Output: 1


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x = x ^ nums[i];
        }
        return x;
    }
};