#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Not gonna print, i only write the code to remember and study

    // Muon test thi..
    // LinearSearch(a, n);
    // BinarySearch(a, n);

    return 0;
}


void LinearSearch (vector<int> &a, int x) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == x) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}


void BinarySearch (vector<int> &a, int x) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    cout << "Element not found" << endl;
}

