#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

struct List {
    Node* Head;
};

void CreateList (List& LS) {
    LS.Head = NULL;
}

void AddNode (List& LS, int x) {
    Node* temp = new Node(x);
    if (LS.Head == NULL) LS.Head = temp;
    else {
        Node* cur = LS.Head;
        Node*pre = NULL;
        while (cur != NULL) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = temp;
    }
}

void PrintList (Node* Head) {
    if (Head == NULL) cout << "NULL";
    else {
        Node* temp = Head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == NULL) cout << "NULL";
        }
    }
}

struct HashTable {
    int size;
    int quantity;
    List Table[100];
    /*
        *p la con tro
        *p = new int[10]; -> *p goi den phan tu dau tien trong mang 

        (neu ban [])
        *(p + i) -> truy cap toi phan tu trong mang
        int *a = (int*)malloc(10 * sizeof(int));  
    */
};

void CreateHashTable (HashTable& ht, int x, int y) {
    ht.size = x;
    ht.quantity = y;
    for (int i = 0; i < x; i++) CreateList(ht.Table[i]);
}

int Hash_Func (int size, int key) {
    return key % size;
}

void AddKey (HashTable& ht, int key) {
    if (ht.quantity < ht.size) {
        AddNode (ht.Table[Hash_Func(ht.size,key)], key);
        ht.quantity++;
    }
}

void PrintHashTable (HashTable& ht) {
    for (int i = 0; i < ht.size; i++) {
        cout << i << ": ";

//        Node *top = ht.Table[i].Head;
//        while (top != NULL) {
//            cout << top->data << " ";
//            top = top->next;
//        }
//        cout << endl;
//    }

        PrintList (ht.Table[i].Head); // printList(ht.table[i].head);
        cout << endl;
    }
}

int CountCollisions(List& LS) {
    int count = 0;
    Node* cur = LS.Head;
    while (cur != NULL) {
        Node* temp = cur->next;
        while (temp != NULL) {
            if (cur->data == temp->data)
                count++;
            temp = temp->next;
        }
        cur = cur->next;
    }
    return count;
}

void CheckCollisions(HashTable& ht) {
    for (int i = 0; i < ht.size; i++) {
        int collisions = CountCollisions(ht.Table[i]);
        cout << "Bucket " << i << ": " << collisions << " collision(s)" << endl;
    }
}

int main () {
    int size, quantity; // kich thuoc bang bam, kich thuoc phan tu
    cin >> size >> quantity;

    HashTable HT;
    CreateHashTable (HT, size, quantity);
    
    queue<int> q;
    for (int i = 1; i <= quantity; i++) {
        int key = i + rand() % 100;
        cout << key << " ";
        q.push(key);
    }
    cout << endl;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        AddKey(HT, top);
    }
        
    cout << "Hash table: ";

    cout << "\nCollision count per bucket:" << endl;
    CheckCollisions(HT);
    
    PrintHashTable (HT);
}