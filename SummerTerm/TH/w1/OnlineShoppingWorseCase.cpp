#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long> onl;
    int a;
    long b;

    while (cin >> a && a != 0) {
        cin >> b;
        auto pos = lower_bound(onl.begin(), onl.end(), b);
        if (a == 1) {
            if (pos == onl.end() || *pos != b) {
                onl.insert(pos, b);  // chèn đúng vị trí
            }
        } else if (a == 2) {
            if (pos == onl.end() || *pos != b) {
                cout << 0 << '\n';
            } else {
                cout << (pos - onl.begin()) + 1 << '\n';  // vị trí bắt đầu từ 1
            }
        }
    }

    return 0;
}


// https://chatgpt.com/share/68776442-1808-8001-a705-3067846142e1