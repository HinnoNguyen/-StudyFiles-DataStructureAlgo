#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
};


// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */



void insertLinkedList (SinglyLinkedList) {
    
}


void insertSortedLinkedList(SinglyLinkedList* llist, int data) {
  // Create a new node for the data
  SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

  // Handle empty list case
  if (!llist->head) {
    llist->head = llist->tail = newNode;
    return;
  }

  // Traverse the list to find the insertion position
  SinglyLinkedListNode* current = llist->head;
  SinglyLinkedListNode* prev = nullptr;
  while (current != nullptr && current->data < data) {
    prev = current;
    current = current->next;
  }

  // Insert at the beginning
  if (!prev) {
    newNode->next = llist->head;
    llist->head = newNode;
  } else {
    // Insert in the middle or at the end
    newNode->next = current;
    prev->next = newNode;
  }

  // Update tail if the new node has the largest data
  if (data > llist->tail->data) {
    llist->tail = newNode;
  }
}

void reverseLinkedList(SinglyLinkedList* llist) {
  SinglyLinkedListNode* current = llist->head;
  SinglyLinkedListNode* prev = nullptr;
  SinglyLinkedListNode* next;

  while (current != nullptr) {
    // Store the next node before overwriting
    next = current->next;

    // Reverse the link
    current->next = prev;

    // Update pointers for next iteration
    prev = current;
    current = next;
  }

  // Update head and tail pointers after reversal
  llist->tail = llist->head;
  llist->head = prev;
}



int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}