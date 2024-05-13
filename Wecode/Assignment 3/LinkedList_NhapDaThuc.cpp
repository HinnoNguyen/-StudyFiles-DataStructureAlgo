#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};



void Nhap(DATHUC &B, double heso, int somu) {
  // Create a new node for the term
  Node* newNode = new Node(new DONTHUC(heso, somu));

  // Handle empty list case
  if (!B.head) {
    B.head = B.tail = newNode;
    return;
  }

  // Insert the term in descending order of exponent
  Node* current = B.head;
  Node* prev = nullptr;
  while (current != nullptr && current->data->somu > somu) {
    prev = current;
    current = current->next;
  }

  // Insert at the beginning
  if (!prev) {
    newNode->next = B.head;
    B.head = newNode;
  } else {
    // Insert in the middle or at the end
    newNode->next = current;
    prev->next = newNode;
  }

  // Update tail if the new term has the highest exponent
  if (somu > B.tail->data->somu) {
    B.tail = newNode;
  }
}

void Xuat(DATHUC B) {
  Node* current = B.head;
  bool isFirstTerm = true;
  while (current != nullptr) {
    // Print the sign and coefficient for non-zero coefficients
    if (current->data->heso != 0) {
      if (!isFirstTerm) {
        cout << (current->data->heso > 0 ? " + " : " - ");
      }
      isFirstTerm = false;
      cout << abs(current->data->heso);
    }

    // Print the exponent if it's not zero
    if (current->data->somu > 0) {
      cout << "x^" << current->data->somu;
    }

    current = current->next;
  }

  // Print "0" if the polynomial is zero (all coefficients are zero)
  if (isFirstTerm) {
    cout << "0";
  }
}

double TinhDaThuc(DATHUC B, double x) {
  double result = 0.0;
  Node* current = B.head;
  while (current != nullptr) {
    result += current->data->heso * pow(x, current->data->somu);
    current = current->next;
  }
  return result;
}



int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
