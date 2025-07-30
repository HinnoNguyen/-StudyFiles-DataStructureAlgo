#include <iostream>
#include <sstream>
using namespace std;

struct node {
    long long data;
    long long count;
    node* left;
    node* right;
};

node* NewNode(long long x) {
    node* p = new node();
    p->data = x;
    p->count = 1;
    p->left = p->right = NULL;
    return p;
}

bool InsertNode (node* &root, long long x) {
    if (!root) {
        root = NewNode(x);
        return true;
    }
    if (x < root->data) return InsertNode(root->left, x);
    else if (x > root->data) return InsertNode(root->right, x);
    else {
        root->count++;
        return false;
    }
}

void PrintHistogram(node* root, ostringstream &out) {
    if (root == NULL) return;
    PrintHistogram(root->right, out);
    out << root->data << " " << root->count << endl;
    PrintHistogram(root->left, out);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    node* root = NULL;
    long long x;
    while (cin >> x && x != 0) InsertNode(root, x);
    ostringstream out;
    PrintHistogram(root, out);
    cout << out.str();
    return 0;
}

// Template: https://github.com/HinnoNguyen/-StudyFiles-DataStructureAlgo/blob/main/SummerTerm/TH/w3/CountLeavesNodes.cpp