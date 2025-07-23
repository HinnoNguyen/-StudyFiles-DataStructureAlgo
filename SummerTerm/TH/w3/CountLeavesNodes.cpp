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
    else if (x > root->data) return InsertNode(root->right, x);
    else return false;
}

int CountLeaves (node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return CountLeaves(root->left) + CountLeaves(root->right);
}

int main () {
    node* root = NULL;
    int x;
    while (cin >> x && x != 0) InsertNode(root, x);
    cout << CountLeaves(root);
    return 0;
}


// Source
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7