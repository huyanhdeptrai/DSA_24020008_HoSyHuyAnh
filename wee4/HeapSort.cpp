#include <iostream>
using namespace std;

const int MAX_SIZE = 1000068;
int a[MAX_SIZE], n;

// Hoán đổi hai phần tử
void doicho(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

// Vun đống (max-heap) tại vị trí i, xét n phần tử đầu
void vundong(int n, int i) {
    while (true) {
        int lon = i;
        int trai = 2 * i + 1;
        int phai = 2 * i + 2;
        if (trai < n && a[trai] > a[lon]) lon = trai;
        if (phai < n && a[phai] > a[lon]) lon = phai;
        if (lon == i) return;
        doicho(a[i], a[lon]);
        i = lon;
    }
}

// Xây dựng max-heap từ mảng ban đầu
void xaydung() {
    for (int i = n / 2 - 1; i >= 0; i--)
        vundong(n, i);
}

// Sắp xếp vun đống: đưa phần tử lớn nhất về cuối rồi vun lại phần còn lại
void heapsort() {
    xaydung();
    for (int i = n - 1; i > 0; i--) {
        doicho(a[0], a[i]);
        vundong(i, 0);
    }
}

// Duyệt mảng từ đầu đến cuối
void duyetxuoi() {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Mang ban dau: ";
    duyetxuoi();

    heapsort();

    cout << "Mang sau khi sap xep: ";
    duyetxuoi();
    return 0;
}
