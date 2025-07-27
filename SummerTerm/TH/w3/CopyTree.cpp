// Template
// Header
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

// Fooster
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node* root = NULL, *r2=NULL;

    while(true){
        int x; cin >> x;
        if (x == 0) break;
        /* Hàm add thêm số nguyên x vào cây nhị phân theo nguyên tắc riêng
        * Hàm này đã được viết đầy đủ
        * sinh viên không cần viết hàm này
        */ 
        add(root, x); 
    }

    copy(root, r2); //Cần phải viết hàm này

    /* Hàm check kiểm tra lại 02 cây sau khi copy
    * Hàm này đã được viết đầy đủ
    * sinh viên không cần viết hàm này
    **/
    check(root, r2);

    return 0;
}

// Main code (Submitted Codes)
const int MAX = 1000000;
Node NodePool[MAX];
int NodeCount = 0;

Node* NewNode(int val) {
    NodePool[NodeCount] = {val, NULL, NULL};
    return &NodePool[NodeCount++];
}

void copy(Node* root, Node*& r2) {
    if (!root) {
        r2 = NULL;
        return;
    }
    r2 = NewNode(root->val);
    copy(root->left, r2->left);
    copy(root->right, r2->right);
}


// Source
// https://chatgpt.com/share/6885f6c1-62a0-8001-a251-ac5c75c91af5