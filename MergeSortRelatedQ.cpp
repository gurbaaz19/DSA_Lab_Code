//#include <bits/stdc++.h>
//
//using namespace std;
//
//void merge(long long arr[], long long low, long long mid, long long high);
//
//void mergeSort(long long arr[], long long begin, long long end);
//
//int main() {
//    long long n, k;
//
//    cin >> n >> k;
//
//    long long arr[n * k];
//
//    for (long long i{0}; i < (n * k); i++) {
//        cin >> arr[i];
//    }
//
//    mergeSort(arr, 0, (n * k) - 1);
//
//    for (long long i{0}; i < (n * k); i++) {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}
//
//void merge(long long arr[], long long low, long long mid, long long high) {
//    long long n1 = mid - low + 1, n2 = high - mid;
//    long long left[n1], right[n2];
//    for (long long i = 0; i < n1; i++) {
//        left[i] = arr[low + i];
//    }
//    for (long long i = 0; i < n2; i++) {
//        right[i] = arr[mid + i + 1];
//    }
//
//    long long i = 0, j = 0, k = low;
//    while (i < n1 && j < n2) {
//        if (left[i] <= right[j]) {
//            arr[k] = left[i];
//            i++;
//            k++;
//        } else {
//            arr[k] = right[j];
//            j++;
//            k++;
//        }
//    }
//    while (i < n1) {
//        arr[k] = left[i];
//        i++;
//        k++;
//    }
//    while (j < n2) {
//        {
//            arr[k] = right[j];
//            j++;
//            k++;
//        }
//    }
//}
//
//void mergeSort(long long arr[], long long begin, long long end) {
//    if (end > begin) {
//        long long mid = begin + (end - begin) / 2;
//        mergeSort(arr, begin, mid);
//        mergeSort(arr, mid + 1, end);
//        merge(arr, begin, mid, end);
//    }
//}



#include <bits/stdc++.h>

using namespace std;

#define bigNumber long long

void merge(bigNumber arr[], bigNumber low, bigNumber mid, bigNumber high);

int main() {
    bigNumber n, k;

    cin >> n >> k;

    bigNumber arr[n * k];

    for (bigNumber i{0}; i < (n * k); i++) {
        cin >> arr[i];
    }

    for(bigNumber i{1}; i < k; i++)
        merge(arr, 0, n*i-1, n*(i+1) - 1);

    for(bigNumber i{0}; i < k * n; i++)
        cout<<arr[i]<<" ";

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
