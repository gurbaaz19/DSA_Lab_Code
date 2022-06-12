#include <bits/stdc++.h>

using namespace std;

void solve();
bool ifPalindrome(int n);

int main() {
    solve();
    return 0;
}

void solve() {
    int n=5;
    int count{0};

    vector<int> input(n,0);

    for(int i=0;i<n;i++){
        cin>>input.at(i);
    }

    for(int i=0;i<n;i++){
        if(ifPalindrome(input.at(i))){
            count++;
            if(count>2){
                cout<<"YES";
                return;
            }
        }
    }
    cout<<"NO";
}

bool ifPalindrome(int n) {
    int original = n;
    int reverse = 0;
    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n = n / 10;
    }

    return (reverse == original);
}