// 787. Cheapest Flights Within K Stops
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
// EXAMPLE:
// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, INT_MAX);
        res[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int> temp = res;
            for (int j = 0; j < flights.size(); j++)
            {
                int s = flights[j][0];
                int d = flights[j][1];
                int wt = flights[j][2];

                if (res[s] != INT_MAX && temp[d] > res[s] + wt)
                    temp[d] = res[s] + wt;
            }
            res = temp;
        }
        if (res[dst] != INT_MAX)
        {
            return res[dst];
        } else
        {
            return -1;
        }
    }
};