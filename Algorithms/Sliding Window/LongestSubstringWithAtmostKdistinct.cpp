// Q no. 340

// here k is the hashmap size, hashmap stores number of unique elements.
// for exactly k

int high = 0, low = 0;
unordered_map<int, int> freq;
int result = 0;
for(high = 0; high < n; high++) {

    freq[nums[high]]++;

    while(freq.size() > k) {
        freq[nums[low]]--;
        if(freq[nums[low]] == 0) {
            freq.erase(nums[low]);
        }
        low++;
    }
    if(freq.size() == k) {
        int size = high - low + 1;
        result = max(size, result);
    }
}
return result;

// T.C. = O(n)