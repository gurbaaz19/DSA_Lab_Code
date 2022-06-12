#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(vector<ll> &price, vector<ll> &answer);

int main() {
    ll size{0};
    cin >> size;

    if(size!=0) {
        vector<ll> price(size), answer(size);

        for (ll i{0}; i < size; i++) {
            cin >> price.at(i);
        }

        solve(price, answer);
    }
    return 0;
}

void solve(vector<ll> &price, vector<ll> &answer) {
    vector<ll> temp;
    temp.push_back(0);

    answer.at(0) = 1;

    ll j{1};

    while (j < (ll) price.size()) {
        while (temp.empty() == false && price.at(temp.at(temp.size() - 1)) < price.at(j) + 1) {
            temp.pop_back();
        }

        if (temp.empty()==false) {
            answer.at(j) = j - temp.at(temp.size() - 1);
        } else {
            answer.at(j) = j + 1;
        }

        temp.push_back(j);
        j++;
    };

    for (auto item: answer) {
        cout << item << " ";
    }
}
