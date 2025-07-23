#include <iostream>
#include <vector>
using namespace std;

int Lower_Bound(vector<int>& a, int x) {
    int left = 0, right = (int)a.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] < x) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    vector<int> onl;
    int a, b;

    while (cin >> a) {
        if (a == 0) break;
        cin >> b;

        int pos = Lower_Bound(onl, b); 

        if (a == 1) {
            if (pos == onl.size() || onl[pos] != b) onl.insert(onl.begin() + pos, b);
        }
        else if (a == 2) {
            if (pos == onl.size() || onl[pos] != b) cout << 0 << '\n';
            else cout << pos + 1 << '\n';
        }
    }
    return 0;
}
