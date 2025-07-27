// Template
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)

// Main code (Submitted Codes)
struct node {
    char key[105];
    node* left;
    node* right;
};

int cmp(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return a[i] - b[i];
        i++;
    }
    return a[i] - b[i];
}

void insert(node*& root, const char* key) {
    if (root == 0) {
        root = new node;
        int i = 0;
        while (key[i]) {
            root->key[i] = key[i];
            i++;
        }
        root->key[i] = '\0';
        root->left = root->right = 0;
        return;
    }
    int c = cmp(key, root->key);
    if (c < 0) insert(root->left, key);
    else if (c > 0) insert(root->right, key);
}

int search(node* root, const char* key) {
    if (root == 0) return 0;
    int c = cmp(key, root->key);
    if (c == 0) return 1;
    if (c < 0) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    cin.tie(nullptr);

    node* root = 0;
    int command;
    char word[105];
    while (scanf("%d", &command) && command != 0) {
        scanf("%s", word);
        if (command == 1) insert(root, word);
        else if (command == 2) printf("%d\n", search(root, word));
    }
    return 0;
}


// Source
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7
// https://chatgpt.com/share/6885e06e-79d0-8001-bd66-a6d9aad8d1fd