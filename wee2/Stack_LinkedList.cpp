#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* dinh = NULL;

Node* makeNode(int val) {
    Node* p = new Node();
    p->data = val;
    p->next = NULL;
    return p;
}

// Thêm phần tử lên đỉnh ngăn xếp
void push(int val) {
    Node* p = makeNode(val);
    p->next = dinh;
    dinh = p;
}

// Lấy phần tử ở đỉnh ngăn xếp
bool pop(int &val) {
    if (dinh == NULL) return false;
    Node* temp = dinh;
    val = temp->data;
    dinh = dinh->next;
    delete temp;
    return true;
}

// Xem phần tử ở đỉnh ngăn xếp
bool xemdinh(int &val) {
    if (dinh == NULL) return false;
    val = dinh->data;
    return true;
}

// Đếm số phần tử
int demsophantu() {
    int count = 0;
    Node* cur = dinh;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

// Kiểm tra ngăn xếp rỗng
bool rong() {
    return dinh == NULL;
}

// Duyệt từ đỉnh xuống đáy ngăn xếp
void duyetxuoi() {
    Node* cur = dinh;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void giaiphong() {
    int val;
    while (pop(val)) {}
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Ngan xep ban dau: ";
    duyetxuoi();
    cout << "So phan tu: " << demsophantu() << "\n";

    int val;
    if (pop(val))
        cout << "Lay ra: " << val << "\n";

    push(40);
    cout << "Ngan xep sau khi thao tac: ";
    duyetxuoi();

    if (xemdinh(val))
        cout << "Phan tu dinh: " << val << "\n";

    giaiphong();
    return 0;
}
