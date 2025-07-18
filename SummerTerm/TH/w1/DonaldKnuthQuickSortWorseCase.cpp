#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dem = 0;

void anti_quicksort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 2; i < n; i++) {
        int j = i / 2;
        if (i != j) { 
            swap(arr[i], arr[j]);
            dem++;
        }
    }
}

int main() {
    int n;    
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    anti_quicksort(arr);

    cout << dem << endl;

    return 0;
}