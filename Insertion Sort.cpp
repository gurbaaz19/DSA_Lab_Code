#include <bits/stdc++.h>

using namespace std;

struct dog{
    int z;
    int x;
    int y;
};


void insertionSort(int arr[], int n,dog doggy[], int i);

int main() {
    int n,i;

    cin>>n;

    int arr[n];

    for (int j{0}; j < n; j++) {
        cin >> arr[j];
    }

    cin>>i;

    dog doggy[i];

    for (int k{0}; k < i; k++) {
        cin >> doggy[k].z;
        cin >> doggy[k].x;
        cin >> doggy[k].y;
        (doggy[k].z)--;
        (doggy[k].x)--;
        (doggy[k].y)--;
    }

    insertionSort(arr,n,doggy,i);

    return 0;
}

void insertionSort(int arr[], int n,dog doggy[], int i ) {
    int count{0};
    for (int a = 1; a < n; a++) {

        for(int w{0};w<i;w++){

            if(doggy[w].z==a){
                if(arr[doggy[w].y]<arr[doggy[w].x]){
                    swap(arr[doggy[w].y],arr[doggy[w].x]);
                }
            }
        }

        int key = arr[a];
        int j = a - 1;
        while (j >= 0 && arr[j] > key) {
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout<<count;
}
