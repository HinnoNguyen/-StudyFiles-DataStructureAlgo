
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
	}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {

Node *temp = root;
        if (root == NULL)
        {
            Node *ptr = new Node(data);
            return ptr;
        }
        Node *prev = nullptr;
        while (root != nullptr)
        {
            prev = root;
            if (root->data == data)
                return nullptr;
            else if (root->data < data)
                root = root->right;
            else
                root = root->left;
        }
        Node *ptr = new Node(data);
        if (data < prev->data)
            prev->left = ptr;
        else
            prev->right = ptr;
        return temp;

    }
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}

