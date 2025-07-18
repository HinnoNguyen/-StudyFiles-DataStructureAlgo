#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int insertionSortCount(vector<int> a) {
    int cnt = 0;
    for (int i = 1; i < a.size(); ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
            ++cnt; 
        }
        a[j + 1] = key;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    int k;
    while (cin >> k) {
        // kiểm tra giới hạn tối đa
        if (k > n * (n - 1) / 2) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<int> res;
        for (int i = n - 1; i >= 0; --i) {
            int pos = min(k, (int)res.size());
            res.insert(res.begin() + pos, a[i]);
            k -= pos;
        }

        if (insertionSortCount(res) != k) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
}