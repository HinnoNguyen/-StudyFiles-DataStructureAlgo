// Template
#include <iostream>
using namespace std;

// Main code (Submitted Codes)
struct node {
    int data;
    node* left;
    node* right;
};

const int MAXN = 500000;
node pool[MAXN];
int pool_index = 0;

node* NewNode(int x) {
    node* p = &pool[pool_index++];
    p->data = x;
    p->left = p->right = nullptr;
    return p;
}

bool InsertNode(node*& root, int x) {
    if (!root) {
        root = NewNode(x);
        return true;
    }
    if (x < root->data) return InsertNode(root->left, x);
    else if (x > root->data) return InsertNode(root->right, x);
    else return false;
}

node* q[MAXN];
int front = 0, back = 0;

void Enqueue(node* n) {
    q[back++] = n;
}

node* Dequeue() {
    return q[front++];
}

bool isEmpty() {
    return front == back;
}

void BFS(node* root) {
    if (!root) return;
    Enqueue(root);
    while (!isEmpty()) {
        node* cur = Dequeue();
        cout << cur->data << ' ';
        if (cur->left) Enqueue(cur->left);
        if (cur->right) Enqueue(cur->right);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node* root = nullptr;
    int x;
    while (cin >> x && x != 0) InsertNode(root, x);

    BFS(root);
    return 0;
}

// Source
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7
// https://chatgpt.com/share/68860a27-0a08-8001-9b51-aef89558fbf1