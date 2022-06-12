#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct graph {
    ll vertex;
    list<ll> *newList;
public:
    explicit graph(ll v) {
        this->vertex = v;
        this->newList = new list<ll>[v];
    }

    void addEdge(ll i, ll j, bool undirected = true) const {
        newList[i].push_back(j);
        if (undirected) newList[j].push_back(i);
    }

    void printAdjList() {
        for (ll i{0}; i < vertex; i++) {
            cout << i << "-->";
            for (auto node: newList[i]) {
                cout << node << " ";
            }
            cout << endl;
        }
    } // was using to test input

    void dfsTraversalTool(vector<bool> &visited, ll index) {
        auto it = newList[index].begin();

        for (; it != newList[index].end(); ++it) {
            if (!visited.at(*it)) {
                visited.at(*it) = true;
                dfsTraversalTool(visited, *it);
            }
        }
    }

    ll numberOfCities() {
        vector<bool> visited(vertex, false);
        ll citiesCount{0}, index{0};

        for (bool check: visited) {
            if (!check) {
                visited.at(index) = true;
                dfsTraversalTool(visited, index);
                ++citiesCount;
            }
            ++index;
        }

        return citiesCount;
    }
};

ll solve();

int main() {
    ll queriesCount{0};
    cin >> queriesCount;

    while (queriesCount > 0) {
        cout << solve() << endl;
        --queriesCount;
    }
    return 0;
}

ll solve() {
    ll villagesCount{0}, citiesCount{0}, roadsCount{0}, villageX{0}, villageY{0};
    cin >> villagesCount >> roadsCount;
    graph villages(villagesCount);
    for (ll i{0}; i < roadsCount; i++) {
        cin >> villageX >> villageY;
        villages.addEdge(villageX - 1, villageY - 1);
    }

    citiesCount = villages.numberOfCities();

    return citiesCount;
}