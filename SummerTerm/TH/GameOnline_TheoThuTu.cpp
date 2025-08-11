#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<long long, int> pos; 
    vector<long long> order;       

    int a;
    long long b;
    while (cin >> a) {
        if (a == 0) break;
        cin >> b;

        if (a == 1) {
            pos[b] = order.size();
            order.push_back(b);
        } 
        else if (a == 2) {
            if (!pos.count(b)) {
                cout << "N\n";
            } else {
                int idx = pos[b];
                cout << b;
                if (idx - 1 >= 0) cout << " " << order[idx - 1];
                if (idx - 2 >= 0) cout << " " << order[idx - 2];
                cout << "\n";
            }
        }
    }
    return 0;
}
