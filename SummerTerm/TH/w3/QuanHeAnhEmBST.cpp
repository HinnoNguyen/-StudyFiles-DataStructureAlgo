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

