#include <iostream>
using namespace std;

const int MAX_SIZE = 1000068;
int a[MAX_SIZE];
int dau = 0, soluong = 0;

// Thêm phần tử vào cuối hàng đợi
bool enqueue(int val) {
    if (soluong == MAX_SIZE) return false;
    a[(dau + soluong) % MAX_SIZE] = val;
    soluong++;
    return true;
}

// Lấy phần tử ở đầu hàng đợi
bool dequeue(int &val) {
    if (soluong == 0) return false;
    val = a[dau];
    dau = (dau + 1) % MAX_SIZE;
    soluong--;
    return true;
}

// Xem phần tử ở đầu hàng đợi
bool xemdau(int &val) {
    if (soluong == 0) return false;
    val = a[dau];
    return true;
}

// Đếm số phần tử
int demsophantu() {
    return soluong;
}

// Kiểm tra hàng đợi rỗng
bool rong() {
    return soluong == 0;
}

// Duyệt hàng đợi từ đầu đến cuối
void duyetxuoi() {
    for (int i = 0; i < soluong; i++)
        cout << a[(dau + i) % MAX_SIZE] << " ";
    cout << "\n";
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
    return 0;
}
