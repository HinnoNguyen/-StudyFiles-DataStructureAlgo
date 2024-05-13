/*-------------------------------------------------------------
    Instruction to upload code to Github
    git init => git add -A => git commit -m => git push (-f) origin main
---------------------------------------------------------------*/
//Library space: Identify library 
#include <bits/stdc++.h> //Main library 
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

// Link: https://codelearn.io/learning/cau-truc-du-lieu-va-giai-thuat?tab=description&activityId=1277&activityType=12

//Minor workspace 2: Identify struct, class 

/*-------------------------------------------------------------*/
//Minor workspace 3: Identify lower functions 

int search(int a[], int n, int x){
	for (int i = 0; i < n; i++){
		if (a[i] == x){
			return i;
		}
	}
	return -1;
}

/*-------------------------------------------------------------*/
int main() {
    //utilize cin|cout 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    /*---------------------------------------------------------*/
    //Major workspace: Identify variables, Execute functions 
    INT a[100];
    int n, x;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> x;
	cout << search(a, n, x);


    /*---------------------------------------------------------*/
    return 0;
}

// Nhập vào một số nguyên dương n, 
// tiếp theo là n số nguyên lần lượt là các phần tử trong dãy a, 
// cuối cùng nhập số nguyên x.

// Hãy đưa ra chỉ số đầu tiên của phần tử đầu tiên có giá trị bằng x, 
// nếu không tồn tại số đó thì trả về -1.