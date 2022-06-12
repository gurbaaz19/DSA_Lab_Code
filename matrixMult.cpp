#include <bits/stdc++.h>

using namespace std;

#define ulli unsigned long long int

const ulli MOD_CONST = 1e9 + 7;

void fibAtN(ulli n);

void mult(ulli matrix1[2][2], ulli matrix2[2][2]);

void power(ulli n, ulli matrix[2][2]);

int main() {
    ulli n{0};

    cin >> n;

    fibAtN(n);

    return 0;
}

void fibAtN(ulli n) {
    ulli matrix[2][2] = {{1, 1},
                         {1, 0}};
    if (!n) {
        cout << 0;
        return;
    }
    power(n - 1, matrix);

    cout << matrix[0][0];
}

void power(ulli n, ulli matrix[2][2]) {
    if (!n)
        return;

    else if (n == 1)
        return;

    ulli matrix2[2][2] = {{1, 1},
                          {1, 0}};

    power(n / 2, matrix);
    mult(matrix, matrix);

    if ((n % 2))
        mult(matrix, matrix2);
}

void mult(ulli matrix1[2][2], ulli matrix2[2][2]) {
    ulli a{(matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1]) % MOD_CONST},
            b{(matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0]) % MOD_CONST},
            c{(matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1]) % MOD_CONST},
            d{(matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0]) % MOD_CONST};

    matrix1[0][0] = d;
    matrix1[0][1] = c;
    matrix1[1][0] = b;
    matrix1[1][1] = a;
}