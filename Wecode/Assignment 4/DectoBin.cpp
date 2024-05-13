#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; 
    stack<int> s;
    cin >> n;
    int i = 0;
    
    do {
        s.push(n % 2);
        n = n / 2;
    } while (n > 0);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}