#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count = 0;

int partition(int pivot, int *a, int n) {
        int left = 0, right = n - 1;
        while (left <= right) {
                while (a[left] < pivot){
                        left++;  
                        count++;
                }
                while (a[right] > pivot){
                        right--;
                        count++;
                }
                count += 2;

                if (left <= right)
                {
                        swap(a[left], a[right]);
                        left++;
                        right--;
                }
        }
        return left-1;
}



void quicksort(int *a, int l, int r){
    if (r > l){
        auto pivot = a[(l+r)/2];
        auto i = partition(pivot, a+l, r-l+1);
        quicksort(a, l, l+i);
        quicksort(a, l+i+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), worst(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Sinh worst-case: anti-median
    sort(a.begin(), a.end());
    int l = 0, r = n - 1, idx = 0;
    while (l <= r) {
        if (idx % 2 == 0) worst[idx++] = a[l++];
        else worst[idx++] = a[r--];
    }

    // Gọi quicksort trên mảng worst-case
    quicksort(worst.data(), 0, n - 1);

    cout << count << endl;
    return 0;
}