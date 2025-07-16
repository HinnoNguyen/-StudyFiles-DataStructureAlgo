#include <iostream>
using namespace std;

long onl[1000000];
int size_onl = 0;

bool exists(long x) {
    int l = 0, r = size_onl - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (onl[mid] == x) return true;
        else if (onl[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int find_pos(long x) {
    int l = 0, r = size_onl;
    while (l < r) {
        int mid = (l + r) / 2;
        if (onl[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    int a;
    long b;
    while (cin >> a) {
        if (a == 0) break;
        cin >> b;

        int pos = find_pos(b);
        if (a == 1) {
            if (pos == size_onl || onl[pos] != b) {
                for (int i = size_onl; i > pos; --i) {
                    onl[i] = onl[i - 1];
                }
                onl[pos] = b;
                ++size_onl;
            }
        } 
        else if (a == 2) {
            if (pos == size_onl || onl[pos] != b) cout << 0 << '\n';
            else cout << pos + 1 << '\n';
        }
    }

    return 0;
}



// https://chatgpt.com/share/68776442-1808-8001-a705-3067846142e1