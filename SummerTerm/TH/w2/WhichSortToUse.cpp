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
// Except Selection Sort, using Cycle Sort
void select_sort(data A[], int n) { //
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        data item = A[cycle_start];
        int pos = cycle_start;

        for (int i = cycle_start + 1; i < n; i++)
            if (A[i] < item)
                pos++;

        if (pos == cycle_start)
            continue;

        while (!(item < A[pos]) && !(A[pos] < item))
            pos++;

        if (pos != cycle_start) {
            data temp = A[pos];
            A[pos] = item;
            item = temp;
        }

        while (pos != cycle_start) {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++)
                if (A[i] < item)
                    pos++;

            while (!(item < A[pos]) && !(A[pos] < item))
                pos++;

            data temp = A[pos];
            A[pos] = item;
            item = temp;
        }
    }
}

// https://chatgpt.com/share/687a21a9-0208-8001-8816-16727903927c
// https://www.geeksforgeeks.org/dsa/cycle-sort/
