#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node (int x) {
		data = x;
		left = right = NULL;
	}
};

struct Tree {
	Node* root;
};

void CreateTree (Tree& T) {
	T.root = NULL;
}

Node* InsertNode (Tree& T, int x) {
	Node* InsertNode = new Node(x);
	if (T.root == NULL) T.root = InsertNode;
	else {
		Node* cur = T.root;
		Node* pre = NULL;
		while (cur != NULL) {
			pre = cur;
			if (cur->data > x) cur = cur->left;
			else if (cur->data < x) cur = cur->right;
			else break;
		}
		if (pre->data > x) pre->left = InsertNode;
		else if (pre->data < x) pre->right = InsertNode;
		else return;
	}
}

//********************PRINT TRAVESAL********************

// RECURSION
void PrintNLR_Recursion (Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		PrintNLR_Recursion (root->left);
		PrintNLR_Recursion (root->right);
	}
}

// STACK
void PrintNLR_Stack (Node* root) {
	stack<Node*> st;
	st.push(root);

	while (!st.empty()) {
		Node* top = st.top();
		st.pop();
		cout << top->data << " ";
		if (top -> right == NULL) st.push(top->right);
		if (top -> left == NULL) st.push(top->left);
	}
}

//********************COUNT LEAF NODES********************
bool IsLeafNode (Node* T) {
	return (T->left == NULL && T->right == NULL);
}

int CountLeafNodes (Node*T) {
	if (T == NULL) return 0;
	if (IsLeafNode(T)) return 1;
	else return CountLeafNodes (T->left) + CountLeafNodes (T->right);
}

//********************TREE HEIGHTS********************
// bool IsLeafNode (Node* T) {
// return (T->left == NULL && T->right == NULL);
// }

int TreeHeight (Node* T) {
	if (T != NULL) {
		return 1 + max(TreeHeight(T->left), TreeHeight(T->right));
	}
	return -1;
}


//*******************DELETE*******************

Node* DeleteNode(Node* T, int x) {
	if (T != NULL) {
		if (T->data == x) {
			DeleteNode (T->left , x);
			DeleteNode (T->right, x);
			T = NULL;
		}
		else if (T->data > x) T->left = DeleteNode (T->left, x);
		else T->right = DeleteNode (T->right, x);
		return T;
	}
}

//********************************************

int main () {
	int n, x;
	cin >> n;
	Tree T;
	CreateTree (T);
	for (int i = 0; i < n; i++) {
		cin >> x;
		T.root = InsertNode(T, x);
	}

	//********************PRINT TRAVESAL********************
	// RECURSION
	cout << "\nRecursion: ";
	cout << "\nNLR: ";
	PrintNLR_Recursion (T.root);

	//STACK
	cout << "\n\nStack: ";
    cout << "\nNLR: ";
	PrintNLR_Stack (T.root);

	//********************COUNT LEAF NODES********************
	cout << "Leaf nodes: " << CountLeafNodes(T.root) << endl;


	//********************TREE HEIGHTS********************
	cout << "Tree level: " << TreeHeight(T.root) << endl;

	//*******************DELETE*******************
	int del;
	cin >> del;
	T.root = DeleteNode (T.root, del);
	cout << "After delete " << del << ": ";
	PrintNLR_Recursion (T.root);

    return 0;
}