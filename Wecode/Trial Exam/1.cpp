// #include <bits/stdc.h++>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Diem {
    double x, y, z;
};

bool SoSanhDiem (const Diem& a, const Diem& b) {
    if (a.x != b.x)
        return a.x < b.x;
    else if (a.y != b.y)
        return a.y < b.y;
    else
        return a.z < b.z;
}

double BinarySearch (const vector<Diem>& A, const Diem& data) {
    double left = 0;
    double right = A.size() - 1;

    while (left <= right) {
        double mid = left + (right - left) / 2;
        if (A[mid].x == data.x && A[mid].y == data.y && A[mid].z == data.z)
            return mid + 1;
        else if (SoSanhDiem(A[mid], data))
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n;
    vector<Diem> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }

    sort(A.begin(), A.end(), SoSanhDiem);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        Diem di;
        cin >> di.x >> di.y >> di.z;
        
        int kq = BinarySearch(A, di);
        if (kq != 1)
            cout << kq;
        else
            cout << "KHONG";
    }
    return 0;
}