#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #define MAXN 100000

int dem = 0; 

int partition(int pivot, int *a, int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        while (a[left] < pivot) {
            left++;
            dem++;
        }
        while (a[right] > pivot) {
            right--;
            dem++;
        }
        dem += 2;

        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left - 1;
}

void quicksort(int *a, int l, int r) {
    if (r > l) {
        auto pivot = a[(l + r) / 2];
        auto i = partition(pivot, a + l, r - l + 1);
        quicksort(a, l, l + i);
        quicksort(a, l + i + 1, r);
    }
}

void buildWorstCase(vector<int>& res, const vector<int>& values) {
    if (values.empty()) return;

    int mid = values.size() / 2;
    res.push_back(values[mid]);

    vector<int> left(values.begin(), values.begin() + mid);
    vector<int> right(values.begin() + mid + 1, values.end());

    buildWorstCase(res, left);
    buildWorstCase(res, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end()); 
    vector<int> res;
    buildWorstCase(res, a);   
    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i < n - 1) cout << ' ';
        else cout << '\n';
    }

    return 0;
}
