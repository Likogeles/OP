#include <iostream>
#include <Vector>
using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

vector<int> quickSort(vector<int> arr) {
    if (arr.size() <= 1)
        return arr;
    int pivot = arr[0];
    vector<int> less;
    vector<int> high;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] <= pivot) {
            less.push_back(arr[i]);
        }
        else {
            high.push_back(arr[i]);
        }
    }
    vector<int> new_v = quickSort(less);
    new_v.push_back(pivot);
    for (int i : quickSort(high))
    {
        new_v.push_back(i);
    }
    return new_v;
}