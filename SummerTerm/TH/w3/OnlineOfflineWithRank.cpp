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
    if (x < root->val) root->left = InsertNode(root->left, x);
    else if (x > root->val) root->right = InsertNode(root->right, x);
    
    UpdateSize(root);
    return root;
}

node* FindMin(node* root) {
    while (root && root->left) root = root->left;
    return root;
}

node* DeleteNode (node* root, long long x) {
    if (!root) return nullptr;
    
    if (x < root->val) root->left = DeleteNode(root->left, x);
    else if (x > root->val) root->right = DeleteNode(root->right, x);
    else {
        if (!root->left) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        
        node* temp = FindMin(root->right);
        root->val = temp->val; 
        root->right = DeleteNode(root->right, temp->val); 
    }
    
    UpdateSize(root);
    return root;
}

bool Exists(node* root, long long x) {
    if (!root) return false;
    if (x == root->val) return true;
    if (x < root->val) return Exists(root->left, x);
    else return Exists(root->right, x);
}

int FindRank (node* root, long long x) {
    if (!root) return 0;
    if (x < root->val) return FindRank(root->left, x);
    else if (x > root->val) return GetSize(root->left) + 1 + FindRank(root->right, x);
    else return GetSize(root->left);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node* root = nullptr;
    int x;
    long long b;

    while (cin >> x && x != 0) {
        cin >> b;
        if (x == 1) {
            if (!Exists(root, b)) root = InsertNode(root, b);
        } 
        else if (x == 2) {
            if (Exists(root, b)) cout << FindRank(root, b) + 1 << endl;
            else cout << "0\n";
        } 
        else if (x == 3) {
            if (Exists(root, b)) root = DeleteNode(root, b);
        }
    }
    return 0;
}

// Source
// Template mau: https://github.com/HinnoNguyen/-StudyFiles-DataStructureAlgo/blob/main/SummerTerm/TH/w3/OnlineSortingLarge.cpp
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7