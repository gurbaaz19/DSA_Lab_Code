#include <bits/stdc++.h>

using namespace std;

//void mergeSort(int arr[], int begin, int end);

void merge(long long arr[], long long low, long long mid, long long high);
void mergeSort(long long arr[], long long begin, long long end);

int main() {
    long long n1, n2;

    cin >> n1 >> n2;

    long long arr[n1 + n2];

    for (long long i{0}; i < (n1 + n2); i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n1 + n2 - 1);

    return 0;
}

void merge(long long arr[], long long low, long long mid, long long high) {
    long long n1 = mid - low + 1, n2 = high - mid;
    long long left[n1], right[n2];
    for (long long i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (long long i = 0; i < n2; i++) {
        right[i] = arr[mid + i + 1];
    }

    long long i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
            k++;
        } else {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}

void mergeSort(long long arr[], long long begin, long long end) {
    if (end > begin) {
        int mid = begin + (end - begin) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}