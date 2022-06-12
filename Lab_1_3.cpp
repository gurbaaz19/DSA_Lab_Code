#include <bits/stdc++.h>

using namespace std;

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    unsigned int n{0}, result{0};
    cin >> n;
    for (unsigned int i = 5; i <= n; i *= 5) {
        result += n / i;
    }
    cout << result;
}