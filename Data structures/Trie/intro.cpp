#include<iostream>
using namespace std;

// use - making of a dictionary with add word, search, remove word.
// Hashmap can be used but due to time complexity, it will take more time.

// now we see trie: A main ROOT, which has child attached to it, we find char or element matching, if present look for next, if not then create one.

class Trienode{
    public:
        char data;
        Trienode* children[26];
        bool isTerminal;

    Trienode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

// The Trie (Manager) is the Station Master.

// The root is the First Carriage of the train.

// Each carriage is a Trienode.

class Trie{
    public:
        Trienode* root; // making first node with the properties of trienode.
    
    void insertUtil(Trienode* root, string word) {

        if(word.length == 0) {
            root -> isTerminal = true;
        }

        int index = word[0] - 'A'; // first word index calculation in the array/vector.
        trienode* child;

        if(root -> children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));

    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(Trienode* root, string word) {
        // base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        Trienode* child;

        // present
        if(root -> children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(child, word);
    }
};

int main() {

}