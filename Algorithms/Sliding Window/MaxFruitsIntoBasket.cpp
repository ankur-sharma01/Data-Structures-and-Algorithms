// Q. No. 904
// fruits into baskets.

// exactly one fruit from each tree, meaning no. of fruits = no. of trees selected.

int high = 0, low = 0;
int k = 2;
int max_fruits = 0;
int n = fruits.size();

unordered_map<int, int> countOfTrees;

for(high = 0; high < n; high++) {
    countOfTrees[fruits[high]]++;

    while(countOfTrees.size() > k) {
        countOfTrees[fruits[low]]--;
        if(countOfTrees[fruits[low]] == 0) {
            countOfTrees.erase(fruits[low]);
        }
        low++;
    }
    // not neccessary to fill all the basket so no if block needed, freq.size() < k is handled seperately.
        fruit = high - low + 1;
        max_fruits = max(max_fruits, size);
    
}
return max_fruits;



