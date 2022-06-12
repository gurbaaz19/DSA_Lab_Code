#include <bits/stdc++.h>

using namespace std;

#define bigNumber long long

void solve(vector<bigNumber> input);

int main() {
    bigNumber n;
    cin >> n;
    vector<bigNumber> input(n, 0);

    for (bigNumber i = 0; i < n; i++) {
        cin >> input.at(i);
    }

    solve(input);

    return 0;
}

void solve(vector<bigNumber> input) {
    auto smallest = input.at(0), maxProfit = input.at(1) - input.at(0);

    for (auto item: input) {
        maxProfit = ((item - smallest) > maxProfit) ? (item - smallest) : maxProfit;
        smallest = (item < smallest) ? item : smallest;
    }

    cout << maxProfit;
}