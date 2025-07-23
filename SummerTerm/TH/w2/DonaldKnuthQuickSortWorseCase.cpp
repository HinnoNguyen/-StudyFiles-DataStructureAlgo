#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long count_cmp = 0;

// Hàm partition dùng pivot giữa (Hoare-style)
int partition(vector<int>& a, int left, int right) {
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
            count_cmp++;
        }
        while (a[j] > pivot) {
            j--;
            count_cmp++;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Hàm quicksort đệ quy
void quicksort(vector<int>& a, int left, int right) {
    if (left >= right) return;
    int index = partition(a, left, right);
    quicksort(a, left, index - 1);
    quicksort(a, index, right);
}

// Anti-Quicksort: sắp xếp lại mảng để tạo worst-case
void anti_quicksort(vector<int>& a) {
    int n = a.size();
    vector<int> res;
    res.push_back(0);
    for (int i = 1; i < n; ++i) {
        int pos = res.size() / 2;
        res.insert(res.begin() + pos, i);
    }

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i) {
        a[i] = sorted[res[i]];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Tạo worst-case
    anti_quicksort(a);

    // Chạy quicksort với pivot giữa
    quicksort(a, 0, n - 1);

    // In ra count
    cout << count_cmp << endl;
    return 0;
}
