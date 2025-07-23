// Template
#include <iostream>
using namespace std;

// Main code (Submitted Codes)
const int MAXSIZE = 900009;
long long HashTable[MAXSIZE];

long long HashKey(int x, int y) {
    return 1LL * x * 10000019 + y;
}

bool InsertHashKey(long long key) {
    int i = key % MAXSIZE;
    int step = 1 + (key % (MAXSIZE - 1));

    while (HashTable[i] != 0) {
        if (HashTable[i] == key) return false;
        i = (i + step) % MAXSIZE;
    }

    HashTable[i] = key;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, dem = 0;

    while (cin >> x) {
        if (x == 0) break;
        cin >> y;

        long long key = HashKey(x, y);
        if (InsertHashKey(key)) dem++;
    }

    cout << dem << '\n';
    return 0;
}

// Source:
// https://chatgpt.com/share/688044b0-99b8-8000-822f-f834f074b470