/*
 * QUESTION:
 *
 * A conveyor belt has packages that must be shipped from one port to another within days days.
 *
 * The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
 *
 * Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
 *
 * Example:
 *
 * Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 * Output: 15
 * Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
 * 1st day: 1, 2, 3, 4, 5
 * 2nd day: 6, 7
 * 3rd day: 8
 * 4th day: 9
 * 5th day: 10
 *
 * Find it: https://www.google.com/search?q=A%20conveyor%20belt%20has%20packages%20that%20must%20be%20shipped%20from%20one%20port%20to%20another%20within%20days%20days.%20The
 */

// ---- write your solution below ----


// Approach: Pattern to be noticed here is binary search for finding out the max capacity such that we can ship packages exactly within given days.

class Solution {
public:
    int fun(vector<int>& weights, int guess) {
        int daysTaken = 1, load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] + load <= guess)
            {
                load += weights[i];
            } else
            {
                daysTaken++;
                load = weights[i];
            }
        }
        return daysTaken;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxElement = 0;
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += weights[i];
            maxElement = max(maxElement, weights[i]);
        }
        
        int low = maxElement;
        int high = totalSum;
        int minCapacity = 0;

        while (low <= high)
        {
            int guess = low + (high-low)/2;
            if (fun(weights, guess) <= days)
            {
                minCapacity = guess;
                high = guess - 1;
            } else
            {
                low = guess + 1;
            }
        }
        return minCapacity;
    }
};