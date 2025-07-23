#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dem = 0;

int partition(int pivot, int *a, int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        while (a[left] < pivot){
            left++;  
            dem++;
        }
        while (a[right] > pivot){
            right--;
            dem++;
        }
        dem += 2;

        if (left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left - 1;
}

void quicksort(int *a, int l, int r){
    if (r > l){
        int pivot = a[(l + r) / 2];
        int i = partition(pivot, a + l, r - l + 1);
        quicksort(a, l, l + i);
        quicksort(a, l + i + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Tạo hoán vị zig-zag gây worst-case cho QuickSort
    sort(a.begin(), a.end());
    vector<int> b;
    int l = 0, r = n - 1;
    bool turn = true;
    while (l <= r) {
        if (turn) b.push_back(a[r--]);
        else b.push_back(a[l++]);
        turn = !turn;
    }
    a = b;

    quicksort(a.data(), 0, n - 1);

    cout << dem << '\n';

    return 0;
}
