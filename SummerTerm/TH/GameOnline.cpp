#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<long long> online;
    int a;
    long long b;
    while (cin >> a) {
        if (a == 0) break;
        cin >> b;
        if (a == 1) { 
            online.insert(b);
        } else if (a == 2) {
            cout << (online.count(b) ? 1 : 0) << '\n';
        } else if (a == 3) {
            online.erase(b);
        }
    }
    return 0;
}