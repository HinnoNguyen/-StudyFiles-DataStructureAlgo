// Header
#include <iostream>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isBrother(Tree, int, int);

void run(int q, Tree T){

// Submited Area **************************************************
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << u << " va " << v << " ";
        if (isBrother(T, u, v)) cout << "la anh em\n";
        else cout << "khong phai la anh em\n";
    }
}

void Insert(Tree &T, int x) {
    TNode* newNode = CreateTNode(x);
    if (T.root == NULL) {
        T.root = newNode;
        return;
    }

    TNode* cur = T.root;
    TNode* prev = NULL;

    while (cur != NULL) {
        prev = cur;
        if (x < cur->key) cur = cur->pLeft;
        else cur = cur->pRight;
    }

    if (x < prev->key) prev->pLeft = newNode;
    else prev->pRight = newNode;
}

bool isBrother(Tree T, int a, int b) {
    if (a == b) return false;

    TNode* cur = T.root;

    while (cur != NULL) {
        bool leftHasA = (cur->pLeft != NULL && cur->pLeft->key == a);
        bool rightHasB = (cur->pRight != NULL && cur->pRight->key == b);

        bool leftHasB = (cur->pLeft != NULL && cur->pLeft->key == b);
        bool rightHasA = (cur->pRight != NULL && cur->pRight->key == a);

        if ((leftHasA && rightHasB) || (leftHasB && rightHasA)) return true;
        
        if (a < cur->key && b < cur->key) cur = cur->pLeft;
        else if (a > cur->key && b > cur->key) cur = cur->pRight;
        else cur = (cur->pLeft != NULL) ? cur->pLeft : cur->pRight;
    }
    return false;

// Source: https://chatgpt.com/share/68899082-7cfc-8001-ae6a-40c02e90e7cb

// Fooster
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);
    
    return 0;
}

