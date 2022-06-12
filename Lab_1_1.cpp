#include <bits/stdc++.h>

using namespace std;

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int n{0};
    cin>>n;
    vector<int> input(n,0);

    for(int i=0;i<n;i++){
        cin>>input.at(i);
    }

    sort(input.begin(), input.end(),greater<int>());

    cout<<input.at(0)+input.at(1);
}
