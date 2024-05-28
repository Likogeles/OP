#include <iostream>
#include <Vector>
using namespace std;

void merge_sort(int arr[], int t[], int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    merge_sort(arr, t, l, m);
    merge_sort(arr, t, m + 1, r);
    for (int i = l; i <= r; ++i) {
        t[i] = arr[i];
    }
    int ai = l, bi = m + 1;
    for (int i = l; i <= r; ++i) {
        if (ai > m) {
            arr[i] = t[bi];
            bi++;
            continue;
        }
        if (bi > r) {
            arr[i] = t[ai];
            ai++;
            continue;
        }
        if (t[bi] < t[ai]) {
            arr[i] = t[bi];
            bi++;
        }
        else {
            arr[i] = t[ai];
            ai++;
        }
    }
}