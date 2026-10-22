#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* dau = NULL;
Node* cuoi = NULL;

Node* makeNode(int val) {
    Node* p = new Node();
    p->data = val;
    p->next = NULL;
    return p;
}

// Thêm phần tử vào cuối hàng đợi
void enqueue(int val) {
    Node* p = makeNode(val);
    if (dau == NULL) {
        dau = cuoi = p;
        return;
    }
    cuoi->next = p;
    cuoi = p;
}

// Lấy phần tử ở đầu hàng đợi
bool dequeue(int &val) {
    if (dau == NULL) return false;
    Node* temp = dau;
    val = temp->data;
    dau = dau->next;
    if (dau == NULL) cuoi = NULL;
    delete temp;
    return true;
}

// Xem phần tử ở đầu hàng đợi
bool xemdau(int &val) {
    if (dau == NULL) return false;
    val = dau->data;
    return true;
}

// Đếm số phần tử
int demsophantu() {
    int count = 0;
    Node* cur = dau;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

// Kiểm tra hàng đợi rỗng
bool rong() {
    return dau == NULL;
}

// Duyệt hàng đợi từ đầu đến cuối
void duyetxuoi() {
    Node* cur = dau;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void giaiphong() {
    int val;
    while (dequeue(val)) {}
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Hang doi ban dau: ";
    duyetxuoi();
    cout << "So phan tu: " << demsophantu() << "\n";

    int val;
    if (dequeue(val))
        cout << "Lay ra: " << val << "\n";

    enqueue(40);
    cout << "Hang doi sau khi thao tac: ";
    duyetxuoi();

    if (xemdau(val))
        cout << "Phan tu dau: " << val << "\n";

    giaiphong();
    return 0;
}
