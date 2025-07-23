#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    long, 
    null_type,
    less<long>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_set onl;
    int a;
    long b;

    while (cin >> a && a != 0) {
        cin >> b;
        if (a == 1) {
            onl.insert(b);  
        } else if (a == 2) {
            if (onl.find(b) == onl.end()) cout << 0 << '\n';
            else cout << onl.order_of_key(b) + 1 << '\n'; 
        }
    }

    return 0;
}

// https://chatgpt.com/share/687a391e-48d8-8001-9a29-6cf6a4d9ff77