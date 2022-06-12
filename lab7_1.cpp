#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll solve(vector<ll> petrol, vector<ll> dist, ll k);

int main() {
    ll k{0};
    cin >> k;
    vector<ll> petrol(k), dist(k);

    for (ll i{0}; i < k; i++) {
        cin >> petrol.at(i);
        cin >> dist.at(i);
    }

    cout << solve(petrol, dist, k);

    return 0;
}

ll solve(vector<ll> petrol, vector<ll> dist, ll k) {
    ll ptr1{0}, ptr2{1};

    ll petrolLeft{petrol.at(ptr1)};
    petrolLeft -= dist.at(ptr1);

    while (ptr1 != ptr2 || petrolLeft < 0) {
        while (petrolLeft < 0 && ptr1 != ptr2) {
            petrolLeft -= petrol.at(ptr1) - dist.at(ptr1);

            ++ptr1;
            ptr1 %= k;

            if (ptr1 == 0) {
                return -1;
            }
        }

        petrolLeft += petrol.at(ptr2) - dist.at(ptr2);

        ++ptr2;
        ptr2 %= k;
    }
    return ptr1;
}
