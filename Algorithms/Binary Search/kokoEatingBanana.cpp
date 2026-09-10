// LC 875: koko eating banana

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k(eating speed) such that she can eat all the bananas within h hours.


// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4


class Solution {
public:
    long long fun(vector<int>& piles, int n, int k) {
        long long h = 0;
        for(int i = 0; i < n; i++)
        {
            h = h + piles[i]/k;
            if(piles[i] % k != 0) h++;
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = -1;

        while(low<=high)
        {
            int guess = low + (high - low)/2;
            long long hour = fun(piles, n, guess);

            if(hour > h)
            {
                low = guess + 1;
            } else
            {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};