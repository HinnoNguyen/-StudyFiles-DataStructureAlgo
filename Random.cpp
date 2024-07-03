#include <iostream>
#include <vector>
using namespace std;

struct BoDuLieu {
    int x, y;

    BoDuLieu(int x, int y) : x(x), y(y) {}
};

void merge(vector<BoDuLieu>& arr, int left, int mid, int right) {
    vector<BoDuLieu> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i].x < arr[j].x || (arr[i].x == arr[j].x && arr[i].y <= arr[j].y)) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

void mergeSort(vector<BoDuLieu>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<BoDuLieu> data = {{5, 2}, {3, 1}, {5, 1}, {3, 3}};
    mergeSort(data, 0, data.size() - 1);

    for (const auto& d : data) {
        cout << "(" << d.x << ", " << d.y << ") ";
    }

    return 0;
}