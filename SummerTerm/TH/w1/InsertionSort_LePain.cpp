#include <bits/stdc++.h>
using namespace std;

int count_inversions(const vector<int>& a) {
    int n = a.size();
    map<int, int> compress;
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    int id = 1;
    for (int x : sorted) {
        if (!compress.count(x)) compress[x] = id++;
    }

    vector<int> BIT(id + 2, 0);
    auto update = [&](int i) {
        while (i < BIT.size()) {
            BIT[i]++;
            i += i & -i;
        }
    };
    auto query = [&](int i) {
        int res = 0;
        while (i > 0) {
            res += BIT[i];
            i -= i & -i;
        }
        return res;
    };

    int inv = 0;
    for (int i = n - 1; i >= 0; --i) {
        int val = compress[a[i]];
        inv += query(val - 1);
        update(val);
    }
    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> original(n);
    for (int& x : original) cin >> x;

    vector<int> sorted = original;
    sort(sorted.begin(), sorted.end());

    int max_inv = n * (n - 1) / 2;
    int k;
    while (cin >> k) {
        // Check trivial cases
        if (k < 0 || k > max_inv) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<int> current = sorted;
        reverse(current.begin(), current.end());

        int current_inv = count_inversions(current);
        if (current_inv == k) {
            for (int i = 0; i < n; ++i)
                cout << current[i] << (i + 1 < n ? ' ' : '\n');
            continue;
        }

        bool found = false;
        for (int i = 0; i < n && current_inv > k; ++i) {
            for (int j = n - 1; j > i && current_inv > k; --j) {
                if (current[j] < current[j - 1]) {
                    swap(current[j], current[j - 1]);
                    --current_inv;
                }
            }
        }

        if (current_inv == k) {
            for (int i = 0; i < n; ++i)
                cout << current[i] << (i + 1 < n ? ' ' : '\n');
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}

// https://chatgpt.com/share/687a6e12-5d14-8001-ba88-3aaf883676d2
// https://www.youtube.com/watch?v=LEy9NdrlEGo
// https://github.com/thaituanUIT/DSA/blob/main/insertion_overload.cpp