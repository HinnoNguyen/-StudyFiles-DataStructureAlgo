/*-------------------------------------------------------------
    Instruction to upload code to Github
    git init => git add -A => git commit -m => git push (-f) origin main
---------------------------------------------------------------*/
//Library space: Identify library 
//#include <bits/stdc++.h> //Main library 
#include <iostream>
using namespace std; //Namespace
/*-------------------------------------------------------------*/
//Definiton space: Identify definiton 
#define num_MAX 300
#define MAXN 10000
typedef int* contro_int;
typedef int& thamchieu_int;
/*-------------------------------------------------------------*/
//Minor workspace 1: Identify template 
template <typename T> T* multiple_target_dynamic_allo(int num) {
    return new T[num];
}
template <typename T> T* single_targe_dynamic_allo() {
    return new T;
}
template <typename T> void erase_multiple_target_dynamic_allo(T* ptr) {
    delete[] ptr;
    ptr = nullptr;
}
template <typename T> void erase_single_target_dynamic_allo(T* ptr) {
    delete ptr;
    ptr = nullptr;
}
/*-------------------------------------------------------------*/
//Minor workspace 2: Identify struct, class 
void Print (int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void Merge (int a[], int left, int right, int mid) {
    int m = left;
    int n = mid + 1;
    int k = 0;
    int* temp = new int (right - left + 1);
    while (!((m > mid )&& (n > right))) {
        if ((a[m] < a[n] && m <= mid && n<= right) || (n > right))
            temp[k++] = a[m++];
        else
            temp[k++] = a[n++];
    }
    for (int i = 0; i < k; i++)
        a[left + 1] = temp[i];
    delete[] temp;
}

void MergeSort (int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort (a, left, mid);
        MergeSort (a, mid + 1, right);
        Merge (a, left, mid, right);
    }
}


/*-------------------------------------------------------------*/
int main() {
    //utilize cin|cout 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    /*---------------------------------------------------------*/
    //Major workspace: Identify variables, Execute functions 
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int k = 0; k < n; k++) {
        cout << a[k];
        if (k != n - 1) 
            cout << " ";
    }
    cout << endl;

    /*---------------------------------------------------------*/
    return 0;
}