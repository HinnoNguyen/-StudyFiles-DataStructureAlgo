/*-------------------------------------------------------------
    Instruction to upload code to Github
    git init => git add -A => git commit -m => git push (-f) origin main
---------------------------------------------------------------*/
//Library space: Identify library 
#include <iostream> //Main library 
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

/*-------------------------------------------------------------*/
//Minor workspace 3: Identify lower functions 

void bubbleSort(int a[], int n) {
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n - 1 ; j++) {
			if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                for (int k = 0; k < n; k++) {
                    cout << a[k];
                    if (k != n - 1)
                        cout << " ";
                }
                cout << endl;
            }
		}
    }
}

/*-------------------------------------------------------------*/
int main() {
    //utilize cin|cout 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    /*---------------------------------------------------------*/
    //Major workspace: Identify variables, Execute functions 

    int a[20],n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bubbleSort(a,n);

    /*---------------------------------------------------------*/
    return 0;
}