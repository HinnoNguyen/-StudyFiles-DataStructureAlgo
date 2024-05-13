#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    int id;
    int count;

    Item(int _id) : id(_id), count(0) {}
};

void merge(vector<Item>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Item> L(n1, Item(0));
    vector<Item> R(n2, Item(0));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].count >= R[j].count) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Item>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cin >> N;

    vector<Item> items;
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        items.push_back(Item(id));
    }

    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        items[i].count++;
    }

    mergeSort(items, 0, N - 1);

    for (const auto& item : items) {
        cout << item.id << " " << item.count << endl;
    }

    return 0;
}