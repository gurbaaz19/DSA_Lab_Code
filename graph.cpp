#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class graph {
    int v;
    list<int> *newNode;
public:
    graph(int v) {
        this->v = v;
        newNode = new list<int>[v];
    }

    void addEdge(int i, int j, bool undirected = true) {
        newNode[i].push_back(j);
        if (undirected) newNode[j].push_back(i);
    }

    void printAdjList() {
        for (int i{0}; i < v; i++) {
            cout << i << "-->";
            for (auto node: newNode[i]) {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source) {
        queue<int> q;
        q.push(source);
        vector<bool> visited(v, false);
        visited.at(source) = true;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            cout << temp << " ";

            for (auto node: newNode[temp]) {
                if (visited.at(node) == 0) {
                    q.push(node);
                    visited.at(node) = 1;
                }
            }
        }
        cout << endl;
    }

    void dfs_recur(int node, vector<bool> &visited, vector<int> &traversed) {
        visited.at(node) = 1;
        traversed.push_back(node);
        for (auto npr: newNode[node]) {
            if (visited.at(npr) == 0) {
                dfs_recur(npr, visited, traversed);
            }
        }
    }

    void dfs(int source) {
        vector<int> traversed;
        vector<bool> visited(v, 0);
        dfs_recur(source, visited, traversed);
        for (int i{0}; i < traversed.size(); i++) {
            cout << traversed.at(i) << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.printAdjList();
    g.bfs(1);
    g.dfs(1);
    return 0;
}