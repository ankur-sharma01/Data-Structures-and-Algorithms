class LFUCache {
private:

    struct Node{
        int key;
        int val;
        int freq;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    int cap;
    int minFreq;

    unordered_map<int, Node*> keyMap;
    unordered_map<int, Node*> freqHeadMap;
    unordered_map<int, Node*> freqTailMap;
    unordered_map<int, int> freqSizeMap;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];
        frequencyBump(node);
        return node->val;
    }
    
    void put(int key, int value) {
        
    }
};