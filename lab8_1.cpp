#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node;

void solve(vector<ll> &input, ll n, ll k);

node *newNode(ll value);

node *createBST(vector<ll> &input, ll start, ll end);

bool getPairFromBST(node *root, ll k, unordered_set<ll> &mySet);


int main() {
    ll n{0}, k{0};
    cin >> n;
    vector<ll> input(n);
    for (ll i{0}; i < n; i++) {
        cin >> input.at(i);
    }
    cin >> k;

    solve(input, n, k);

    return 0;
}

struct node {
    ll value;
    node *left, *right;
};

void solve(vector<ll> &input, ll n, ll k) {
    std::sort(input.begin(), input.end());
    node *root = createBST(input, 0, n - 1);
    unordered_set<ll> mySet;
    if (!getPairFromBST(root, k, mySet)) {
        cout << "NULL";
    }
}

node *newNode(ll value) {
    node *newNode = new node();
    newNode->value = value;
    newNode->right = newNode->left = nullptr;
    return newNode;
}

node *createBST(vector<ll> &input, ll start, ll end) {
    if (start > end)
        return nullptr;

    ll mid = (start + end) / 2;
    node *root = newNode(input.at(mid));

    root->left = createBST(input, start,
                           mid - 1);

    root->right = createBST(input, mid + 1, end);

    return root;
}

bool getPairFromBST(node *root, ll k, unordered_set<ll> &mySet) {
    if (root == nullptr) {
        return false;
    }
    if (getPairFromBST(root->left, k, mySet)) {
        return true;
    }
    if (mySet.find(k - root->value) != mySet.end()) {
        cout << k - root->value << " " << root->value;
        return true;
    } else {
        mySet.insert(root->value);
    }

    return getPairFromBST(root->right, k, mySet);
}

