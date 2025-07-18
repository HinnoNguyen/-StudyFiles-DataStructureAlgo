
#include <iostream>
//using namespace std;

class data{
private:
    int x;
    static int assignment_count;
    static int n;
public:

    friend std::ostream& operator<<(std::ostream &os, const data& a);
    friend std::istream& operator>>(std::istream &os, data& a)    ;
    static void set_n(int n){
        if (data::n == 0) data::n = n;
        else std::cout << "WRONG";
    }
    data& operator=(const data& a){
        assignment_count++;
        if (assignment_count > 3* data::n){
            std::cout << "WRONG";
        }
        this->x = a.x;
        return *this;
    }

    bool operator<(const data& a){
        return this->x < a.x;
    }
};
int data::assignment_count = 0;
int data::n = 0;

std::ostream& operator<<(std::ostream &os, const data& a){
    return os << a.x;
}
std::istream& operator>>(std::istream &os, data& a){
    return os >> a.x;
}

int main(){
    int n;
    std::cin >> n;
    data::set_n(n);

    data *A = new data[n];
    for (int i = 0; i < n; i++){
        std::cin >> A[i];
    }

    select_sort(A, n);

    for(int i = 0; i < n; i++){
        std::cout << A[i] << " " ;
    }
}

/* ********************************************************************************************************* */
// Except Selection Sort, using Heap Sort
void swap(data &a, data &b) {
    data temp = a;
    a = b;
    b = temp;
}

void heapify(data A[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && A[largest] < A[l])
        largest = l;
    if (r < n && A[largest] < A[r])
        largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void select_sort(data A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}


// https://handbook.bhtcnpm.com/docs/dsa/phan1/chuong3#36-s%E1%BA%AFp-x%E1%BA%BFp-vun-%C4%91%E1%BB%91ng-heap-sort