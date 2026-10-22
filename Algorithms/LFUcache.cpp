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

#include <vector>
#include <unordered_map>
#include <climits>

class LFUCache {
public:
    int max_capacity;
    std::unordered_map<int, int> store; // key -> value
    std::unordered_map<int, int> freq;  // key -> frequency count
    
    LFUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        // If key doesn't exist, return -1
        if (store.find(key) == store.end()) {
            return -1;
        }
        
        // Bump frequency on access
        freq[key]++;
        return store[key];
    }
    
    void put(int key, int value) {
        if (max_capacity <= 0) return;

        // If key already exists, update value and bump frequency
        if (store.find(key) != store.end()) {
            store[key] = value;
            freq[key]++;
            return;
        }
        
        // If at capacity, we need to evict the least frequently used item
        if (store.size() >= max_capacity) {
            int least_visited = INT_MAX;
            int keyToEvict = -1;

            // Search through all keys to find the one with the lowest frequency
            for (auto& pair : freq) {
                int k = pair.first;
                int f = pair.second;
                
                if (f < least_visited) {
                    least_visited = f;
                    keyToEvict = k;
                }
            }

            // Evict the least frequent key
            store.erase(keyToEvict);
            freq.erase(keyToEvict);
        }

        // Insert new key-value pair with frequency starting at 1
        store[key] = value;
        freq[key] = 1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */