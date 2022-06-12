#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node;

void solve(vector<ll> &input, ll n);

node *newNode(ll value);

node *createBST(vector<ll> &input, ll start, ll end);


int main() {
    ll n{0}, k{0};
    cin >> n;
    vector<ll> input(n);
    for (ll i{0}; i < n; i++) {
        cin >> input.at(i);
    }
    cin >> k;

    solve(input, n);

    return 0;
}

struct node {
    ll value;
    node *left, *right;
};

void solve(vector<ll> &input, ll n) {
    std::sort(input.begin(), input.end());
    node *root = createBST(input, 0, n - 1);
    node*parent=root;
    node*gparent=parent;
    while(root!= nullptr){
        gparent=parent;
        parent=root;
        root=root->right;
    }

    ll greatest=parent->value,greatest2=gparent->value;

    cout<<greatest-greatest2;

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

