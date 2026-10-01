/*
 * QUESTION:
 *
 * A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
 * Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
 * A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
 *
 * Example 1:
 * Input: n = 1
 * Output: 5
 * Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
 *
 * Example 2:
 * Input: n = 4
 * Output: 400
 *
 * Example 3:
 * Input: n = 50
 * Output: 564908303
 *
 * Find it: https://www.google.com/search?q=A%20digit%20string%20is%20good%20if%20the%20digits%20%280-indexed%29%20at%20even%20indices%20are%20even%20and%20the%20digits%20at
 */

// ---- write your solution below ----

class Solution {
public:
    /*

    Bit = 1           Bit = 0             Bit = 1             Bit = 1
                    (LSB of 13)         (LSB of 6)          (LSB of 3)          (LSB of 1)
                    ───────────         ──────────          ──────────          ──────────
    base:           3^1  =======>       3^2  =======>       3^4  =======>       3^8
                        │                   │                   │                   │
                        │ (Keep!)           │ (Ignore)          │ (Keep!)           │ (Keep!)
                        ▼                   ▼                   ▼                   ▼
    result:            3^1        x         1         x        3^4        x        3^8   =  3^13

    */

    long long mod = 1e9 + 7;
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base = base % mod;

        while (exp > 0)
        {
            // Notice that every single power of 2 except the last one (2^0 = 1) is an EVEN number (2, 4, 8, 16...).Any combination of even numbers added together is always even.Therefore, the only thing that can make a binary number odd is if the 2^0 bit (the LSB) is set to 1. If LSB is 1 implies Number is ODD If LSB is 0 implies Number is EVEN.
            if (exp & 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp = exp >> 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        // Indices: [0, 1, 2, 3, 4], 3 Evens (0, 2, 4), 2 Odds (1, 3).evenCount = (5 + 1) / 2 = 3, oddCount = 5 / 2 = 2
        long long even = (n+1)/2;
        long long odd = n/2;

        long long evenPow = modPow(5, even);
        long long oddPow = modPow(4, odd);

        return (evenPow * oddPow) % mod;
    }
};
