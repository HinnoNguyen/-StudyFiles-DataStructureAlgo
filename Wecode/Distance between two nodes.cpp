
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

Node *newNode(int v)
{
    Node *newNode = new Node;
    newNode->value = v;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node *root, Node *newNode)
{
    if (!root)
        return;

    if (newNode->value < root->value)
    {
        if (!root->left)
        {
            root->left = newNode;
            return;
        }
        insertNode(root->left, newNode);
        return;
    }

    if (!root->right)
    {
        root->right = newNode;
        return;
    }
    insertNode(root->right, newNode);
}

Node* findLCA(Node* root, int a, int b) {
    if (!root || root->value == a || root->value == b)
        return root;

    Node* leftLCA = findLCA(root->left, a, b);
    Node* rightLCA = findLCA(root->right, a, b);

    if (leftLCA && rightLCA)
        return root;

    if (leftLCA != NULL)
        return leftLCA;
    else
        return rightLCA;
}

int findDistance(Node* root, int target, int level) {
    if (!root)
        return -1;

    if (root->value == target)
        return level;

    int leftDistance = findDistance(root->left, target, level + 1);
    if (leftDistance != -1)
        return leftDistance;

    return findDistance(root->right, target, level + 1);
}

int distanceBetweenNodes(Node* tree, int a, int b) {
    Node* lca = findLCA(tree, a, b);
    int distA = findDistance(lca, a, 0);
    int distB = findDistance(lca, b, 0);

    return distA + distB;
}


int main()
{
    Node *tree = NULL;

    int n;
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (!tree)
        {
            tree = newNode(val);
            continue;
        }

        insertNode(tree, newNode(val));
    }

    int a, b;
    cin >> a >> b;

    cout << distanceBetweenNodes(tree, a, b) << endl;

    return 0;
}
