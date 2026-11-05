#include <iostream>
using namespace std;

const int MAX_SIZE = 1000068;
int a[MAX_SIZE], tam[MAX_SIZE], n;

// Trộn hai đoạn đã sắp xếp [l..m] và [m+1..r]
void tron(int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tam[k++] = a[i++];
        else tam[k++] = a[j++];
    }
    while (i <= m) tam[k++] = a[i++];
    while (j <= r) tam[k++] = a[j++];
    for (k = l; k <= r; k++)
        a[k] = tam[k];
}

// Sắp xếp trộn đoạn [l..r]: chia đôi, sắp xếp từng nửa rồi trộn lại
void mergesort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    tron(l, m, r);
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

    mergesort(0, n - 1);

    cout << "Mang sau khi sap xep: ";
    duyetxuoi();
    return 0;
}
