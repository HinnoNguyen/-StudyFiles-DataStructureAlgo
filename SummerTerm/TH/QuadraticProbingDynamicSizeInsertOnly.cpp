#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_M = 1000;
const int EMPTY = 1000000000;

int hash_table[MAX_M];

void init_table(int m) {
    for (int i = 0; i < m; ++i)
        hash_table[i] = EMPTY;
}

bool exists(int x, int m, int a, int b) {
    for (int i = 0; i < m; ++i) {
        int h = ((x % m + m) % m + a * i + b * i * i) % m;
        if (hash_table[h] == x) return true; 
        if (hash_table[h] == EMPTY) return false; 
    }
    return false;
}

void insert(int x, int m, int a, int b, int &count_inserted) {
    if (count_inserted >= m) return; 
    if (exists(x, m, a, b)) return; 

    for (int i = 0; i < m; ++i) {
        int h = ((x % m + m) % m + a * i + b * i * i) % m;
        if (hash_table[h] == EMPTY) {
            hash_table[h] = x;
            count_inserted++;
            break;
        }
    }
}

int main() {
    int m, a, b;

    while (cin >> m && m != 0) {
        cin >> a >> b;
        cin.ignore(); 

        string line;
        getline(cin, line);
        istringstream iss(line);

        int x;
        int count_inserted = 0;
        init_table(m);

        while (iss >> x)
            insert(x, m, a, b, count_inserted);

        for (int i = 0; i < m; ++i) {
            if (hash_table[i] == EMPTY) cout << "None";
            else cout << hash_table[i];
            if (i != m - 1) cout << ", ";
        }
        cout << "\n";
    }

    return 0;
}