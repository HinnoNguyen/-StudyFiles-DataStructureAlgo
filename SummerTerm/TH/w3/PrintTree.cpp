// Template
#include <iostream>
using namespace std;

// Main code (Submitted Codes)
struct node {
    int data;
    node* left;
    node* right;
    int x, y;
};

node* NewNode(int x) {
    node* p = new node();
    p->data = x;
    p->left = p->right = NULL;
    p->x = p->y = 0;
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

int CountDigit(int x) {
    int c = 0;
    do {
        ++c;
        x /= 10;
    } while (x);
    return c;
}

void AssignXY(node* root, int depth) {
    if (!root) return;
    AssignXY(root->left, depth + 1);
    root->x = xCounter++;
    root->y = depth;
    AssignXY(root->right, depth + 1);
}

int main () {
    node* root = NULL;
    int x;
    while (cin >> x && x != 0) InsertNode(root, x);

    

    return 0;
}


// Source
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7