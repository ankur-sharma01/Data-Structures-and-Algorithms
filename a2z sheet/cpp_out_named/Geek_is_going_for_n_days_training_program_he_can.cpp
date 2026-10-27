/*
 * QUESTION:
 *
 * Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.
 *
 * Example:
 * Input:
 * n = 3
 * points = [[1,2,5],[3,1,1],[3,3,3]]
 * Output:
 * 11
 * Explanation:
 * Geek will learn a new move and earn 5 points on the first day,
 * then on the second day, he will do running and earn 3 points,
 * and on the third day, he will do fighting and earn 3 points.
 * So, the maximum points is 11.
 *
 * Find it: https://www.google.com/search?q=Geek%20is%20going%20for%20n%20days%20training%20program%2C%20he%20can%20perform%20any%20one%20of%20these%20three%20activities%20Running%2C
 */

// ---- write your solution below ----

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        if (n == 0) return 0;

        // points for day 0:
        int prev_0 = mat[0][0];
        int prev_1 = mat[0][1];
        int prev_2 = mat[0][2];

        Day 0 points: [Running: 8, Fighting: 7, Learning: 1]
        Day 1 points: [Running: 9, Fighting: 2, Learning: 1]

        for (int i = 1; i < n; i++)
        {
            curr_0 = mat[i][0] + max(prev_1, prev_2);
            curr_1 = mat[i][1] + max(prev_0, prev_2);
            curr_2 = mat[i][2] + max(prev_1, prev_2);

            prev_0 = curr_0;
            prev_1 = curr_1;
            prev_2 = curr_2;
        }

        return max({prev_0, prev_1, prev_2});
    }
};
