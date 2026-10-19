/*
 * QUESTION:
 *
 * Count the number of undirected graphs that can be formed with n vertices.
 *
 * Find it: https://www.google.com/search?q=Count%20the%20number%20of%20undirected%20graphs%20that%20can%20be%20formed%20with%20n%20vertices.
 */

// ---- write your solution below ----

class Solution{
public:
    long long count(int n) {
        long long edges = (n * (n-1))/2;

        // 1LL means left shift by 1 as long long.
        return 1LL << edges;
    }
}

// another approach:
class Solution{
public:
    const int mod = 1e9 + 7;

    long long power(long long x, long long y) {
        // Binary Exponentiation:
        long long res = 1;
        while (y > 0)
        {
            if (y & 1)
            {
                res = (res * x) % mod;
            }

            x = (x * x) % mod;
            y = y/2;
        }
        return res;
    }

    long long count(int n) {
        long long x = (n * (n-1))/2;
        return power(2, x);
    }
}
