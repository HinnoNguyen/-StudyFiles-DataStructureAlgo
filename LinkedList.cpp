#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Create (int x) {
    Node* temp = new Node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

void Print (Node* L) {
    Node *p = L;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

Node* AddElement (Node* p, int x) {
    Node* temp = Create(x);
    p->next = temp;
    return temp;
}

// Hàm tìm phần tử giữa và chia danh sách
Node* findMiddle(Node* head) {
    if (head == nullptr) return nullptr;
    Node *slow = head, *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Hàm gộp hai danh sách đã sắp xếp
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// Hàm Merge Sort cho danh sách liên kết
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* middle = findMiddle(head);
    Node* nextToMiddle = middle->next;
    middle->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);

    return merge(left, right);
}


//********************ADD********************

Node* AddHead (Node* L, int x) {
    Node *temp  = new Node;
    temp->data = x;
    temp->next = L;
    L = temp;
    return L;
}

Node* AddTail (Node *L, int x) {
    Node* p = L;
    while (p->next != NULL)
        p = p->next;
    Node *temp  = new Node;
    temp->data = x;
    temp->next = NULL;
    p->next = temp;
    return L;
}

Node* AddAt (Node *L, int k, int x) {
    Node* p = L;
    for (int i = 0; i < k-1; i++)
        p = p->next;
    Node *temp = new Node;
    temp-> data = x;
    temp-> next = p->next;
    p->next = temp;
    return L;
}

//*******************DELETE*******************

Node* DeleteHead (Node* L, int x) {
	Node* p = L;
	p = p->next;
	delete(L);
	return p;
}

Node* DeleteTail (Node* L, int x) {
	Node* p = L;
	while (p->next->next != NULL)
		p = p->next;
	delete (p->next);
	p->next = NULL;
	return L;
}

Node* DeleteAt (Node* L, int del, int x) {
	Node* p = L;
	for (int i = 0; i < del - 1; i++)
		p = p->next;
	Node* temp = p->next;
	p->next = p->next->next;
	delete(temp);
	return L;
}

//********************************************

int main () {
    int n, x;
    cin >> n;
    cin >> x;

    Node* L = Create(x);
    Node* p = L;
    for (int i = 1; i < n; i++) {
        cin >> x;
        p = AddElement (p, x);
    }

	//Random
	L = mergeSort (L);
	Print(L);

	//********************ADD********************
	cout << "\nAdd Nodes: \n";
    int k;
    cin >> k >> x;
    if (k == 0) L = AddHead (L, x);
    else if (k == n) L = AddTail (L, x);
    else L = AddAt (L, k, x);
	cout << "Linked List after adding node: ";
    Print (L);
	cout << endl;

	//*******************DELETE*******************
	cout << "\nDelete Nodes: \n";
	int del;
	cin >> del >> x;
	if (del == 0) L = DeleteHead (L, x);
	else if (del == n - 1) L = DeleteTail (L, x);
	else L = DeleteAt (L, del, x);
	cout << "Linked List after deleting node: ";
	Print(L);
	cout << endl;

    return 0;
}