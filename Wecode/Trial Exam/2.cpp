#include <iostream>
#include <cmath>

using namespace std;

struct Diem {
    double x, y, z;
    Diem* next;
};

Diem* TaoLinkedList(int n) {
    Diem* head = NULL;
    Diem* tail = NULL;
    for (int i = 0; i < n; ++i) {
        Diem* newDiem = new Diem;
        cin >> newDiem->x >> newDiem->y >> newDiem->z;
        newDiem->next = NULL;
        if (head == NULL) {
            head = newDiem;
            tail = newDiem;
        } 
        else {
            tail->next = newDiem;
            tail = newDiem;
        }
    }
    return head;
}
 
int TimDiem(Diem* head, double x, double y, double z) {
    int index = 0;
    Diem* current = head;
    while (current != NULL) {
        if (current->x == x && current->y == y && current->z == z) {
            return index;
        }
        current = current->next;
        ++index;
    }
    return -1;
}

void run() {
    int n, m;
    cin >> n;
    Diem* A = TaoLinkedList(n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        double x, y, z;
        cin >> x >> y >> z;
        int result = TimDiem(A, x, y, z);
        if (result != -1) {
            cout << result << endl;
        } else {
            cout << "KHONG" << endl;
        }
    }
}

int main() {
    int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}
