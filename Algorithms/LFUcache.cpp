// we will rob houses which are not consecuttive. ek ke baad ek nhi hona chahiye.

// use of recurssion - check at each step for all the possibility, ki chod skte hai to kya hoga aur include kra to kya hoga.

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

class LFUCache {
public:
    vector<int> usage;
    unordered_map<int, int> store;
    int max_capacity = 0;
    LFUCache(int capacity) {
        max_capacity = capacity;

        // resize the usage vector: it is dynamic but only when we use push and pop. we aren't using that here so we need to declare it before hand.
        usage.resize(10005, -1);
        // can also declare at top: used this as this was something new.
    }
    
    int get(int key) {
        // vector<int> usage;

        if(store.find(key) != store.end()) {
            // usage[key]++;
            // return key ---- wrong
            if(usage[key] == -1) {
                usage[key] = 1;
            } else {
                usage[key]++;
            }
            return store[key];
        } else {
            return -1;
        }
        
    }
    
    void put(int key, int value) {

        // unordered_map<int, int> store;

        // vector<int> store(10, -1);


        // store.push({value}) // push can't let us push at a specific space in a vector.

        // store.insert(store.begin() + key, value);
        
        // if(store.size() > max_capacity) --- no eviction for already present element and we are checking size and capacity not indexes so we also need to look for equal sign.
        if(store.size() >= max_capacity && store.find(key) == store.end()) {

            // evict the least used, find using usage vector.
            int least_visited = INT_MAX;
            int indexOfLeastVisit = 0;

            for(int i = 0; i < usage.size(); i++) {
                if (usage[i] == -1) continue;
                
                // least_visited = min(least_visited, usage[i]); --- this won't give the index needed so we will just use block for this.
                
                if(least_visited > usage[i]) {
                    indexOfLeastVisit = i;
                    least_visited = usage[i]; // updating to check in the comparision part.
                }

                // return least_visited; ---- this will exit in the first iteration itself
            }

            // usage[indexOfLeastVisit]--; ---- restart completely.
            usage[indexOfLeastVisit] = -1;
            store.erase(indexOfLeastVisit);
            // store.erase(least_visited)
        }

        // store.push({key, value}); --- no push used in a hashmap.
        store[key] = value;
        // usage[key]++;
        if(usage[key] == -1) {
            usage[key] = 1;
        } else {
            usage[key]++;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */