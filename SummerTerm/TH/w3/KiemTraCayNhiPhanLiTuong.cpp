// Template
#include <iostream>
using namespace std;

// Main code (Submitted Codes)
struct node {
    int data;
    struct node* left;
    struct node* right;
};

node* NewNode(int x) {
    node* p = new node();
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

bool InsertNode (node* &root, int x) {
    if (!root) {
        root = NewNode(x);
        return true;
    }
    if (x < root->data) return InsertNode(root->left, x);
    else return InsertNode(root->right, x);
}

int GetHeight(node* root) {
    if (root == NULL) return 0;
    return max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

bool IsPerfectBinaryTree(node* root, int h, int level) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return (h == level + 1);
    if (root->left == NULL || root->right == NULL) return false;
    return IsPerfectBinaryTree(root->left, h, level + 1) && IsPerfectBinaryTree(root->right, h, level + 1);
}

bool CheckPerfectBinaryTree(node* root) {
    int h = GetHeight(root);
    return IsPerfectBinaryTree(root, h, 0);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    node* root = NULL;
    int x, n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        InsertNode(root, x);
    }

    cout << (CheckPerfectBinaryTree(root) ? "YES" : "NO");
    return 0;
}

// Source - Tham khao   https://tek4.vn/khoa-hoc/cau-truc-du-lieu-va-thuat-toan/cay-nhi-phan-va-cac-kieu-cay-nhi-phan
// Template             https://github.com/HinnoNguyen/-StudyFiles-DataStructureAlgo/blob/main/SummerTerm/TH/w3/CountLeavesNodes.cpp