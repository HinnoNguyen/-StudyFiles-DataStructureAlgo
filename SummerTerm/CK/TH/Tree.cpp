#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node* root = NULL;
    int value;
    while (cin >> value) InsertNode(root, value);
    
    return 0;
}


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

int TreeHeight(node* root) {
    if (!root) return 0;
    int leftHeight = TreeHeight(root->left);
    int rightHeight = TreeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int TreeLevel(node* root) {
    if (!root) return 0;
    int leftLevel = TreeLevel(root->left);
    int rightLevel = TreeLevel(root->right);
    return 1 + max(leftLevel, rightLevel);
}

int TreeLeafCount(node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1; 
    return TreeLeafCount(root->left) + TreeLeafCount(root->right);
}

int TreeNodeCount(node* root) {
    if (!root) return 0;
    int leftCount = TreeNodeCount(root->left);
    int rightCount = TreeNodeCount(root->right);
    return 1 + leftCount + rightCount;
}

void PrintTreeNLR(node* root) { // NLR Traversal
    if (!root) return;
    cout << root->data << " ";
    PrintTreeNLR(root->left);
    PrintTreeNLR(root->right);
}

void PrintTreeLRN(node* root) { // LRN Traversal
    if (!root) return;
    PrintTreeLRN(root->left);
    PrintTreeLRN(root->right);
    cout << root->data << " ";
}

void PrintTreeLNR(node* root) { // LNR Traversal
    if (!root) return;
    PrintTreeLNR(root->left);
    cout << root->data << " ";
    PrintTreeLNR(root->right);
}

void PrintTreeLevelOrder(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void DeleteTree(node* &root) {
    if (!root) return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = NULL;
}

void DeleteLeafNodes(node* &root) {
    if (!root) return;
    if (!root->left && !root->right) {
        delete root;
        root = NULL;
        return;
    }
    DeleteLeafNodes(root->left);
    DeleteLeafNodes(root->right);
}