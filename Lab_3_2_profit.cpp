#include <bits/stdc++.h>

using namespace std;

#define bigNumber long long

class threeTuple {
public:
    bigNumber L, H, S;

    threeTuple(
            bigNumber cL,
            bigNumber cH,
            bigNumber cS
    ) {
        L = cL;
        H = cH;
        S = cS;
    }
};

threeTuple maxSubSec(vector<bigNumber>, bigNumber low, bigNumber high);

threeTuple maxCrossSubSec(vector<bigNumber>, bigNumber low, bigNumber mid, bigNumber high);

int main() {
    bigNumber n;
    cin >> n;
    vector<bigNumber> input0(n, 0);
    vector<bigNumber> input1;

    for (bigNumber i = 0; i < n; i++) {
        cin >> input0.at(i);
    }

    input1.push_back(0);
    for (int i = 1; i < n; i++) {
        input1.push_back(input0.at(i) - input0.at(i - 1));
    }


    threeTuple output = maxSubSec(input1, 0, n-1);

    cout << output.S;
    return 0;
}

threeTuple maxCrossSubSec(vector<bigNumber> sec, bigNumber low, bigNumber mid, bigNumber high) {
    bigNumber leftSum = LONG_LONG_MIN, sum = 0, maxLeft = low;
    for (bigNumber i = mid; i >= low; i--) {
        sum += sec.at(i);
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    bigNumber rightSum = LONG_LONG_MIN, maxRight = high;
    sum = 0;
    for (bigNumber j = mid + 1; j <= high; j++) {
        sum += sec.at(j);
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }

    threeTuple output(maxLeft, maxRight, leftSum + rightSum);
    return output;
}

threeTuple maxSubSec(vector<bigNumber> sec, bigNumber low, bigNumber high) {
    if (high == low) {
        threeTuple output0(low, high, sec.at(low));
        return output0;
    }
    else {
        bigNumber mid;
        mid = (low + high) / 2;
        threeTuple output1 = maxSubSec(sec, low, mid);
        threeTuple output2 = maxSubSec(sec, mid + 1, high);
        threeTuple output3 = maxCrossSubSec(sec, low, mid, high);

        if (output1.S >= output2.S && output1.S >= output3.S)
            return output1;
        else if (output2.S >= output1.S && output2.S >= output3.S)
            return output2;
        else
            return output3;
    }
}