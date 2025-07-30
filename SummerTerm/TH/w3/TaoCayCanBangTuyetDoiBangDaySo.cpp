#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* BuildTree(vector<int> &a, int l, int r) {
    if (l > r)
        return nullptr;
    int mid = (l + r) / 2;
    TreeNode *root = new TreeNode(a[mid]);
    root->left = BuildTree(a, l, mid - 1);
    root->right = BuildTree(a, mid + 1, r);
    return root;
}

void PostOrderBuffered(TreeNode *root, ostringstream &out) {
    if (!root) return;
    PostOrderBuffered(root->left, out);
    PostOrderBuffered(root->right, out);
    out << root->val << '\n';
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> a;
    int x;
    while (cin >> x) a.push_back(x);

    sort(a.begin(), a.end());  // Đảm bảo mảng đã sắp xếp

    TreeNode *root = BuildTree(a, 0, a.size() - 1);
    ostringstream out;
    PostOrderBuffered(root, out);
    cout << out.str();
    return 0;
}


// Source
// https://neetcode.io/solutions/construct-binary-tree-from-preorder-and-inorder-traversal
// https://copilot.microsoft.com/shares/mdn55cG9HraCDHq6EU1eZ
// https://chatgpt.com/share/68898a23-83ac-8001-a6fa-577cf6626cd5