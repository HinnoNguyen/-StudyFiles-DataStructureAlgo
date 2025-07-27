// Template
#include <iostream>
using namespace std;

// Main code (Submitted Codes)
struct node {
    int val;
    node* left;
    node* right;

    node(int v): val(v), left(NULL), right(NULL) {}
};

node* insert(node* root, int x) {
    if (!root) return new node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else if (x > root->val) root->right = insert(root->right, x);
    return root;
}

void find_lower(node* root, int x, int& ans) {
    if (!root) return;
    if (root->val < x) {
        ans = root->val;
        find_lower(root->right, x, ans);
    } else {
        find_lower(root->left, x, ans);
    }
}

void find_upper(node* root, int x, int& ans) {
    if (!root) return;
    if (root->val > x) {
        ans = root->val;
        find_upper(root->left, x, ans);
    } 
    else 
        find_upper(root->right, x, ans);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node* root = nullptr;
    int type, x;

    while (cin >> type && type != 0) {
        cin >> x;
        if (type == 1) root = insert(root, x);
        else if (type == 2) {
            int ans = -1;
            find_lower(root, x, ans);
            if (ans == -1) cout << "NULL\n";
            else cout << ans << '\n';
        } else if (type == 3) {
            int ans = -1;
            find_upper(root, x, ans);
            if (ans == -1) cout << "NULL\n";
            else cout << ans << '\n';
        }
    }

    return 0;
}


// Source
// https://chatgpt.com/share/6885e66a-d8e4-8001-8763-2f55f1357c8d