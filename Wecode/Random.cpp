#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Hàm tạo một nút mới
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Hàm chèn một nút mới vào cây
Node* insert(Node* node, int data) {
    if (node == NULL) 
        return newNode(data);
    if (data < node->data) 
        node->left = insert(node->left, data);
    else 
        if (data > node->data) 
            node->right = insert(node->right, data);
    return node;
}

// Hàm nhập cây
void inputTree(Node*& root) {
    int x;
    while (cin >> x) {
        root = insert(root, x);
    }
}

// Hàm duyệt cây theo thứ tự LNR (Left-Node-Right)
void LNR(Node* root) {
    if (root != NULL) {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

int countNodes(Node* node) {
    if (node == NULL)
        return 0;
    else
        return(countNodes(node->left) + 1 + countNodes(node->right));
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đếm số chẵn, số lẻ, số âm, số dương và số nguyên tố
void countNumbers(Node* node, int& even, int& odd, int& negative, int& positive, int& prime) {
    if (node != NULL) {
        if (node->data % 2 == 0) 
            even++;
        else 
            odd++;
        if (node->data < 0) 
            negative++;
        else if 
            (node->data > 0) positive++;
        if (isPrime(node->data)) 
            prime++;
        countNumbers(node->left, even, odd, negative, positive, prime);
        countNumbers(node->right, even, odd, negative, positive, prime);
    }
}

// Hàm tính chiều cao của cây
int height(Node* node) {
    if (node == NULL) return 0;
    else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        if (lHeight > rHeight) return(lHeight + 1);
        else return(rHeight + 1);
    }
}

// Hàm liệt kê các số nguyên tố trong cây
void listPrime(Node* node) {
    if (node != NULL) {
        if (isPrime(node->data)) 
            cout << node->data << " ";
        listPrime(node->left);
        listPrime(node->right);
    }
}

int main()
{
	Node* T = NULL;
	inputTree(T);
    cout<<"LNR: "; 
    LNR(T);
     cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<height(T)<<endl;

    int count_even = 0, count_odd =0, count_positive = 0, count_negative = 0, count_prime = 0;
    countNumbers(T, count_even, count_odd, count_negative, count_positive, count_prime);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<count_positive<<endl;
    cout<<"Number of negative nodes: "<<count_negative<<endl;

    cout<<"Number of prime nodes: "<<count_prime<<endl;
    cout<<"Prime numbers: "; listPrime(T);

	return 0;
}
