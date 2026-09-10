#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// (SBI)^2 - Q^2 - MHlog = Selection, bubble, insertion, quick sort == n^2, merge and heap sort == nlog(n) ----> worst case complexity.

// intro to map:
    // types: ordered, unordered, multiorder.
    // refer to other map files in the data structures folder!

    // before starting, i is the entry, i.first is the key, i.second is the list of elements associated with i.first. we need to traverse along i.second than move to next i.first for further process.
class graph{

    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool direction) { // u is the key and v is the value for any node.

            // direction = 0 -> undirected and direction = 1 -> directed.
            //create an edge from u to v

            adj[u].push_back(v); // indirectional graph only.
            // back linking as the graph is undirected.
            if(direction == 0) {
                adj[v].push_back(u);
            }
            // 0 -> {1} also means 1 -> {0}
        }

        void printadj() {
            for(auto i:adj) { // i:adj is map pair.
                cout << i.first << "-> ";
                for(auto j: i.second) { // traversing through full list which belongs to i.first key.
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};

int main() {

    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph g;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // printing graph
    g.printadj();
}

int vector<vector<int>> printAdj(int n, int m, vector <vector <int >> & edges) {
    vector<int> ans[n];
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans(u).push_back(v);
        ans(v).push_back(u);
    }
} // we are making array of vectors. each index represents a list i.e. vector.