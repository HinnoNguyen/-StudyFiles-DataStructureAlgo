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
//Minor workspace 2: Identify struct, class 

/*-------------------------------------------------------------*/
//Minor workspace 3: Identify lower functions 


/*-------------------------------------------------------------*/
int main() {
    //utilize cin|cout 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    /*---------------------------------------------------------*/
    //Major workspace: Identify variables, Execute functions 

    // stack = LIFO data structure: Last in First out
    //         store objects into a sort of "vertical tower"
    //         push() to add to the top
    //         pop() to remove from the top

    stack<string> stack = new stack<string>(); // stack data structure



    /*---------------------------------------------------------*/
    return 0;
}