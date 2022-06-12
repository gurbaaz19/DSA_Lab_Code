#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(ll r, vector<ll> &w);

int main() {
    ll n, r;

    cin >> n;

    vector<ll> w(n, 0);

    for (ll i{0}; i < n; i++) {
        cin >> w.at(i);
    }

    cin >> r;

    solve(r, w);
    return 0;
}

void solve(ll r, vector<ll> &w) {
    ll sumElements{0};

    for (auto wt: w) {
        sumElements += wt;
    }

    ll maxElement{*max_element(w.begin(), w.end())}
    , left{maxElement}, right{sumElements}, middle = (left + right) / 2, rounds{1}, sum{0};

    while (true) {

        if(left==right){
        break;
        }

        middle=(left+right)/2;
        sum = 0;
        rounds = 1;
        for (auto wt: w) {
            sum += wt;
            if (sum > middle) {
                rounds++;
                sum = wt;
            }
            else if (sum == middle) {
                rounds++;
                sum = 0;
            }
        }
        if (rounds > r) {
            left=middle+1;
        } else if (rounds <= r) {
            right=middle;
        }
    }

    cout << left;

}