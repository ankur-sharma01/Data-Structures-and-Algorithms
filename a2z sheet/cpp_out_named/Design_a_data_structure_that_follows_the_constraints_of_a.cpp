/*
 * QUESTION:
 *
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *
 * Example:
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 * Find it: https://www.google.com/search?q=Design%20a%20data%20structure%20that%20follows%20the%20constraints%20of%20a%20Least%20Recently%20Used%20%28LRU%29%20cache.
 */

// ---- write your solution below ----


