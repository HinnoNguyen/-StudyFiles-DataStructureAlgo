#include <iostream>
#include <stack>
#include <vector>
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

void InsertNode (Tree& T, int x) {
	Node* temp = new Node(x);
	if (T.root == NULL) T.root = temp;
	else {
		Node* cur = T.root;
		Node* pre = NULL;
		while (cur != NULL) {
			pre = cur;
			if (cur->data > x) cur = cur->left;
			else if (cur->data < x) cur = cur->right;
			else break;
		}
		if (pre->data > x) pre->left = temp;
		else if (pre->data < x) pre->right = temp;
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

//********************LONGEST PATH********************
void PrintPathToLeaf(Node* root) {
	static vector<int> path;
	if (root == NULL) return;
	path.push_back(root->data);

    if (root->left == NULL && root->right == NULL) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
	else {
		PrintPathToLeaf(root->left);
        PrintPathToLeaf(root->right);
    }
    path.pop_back();
}

//********************SHORTEST PATH********************
void PrintShortestPathToLeaf(Node* root) {
	static vector<int> path;
	if (root == NULL) return;
	path.push_back(root->data);

    if (root->left == NULL && root->right == NULL) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
	else {
		if (TreeHeight(root->left) < TreeHeight(root->right))
            PrintShortestPathToLeaf(root->left);
        else
            PrintShortestPathToLeaf(root->right);
    
    path.pop_back();
	}
}

//********************COUNT NODES WHICH ARE LV1********************
int CountNodesAtLevel1(Node* root) {
    if (root == nullptr) return 0;

    int count = 0;
    if (root->left != nullptr) count++;
    if (root->right != nullptr) count++;

    return count;
}

//********************COUNT NODES WHICH ARE LV2********************
int CountNodesAtLevel2(Node* root) {
    if (root == nullptr) return 0;

    int count = 0;
    if (root->left != nullptr) {
        count++; // Left child exists
        count += CountNodesAtLevel1(root->left); // Count its children at level 1
    }
    if (root->right != nullptr) {
        count++; // Right child exists
        count += CountNodesAtLevel1(root->right); // Count its children at level 1
    }

    return count;
}

//*******************DELETE*******************
Node* FindMin (Node* T) {
	while (T->left != NULL)
		T = T->left;
		return T;
}

Node* DeleteNode(Node* T, int x) {
	if (T == NULL) return T;
	if (x < T->data)
		T->left = DeleteNode(T->left, x);
	else if (x > T->data)
		T->right = DeleteNode(T->right, x);
	else {
		if (T->left == NULL) {
			Node*temp = T->right;
			delete T;
			return temp;
		}
		else if (T->right == NULL) {
			Node* temp = T->left;
			delete T;
			return temp;
		}
		Node* temp = FindMin (T->right);
		T->data = temp->data;
		T->right = DeleteNode(T->right, temp->data);
	}
	return T;
}

//********************************************

int main () {
	int n, x;
	cin >> n;
	Tree T;
	CreateTree (T);
	for (int i = 0; i < n; i++) {
		cin >> x;
		InsertNode(T, x);
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
	cout << "\nLeaf nodes: " << CountLeafNodes(T.root) << endl;

	//********************TREE HEIGHTS********************
	cout << "Tree level: " << TreeHeight(T.root) << endl;

	//********************LONGEST PATH********************
	cout << "\nLongest path from root to leaf:\n";
    PrintPathToLeaf(T.root);

	//********************SHORTEST PATH********************
	cout << "\nShortest path from root to leaf:\n";
    PrintShortestPathToLeaf(T.root);

	//********************COUNT NODES WHICH ARE LV1********************
	int nodesAtLevel1 = CountNodesAtLevel1(T.root);
    cout << "Number of nodes at level 1: " << nodesAtLevel1 << endl;

	//********************COUNT NODES WHICH ARE LV2********************
	int nodesAtLevel2 = CountNodesAtLevel2(T.root);
    cout << "Number of nodes at level 2: " << nodesAtLevel2 << endl;

	//*******************DELETE*******************
	cout << "\nDelete node: ";
	int del;
	cin >> del;
	T.root = DeleteNode (T.root, del);
	cout << "After delete " << del << ": ";

	PrintNLR_Recursion (T.root);
}