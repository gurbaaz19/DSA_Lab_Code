#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef vector<vector<ll>> BlockType;

ll indexNumber{0};

void populateTiles(ll tileX1, ll tileY1, ll tileX2, ll tileY2, ll tileX3, ll tileY3, BlockType &land);

void recursiveSolve(ll n, ll startingRow, ll startingColumn, BlockType &land);

void printMap(BlockType &land, ll size);

int main() {
    ll n{0}, a{0}, b{0};
    cin >> n >> a >> b;

    vector<ll> row(n, 0);
    BlockType land(n, row);
    land.at(a - 1).at(b - 1) = -1;

    recursiveSolve(n, 0, 0, land);

    printMap(land, n);

    return 0;
}

void populateTiles(ll tileX1, ll tileY1, ll tileX2, ll tileY2, ll tileX3, ll tileY3, BlockType &land) {
    indexNumber++;
    land.at(tileX1).at(tileY1) = indexNumber;
    land.at(tileX2).at(tileY2) = indexNumber;
    land.at(tileX3).at(tileY3) = indexNumber;
}

void recursiveSolve(ll n, ll startingRow, ll startingColumn,
                    BlockType &land) {
    ll poolRow{0}, poolCol{0};
    if (n == 2) {
        indexNumber++;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (land.at(startingRow + i).at(startingColumn + j) == 0) {
                    land.at(startingRow + i).at(startingColumn + j) = indexNumber;
                }
            }
        }
        return;
    } else {
        for (ll i = startingRow; i < startingRow + n; i++) {
            for (ll j = startingColumn; j < startingColumn + n; j++) {
                if (land.at(i).at(j) != 0) {
                    poolRow = i;
                    poolCol = j;
                }
            }
        }
    }

    if (poolRow < startingRow + n / 2 && poolCol < startingColumn + n / 2) {
        populateTiles(startingRow + n / 2, startingColumn + (n / 2) - 1, startingRow + n / 2, startingColumn + n / 2,
                      startingRow + n / 2 - 1, startingColumn + n / 2, land);
    } else if (poolRow >= startingRow + n / 2 && poolCol < startingColumn + n / 2) {
        populateTiles(startingRow + (n / 2) - 1, startingColumn + (n / 2), startingRow + (n / 2),
                      startingColumn + n / 2, startingRow + (n / 2) - 1, startingColumn + (n / 2) - 1, land);
    } else if (poolRow < startingRow + n / 2 && poolCol >= startingColumn + n / 2) {
        populateTiles(startingRow + n / 2, startingColumn + (n / 2) - 1, startingRow + n / 2, startingColumn + n / 2,
                      startingRow + n / 2 - 1, startingColumn + n / 2 - 1, land);
    } else if (poolRow >= startingRow + n / 2 && poolCol >= startingColumn + n / 2) {
        populateTiles(startingRow + (n / 2) - 1, startingColumn + (n / 2), startingRow + (n / 2),
                      startingColumn + (n / 2) - 1, startingRow + (n / 2) - 1, startingColumn + (n / 2) - 1, land);
    }

    recursiveSolve(n / 2, startingRow, startingColumn + n / 2, land);
    recursiveSolve(n / 2, startingRow, startingColumn, land);
    recursiveSolve(n / 2, startingRow + n / 2, startingColumn, land);
    recursiveSolve(n / 2, startingRow + n / 2, startingColumn + n / 2, land);

}

void printMap(BlockType &land, ll size) {
    for (ll i{0}; i < size; i++) {
        for (ll j{0}; j < size; j++) {
            cout << land.at(i).at(j) << " ";
        }
        cout << endl;
    }
}