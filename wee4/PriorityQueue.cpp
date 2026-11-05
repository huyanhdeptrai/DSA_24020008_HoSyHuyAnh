#include <iostream>
using namespace std;

const int MAX_SIZE = 1000068;
int a[MAX_SIZE];
int n = 0;

// Hoán đổi hai phần tử
void doicho(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

// Thêm phần tử vào hàng đợi ưu tiên (phần tử lớn nhất có độ ưu tiên cao nhất)
bool push(int val) {
    if (n == MAX_SIZE) return false;
    a[n] = val;
    int i = n++;
    // đẩy lên cho đến khi cha không nhỏ hơn
    while (i > 0 && a[(i - 1) / 2] < a[i]) {
        doicho(a[(i - 1) / 2], a[i]);
        i = (i - 1) / 2;
    }
    return true;
}

// Lấy phần tử có độ ưu tiên cao nhất
bool pop(int &val) {
    if (n == 0) return false;
    val = a[0];
    a[0] = a[--n];
    // đẩy xuống cho đến khi thoả mãn tính chất đống
    int i = 0;
    while (true) {
        int lon = i;
        int trai = 2 * i + 1;
        int phai = 2 * i + 2;
        if (trai < n && a[trai] > a[lon]) lon = trai;
        if (phai < n && a[phai] > a[lon]) lon = phai;
        if (lon == i) break;
        doicho(a[i], a[lon]);
        i = lon;
    }
    return true;
}

// Xem phần tử có độ ưu tiên cao nhất
bool xemdau(int &val) {
    if (n == 0) return false;
    val = a[0];
    return true;
}

// Đếm số phần tử
int demsophantu() {
    return n;
}

// Kiểm tra hàng đợi rỗng
bool rong() {
    return n == 0;
}

// Duyệt theo thứ tự lưu trong đống
void duyetxuoi() {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    push(30);
    push(10);
    push(50);
    push(20);

    cout << "Hang doi uu tien ban dau: ";
    duyetxuoi();
    cout << "So phan tu: " << demsophantu() << "\n";

    int val;
    if (pop(val))
        cout << "Lay ra: " << val << "\n";

    push(40);
    cout << "Hang doi uu tien sau khi thao tac: ";
    duyetxuoi();

    if (xemdau(val))
        cout << "Phan tu uu tien nhat: " << val << "\n";

    cout << "Lay het theo thu tu uu tien: ";
    while (pop(val))
        cout << val << " ";
    cout << "\n";
    return 0;
}
