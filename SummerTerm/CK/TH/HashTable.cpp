#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000
const int TableSize = 10000;

int main() {
    HASHTABLE H;
    int CurrentSize;
    int n, m;
    cin >> n >> m;
    CreateHash(H, CurrentSize, n);

    return 0;
}

struct NODE {
    string x;
    string y;
};

typedef NODE* HASHTABLE[MAXTABLESIZE];

unsigned int HF(const string& key) {
    unsigned int hashVal = 0;

    for (char ch : key)
        hashVal = 37 * hashVal + ch;

    return hashVal % TableSize;
}

int HF_LinearProbing(string key, int i) {
    return (HF(key) + i) % TableSize;
}

int isFull(HASHTABLE H, int CurrentSize) {
    if (CurrentSize == TableSize - 1)
        return 1;
    return 0;
}

void CreateHash(HASHTABLE& H, int& CurrentSize, int n) {
    CurrentSize = 0;
    for (int i = 0; i < TableSize; i++)
        H[i] = NULL;
    for (int i = 0; i < n; i++) {
        if (isFull(H, CurrentSize) == 1)
            return;
        NODE* p = new NODE;
        cin >> p->x;
        cin >> p->y;
        int b = HF(p->x);
        int j = 0;
        while (b < TableSize && H[b] != NULL && H[b]->x != p->x)
            b = HF_LinearProbing(p->x, ++j);
        if (H[b] == NULL) {
            H[b] = p;
            CurrentSize++;
            continue;
        }
        H[b]->y = p->y;
    }
}

int SearchHash(HASHTABLE H, string key) {
    int i = 0;
    int b = HF(key);
    while (H[b] != NULL && H[b]->x != key) {
        b = HF_LinearProbing(key, ++i);
    }
    if (H[b] == NULL)
        return -1;
    return b;
}

void DeleteHash(HASHTABLE& H, string key) {
    int b = SearchHash(H, key);
    if (b == -1) return;
    delete H[b];
    H[b] = NULL;
}

void PrintHash(HASHTABLE H) {
    for (int i = 0; i < TableSize; i++) {
        if (H[i] != NULL) {
            cout << "Index " << i << ": " << H[i]->x << ", " << H[i]->y << endl;
        }
    }
}