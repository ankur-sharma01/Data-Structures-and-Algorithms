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

class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        // initializer
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;

    unordered_map<int, Node*> cacheMap;

    Node* dummyHead;
    Node* dummyTail;

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertToFront(Node* node) {
        Node* nextNode = dummyHead->next;
        dummyHead->next = node;
        node->prev = dummyHead;
        node->next = nextNode;
        nextNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        dummyHead = new Node(0, 0);
        dummyTail = new Node(0, 0);
        // bridging is an important thing to do: it is absolutely critical! Skipping that step would cause your program to crash immediately on the very first put or get operation.
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        Node* node = cacheMap[key];
        remove(node);
        insertToFront(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end())
        {
            Node* node = cacheMap[key];
            node->val = value;
            remove(node);
            insertToFront(node);
            return;
        }

        if (cacheMap.size() == cap)
        {
            Node* lru = dummyTail->prev;
            remove(lru);
            cacheMap.erase(lru->key);
            delete lru;
        }

        // create new node and add it to front:
        Node* newNode = new Node(key, value);
        cacheMap[key] = newNode;
        insertToFront(newNode);
    }
};
