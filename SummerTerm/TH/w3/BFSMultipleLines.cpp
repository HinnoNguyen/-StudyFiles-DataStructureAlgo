// Template
#include <iostream>
using namespace std;

// Main code (Submitted Codes)
const int MAX_NODE = 100005;
const int MAX_LEVEL = 10000;
const int MAX_PER_LEVEL = 1024;

struct node {
    int data;
    node* left;
    node* right;
};

node pool[MAX_NODE];
int pool_size = 0;

node* NewNode(int x) {
    if (pool_size >= MAX_NODE) return NULL;
    pool[pool_size].data = x;
    pool[pool_size].left = pool[pool_size].right = NULL;
    return &pool[pool_size++];
}

bool InsertNode(node*& root, int x) {
    if (!root) {
        root = NewNode(x);
        return root != NULL;
    }
    if (x < root->data) return InsertNode(root->left, x);
    if (x > root->data) return InsertNode(root->right, x);
    return false; // bỏ qua nếu trùng
}

void QuickSort(int a[], int l, int r) {
    if (l >= r) return;
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            i++; j--;
        }
    }
    QuickSort(a, l, j);
    QuickSort(a, i, r);
}

void BFS(node* root) {
    if (!root) return;

    node* queue[MAX_NODE];
    int level[MAX_NODE];
    int front = 0, rear = 0;

    int result[MAX_LEVEL][MAX_PER_LEVEL];
    int count[MAX_LEVEL] = {0};

    queue[rear] = root;
    level[rear++] = 0;

    while (front < rear) {
        node* cur = queue[front];
        int l = level[front];
        front++;

        result[l][count[l]++] = cur->data;

        if (cur->left) {
            queue[rear] = cur->left;
            level[rear++] = l + 1;
        }
        if (cur->right) {
            queue[rear] = cur->right;
            level[rear++] = l + 1;
        }
    }

    for (int i = 0; i < MAX_LEVEL; ++i) {
        if (count[i] == 0) break;
        QuickSort(result[i], 0, count[i] - 1);
        for (int j = 0; j < count[i]; ++j) {
            if (j > 0) cout << ' ';
            cout << result[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    node* root = NULL;
    int x;
    while (cin >> x && x != 0) {
        InsertNode(root, x);
    }

    BFS(root);
    return 0;
}

// Source
// https://handbook.bhtcnpm.com/docs/dsa/phan2/chuong7