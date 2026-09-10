unordered_map<int, int> freq;
int n = s.size();
int high = 0, low = 0;
int max_size = 0;

for(high = 0; high < n; high++) {

    freq[s[high]]++;

    while(freq[s[high]] > 1) {
        freq[s[low]]--;
        if(freq[s[low]] == 0) {
            freq.erase(s[low]);
        }
        low++;
    }


    int size = high - low + 1;
    max_size = max(size, max_size);


}
return max_size;

// another approach we can use is that compare the size of freq(hashmap) and orignal array. ---- find it yourself.