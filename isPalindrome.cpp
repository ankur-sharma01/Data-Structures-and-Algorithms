class Solution {
public:
    bool isPalindrome(int x) {
        // Step 1: Handle instant false edge cases
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        
        // Step 2: Reverse the second half of the number
        // The loop stops once the reversed half becomes greater than or equal to the remaining first half
        while (x > reversedHalf) {
            int lastDigit = x % 10;
            reversedHalf = reversedHalf * 10 + lastDigit;
            x /= 10; // Truncate the last digit from x
        }

        // Step 3: Check for equality
        // For even-length numbers (e.g., 1221): x will equal reversedHalf (12 == 12)
        // For odd-length numbers (e.g., 12321): x will be 12, reversedHalf will be 123. 
        // We get rid of the middle digit by doing reversedHalf / 10.
        return x == reversedHalf || x == reversedHalf / 10;
    }
};