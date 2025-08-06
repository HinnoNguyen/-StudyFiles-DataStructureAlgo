#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_M = 1000;
const int EMPTY = 1000000000;

int table[MAX_M];

void Insert(int table[], int k, int m, int a, int b) {
    for (int i = 0; i < m; i++) {
        int h = ((k % m + m) % m + a * i + b * i * i) % m;
        if (table[h] == EMPTY) {
            table[h] = k;
            return;
        }
    }
}

void Print(int table[], int m) {
    for (int i = 0; i < m; ++i) {
        if (i > 0) cout << ", ";
        if (table[i] == EMPTY) cout << "None";
        else cout << table[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line == "0") break; 

        int m, a, b;
        stringstream ss(line);
        ss >> m >> a >> b;

        for (int i = 0; i < m; ++i) table[i] = EMPTY;

        getline(cin, line);
        stringstream nums(line);
        int k;
        while (nums >> k) Insert(table, k, m, a, b);

        Print(table, m);
    }

    return 0;
}
