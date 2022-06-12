#include <bits/stdc++.h>

using namespace std;

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    long long n{0}, k{0}, count{0};
    cin >> n >> k;

    vector<long long> x(n, 0);
    vector<long long> y(n, 0);

    for (long long i{0}; i < n; i++) {
        cin >> x.at(i);
        cin >> y.at(i);
    }

    long long ksq = k * k;
    long long lsq{0};
    for (long long i{0}; i < n; i++) {

        lsq = x.at(i) * x.at(i) + y.at(i) * y.at(i);

        if (lsq <= ksq) {
            count++;
        }
    }

    cout << count;

}