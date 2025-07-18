#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    int k;
    while (cin >> k) {
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

        for (int i = 0; i < n; ++i) {
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
