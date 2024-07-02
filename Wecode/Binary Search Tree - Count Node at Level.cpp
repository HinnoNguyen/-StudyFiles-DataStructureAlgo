/*
Given a binary search tree, write a function to count the number of nodes whose level is equal to the given input.

Input:

First line is the number of nodes in the tree (1 ≤ n ≤ 100)
Second line is the value of the nodes (1 ≤ A[i] ≤ 1000)
Third line is the value of the node whose level is to be counted (0 ≤ n ≤ 100)
Output: the number of nodes whose level is equal to the given input

*/

#include <iostream>
using namespace std;

struct Tree { 
    int data;
    Tree *left;
    Tree *right;
    Tree (int x) : data(x), left (NULL), right (NULL) {};
};

Tree *Insert (Tree *root, int data) {
    if (!root) {
        return new Tree(data);
    }
    if (data < root->data) {
        root->left = Insert (root->left , data);
    }
    else {
        root->right = Insert (root->right , data);
    }
    return root;
}

int CountNodeLevel (Tree* root, int Target, int CurrentLevel = 0) {
    if (!root) {
        return 0;
    }
    if (CurrentLevel == Target) {
        return 1;
    }
    return CountNodeLevel (root->left, Target, CurrentLevel + 1) + CountNodeLevel (root->right, Target, CurrentLevel + 1);
}

int main () {
    int n;
    cin >> n;

    Tree* root = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = Insert (root, data);
    }

    int Target;
    cin >> Target;

    cout << CountNodeLevel(root, Target);
    return 0;
}