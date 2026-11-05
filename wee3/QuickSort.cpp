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

// Phân hoạch đoạn [l..r] theo pivot ngẫu nhiên (Lomuto), trả về vị trí pivot
int phanhoach(int l, int r) {
    doicho(a[l + rand() % (r - l + 1)], a[r]);
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            doicho(a[i], a[j]);
        }
    }
    doicho(a[i + 1], a[r]);
    return i + 1;
}

// Sắp xếp nhanh đoạn [l..r]
void quicksort(int l, int r) {
    if (l >= r) return;
    int p = phanhoach(l, r);
    quicksort(l, p - 1);
    quicksort(p + 1, r);
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

    quicksort(0, n - 1);

    cout << "Mang sau khi sap xep: ";
    duyetxuoi();
    return 0;
}
