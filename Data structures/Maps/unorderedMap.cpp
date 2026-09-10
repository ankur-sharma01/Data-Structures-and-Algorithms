#include<bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> &m) {
    cout << m.size() << endl;
    for(auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main() {
    // sorted output if in numerical form and lexiographical if string.
    // ordered maps use trees for inbuilt implementation while unordered maps use hash tables.
    unordered_map<int, string> m;
    m[1] = "abcd";
    m[5] = "cdc";
    m[3] = "abc";

    m.insert({4, "afd"});

    for(it = m.begin(); it != m.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    auto it = m.find(3);
    if(it == m.end()) {
        cout << "No Value" << endl;
    } else {
        cout << (*it).first << " " << (*it).second << endl;
    }

    if(it != m.end()) m.erase(it);
    print(m);
    m.clear();

}