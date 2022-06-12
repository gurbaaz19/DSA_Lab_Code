#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod=1e9+7;

ll solve(ll n){
    vector<ll> arr(n+1,0);
    arr.at(0)=1;
    for(ll i{0};i<=n;i++){
        for(ll j{1};j<=6;j++){
            if(i-j>=0) arr.at(i)+=arr.at(i-j);
            arr.at(i)%=mod;
        }
    }
    return arr.at(n);
}

int main(){
    ll n{0};
    cin>>n;

    cout<<solve(n);
    return 0;
}