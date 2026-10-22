#include <iostream>
using namespace std;

const int MAX_SIZE = 1000068;
int a[MAX_SIZE];
int dinh = -1;

// Thêm phần tử lên đỉnh ngăn xếp
bool push(int val) {
    if (dinh == MAX_SIZE - 1) return false;
    a[++dinh] = val;
    return true;
}

// Lấy phần tử ở đỉnh ngăn xếp
bool pop(int &val) {
    if (dinh == -1) return false;
    val = a[dinh--];
    return true;
}

// Xem phần tử ở đỉnh ngăn xếp
bool xemdinh(int &val) {
    if (dinh == -1) return false;
    val = a[dinh];
    return true;
}

// Đếm số phần tử
int demsophantu() {
    return dinh + 1;
}

// Kiểm tra ngăn xếp rỗng
bool rong() {
    return dinh == -1;
}

// Duyệt từ đáy lên đỉnh ngăn xếp
void duyetxuoi() {
    for (int i = 0; i <= dinh; i++)
        cout << a[i] << " ";
    cout << "\n";
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
    return 0;
}
