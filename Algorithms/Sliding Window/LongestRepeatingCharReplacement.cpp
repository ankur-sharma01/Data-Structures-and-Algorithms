// Q. No. 424

// TODO: DO IT AGAIN:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.


// wrong as we don't need to flip it actually, we just need to calculate the range where distinct member freq is equal to k.
int flips = 0;
int high = 0, low = 0;
int max_size = INT_MIN;
for(high = 0; high < n; high++) {

    freq[s[high]]++;

    int size = high - low + 1;

    if(freq.size() > 1) {
        if(flips < k) {
            s[high] = s[low];
            flips++;
            freq[s[high]]--;
            freq[s[low]]++;
            size = high - low + 1;
        } else {
            while(freq.size() < 2) {
                freq[s[low]]--;
                if(freq[s[low]] == 0) {
                    freq.erase(s[low]);
                }
                low++;
            }
            flips = 0;
        }
        max_size = max(max_size, size);
    }
    
}
return max_size;
// it's a mental solution but won't work in real life.


// correct code:
class Solution {
public:
    // Fix 1: Move the find function outside so it's a normal class method
    // normal traversing using for loop.
    int find(int freq[]) {
        int max_freq = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
            }
        }
        return max_freq;
    }

    int characterReplacement(string s, int k) {
        int high = 0, low = 0;
        int max_size = 0; // Use 0 instead of INT_MIN for safe string lengths
        int freq[26] = {0}; 

        for(high = 0; high < s.size(); high++) {
            // Fix 2: Map characters to 0-25 index range
            freq[s[high] - 'A']++;

            int size = high - low + 1;
            int max_count = find(freq);
            int diff = size - max_count;

            while(diff > k) {
                // Fix 2: Map characters to 0-25 index range here too
                freq[s[low] - 'A']--; 
                low++;
                
                max_count = find(freq);
                size = high - low + 1;
                diff = size - max_count;
            }

            size = high - low + 1;
            max_size = max(max_size, size);
        }
        return max_size;
    }
};

