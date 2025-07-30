// Template
// Header
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

void add(Node* &root, int x){
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
    if (root == NULL){
        root = new Node;
        root->val = x;
        root->left = root->right= NULL;
    } else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}

// Fooster
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node *root = NULL;

    int x;
    while (cin >> x){
        add(root, x);
    }
    
    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}


// Main code (Submitted Codes)
int GetHeight(Node* root) {
    if (root == NULL) return 0;
    int l = GetHeight(root->left);
    int r = GetHeight(root->right);
    return 1 + max(l, r);
}

int CountUnbalance(Node* root, int &count) {
    if (root == NULL) return 0;
    int l = CountUnbalance(root->left, count);
    int r = CountUnbalance(root->right, count);
    if (abs(l - r) >= 2) count++;
    return 1 + max(l, r);
}

int unbalance(Node* root) {
    int count = 0;
    CountUnbalance(root, count);
    return count;
}

//https://neetcode.io/solutions/balanced-binary-tree
//https://copilot.microsoft.com/shares/SBg2HNBBm57EZoQpMen7K