#include <iostream>
using namespace std;

struct node {
    long long val;
    int size;
    node* left;
    node* right;

    node(long long v) : val(v), size(1), left(nullptr), right(nullptr) {}
};

int GetSize(node* node) {
    if (!node) return 0;
    return node->size;
}

void UpdateSize(node* node) {
    if (node) node->size = 1 + GetSize(node->left) + GetSize(node->right);
    
}

node* InsertNode(node* root, long long x) {
    if (!root) return new node(x);
    if (x < root->val) {
        root->left = InsertNode(root->left, x);
    } else if (x > root->val) {
        root->right = InsertNode(root->right, x);
    }
    UpdateSize(root);
    return root;
}

int FindRank(node* root, long long x) {
    if (!root) return 0;
    if (x == root->val) return GetSize(root->left) + 1;
    else if (x < root->val) return FindRank(root->left, x);
    else {
        int rightRank = FindRank(root->right, x);
        if (rightRank == 0) return 0;
        return GetSize(root->left) + 1 + rightRank;
    }
}

bool Exists(node* root, long long x) {
    if (!root) return false;
    if (x == root->val) return true;
    if (x < root->val) return Exists(root->left, x);
    else return Exists(root->right, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node* root = nullptr;
    int a;
    long long b;

    while (cin >> a && a != 0) {
        cin >> b;
        if (a == 1) {
            if (!Exists(root, b)) root = InsertNode(root, b);
        } 
        else if (a == 2) {
            int rank = FindRank(root, b);
            cout << rank << '\n';
        }
    }
    return 0;
}

// Source
// Template lay o bai tap TH tuan 2 lop .2: https://github.com/HinnoNguyen/-StudyFiles-DataStructureAlgo/blob/main/SummerTerm/TH/w3/CountLeavesNodes.cpp
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7