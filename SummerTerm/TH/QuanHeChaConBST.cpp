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
bool isFather(Tree, int, int);

void run(int q, Tree T){

// Submited Area **************************************************
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << u << " va " << v << " ";
        if (isFather(T, u, v)) cout << "la cha con\n";
        else cout << "khong phai la cha con\n";
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


bool isFather(Tree T, int u, int v) {
    TNode* cur = T.root;
    while (cur != NULL) {
        if (cur->key == u) {
            if (cur->pLeft != NULL && cur->pLeft->key == v) return true;
            if (cur->pRight != NULL && cur->pRight->key == v) return true;
            return false;
        }
        if (u < cur->key) cur = cur->pLeft;
        else cur = cur->pRight;
    }
    return false; 



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


