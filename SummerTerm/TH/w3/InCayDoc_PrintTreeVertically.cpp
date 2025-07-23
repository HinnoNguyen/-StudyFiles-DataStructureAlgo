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

void PrintRNL(node* root, int depth = 0) { // Right -> Root -> Left
    if (!root) return;
    PrintRNL(root->right, depth + 1);
    for (int i = 0; i < depth * 4; ++i) cout << '.';
    cout << root->data << '\n';
    PrintRNL(root->left, depth + 1);
}

void PrintNLR (node* root, int depth = 0) { // Root -> Left -> Right
    if (!root) return;
    for (int i = 0; i < depth * 4; ++i) cout << '.';
    cout << root->data << '\n';
    PrintNLR(root->left, depth + 1);
    PrintNLR(root->right, depth + 1);
}


int main () {
    node* root = NULL;
    int x;
    while (cin >> x && x != 0) InsertNode(root, x);

    PrintRNL(root);
    cout << endl;
    PrintNLR(root);

    return 0;
}


// Source
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7