#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* next;
};

int HashFunction(int key, int M) {
    return key % M;
}

void Nhap (vector<Node*>& table, int key, int M) {
    int i = HashFunction (key, M);
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = table[i];
    table[i] = newNode;
}

int TimKiem (const vector<Node*>& table, int key, int M) {
    int i = HashFunction(key, M);
    int sosanh = 0;
    Node* current = table[i];
    while (current != nullptr) {
        sosanh++;
        if (current->key == key)
            return sosanh;
        current = current->next;
    }
    return -1;
}

int main() {
    int M, N, nNguyenTo;
    double LOAD;
    cin >> M >> LOAD >> N;
    vector<Node*> table(M, nullptr);
    for (int i = 0; i < N; ++i) {
        int key;
        cin >> key;
        Nhap(table, key, M);
    }
    cin >> nNguyenTo;
    for (int i = 0; i < nNguyenTo; i++) {
        int key;
        cin >> key;
        int kq = TimKiem(table, key, M);
        if (kq != -1)
            cout << kq << endl;
        else
            cout << "KHONG" << endl;
    }
}
