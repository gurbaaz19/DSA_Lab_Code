#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll parent(ll i) {
    return i / 2;
}

ll left(ll i) {
    return 2 * i;
}

ll right(ll i) {
    return 2 * i + 1;
}

void hSwap(ll *a, ll *b) {
    ll dummy = *a;
    *a = *b;
    *b = dummy;
}

void minHeapify(ll i, vector<ll> &a) {
    ll heapSize = (a.size() - 1);
    ll l = left(i);
    ll r = right(i);
    ll smallest = i;

    if (l <= heapSize && a.at(l) < a.at(i))
        smallest = l;

    if (r <= heapSize && a.at(r) < a.at(smallest))
        smallest = r;

    if (smallest != i) {
//        ll dummy = a.at(smallest);
//        a.at(smallest) = a.at(i);
//        a.at(i) = dummy;
        hSwap(&a.at(i), &a.at(smallest));
        minHeapify(smallest, a);
    }
}

void buildMinHeap(vector<ll> &a) {
    ll heapSize = (a.size() - 1);
    for (ll i = (heapSize / 2); i > 0; i--) {
        minHeapify(i, a);
    }
};

ll exMin(vector<ll> &a) {
    ll heapSize = (a.size() - 1), min{a.at(1)};
    hSwap(&a.at(a.size() - 1), &a.at(1));
    a.pop_back();
    //buildMinHeap(a);
    minHeapify(1, a);
    return min;
}

void insert(vector<ll> &a, ll cost) {
    a.push_back(cost);
    minHeapify(1, a);
}

void solve() {
    ll n, temp, add{0}, cost{0}, t1, t2;
    cin >> n;

    vector<ll> input(n + 1, 0);

    for (ll i{1}; i < n + 1; i++) {
        cin >> temp;
        input.at(i) = temp;
    }

    buildMinHeap(input);

    while (input.size() > 2) {
        t1 = exMin(input);
        t2 = exMin(input);
        add = t1 + t2;
        cost += add;
        insert(input, add);
    }

    cout << cost;
}

int main() {
    solve();
    return 0;
}