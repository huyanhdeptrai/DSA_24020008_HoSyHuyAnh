#include <bits/stdc++.h>
using namespace std;

int a[1000068], n;

// 1. truy cập phần tử ở i
int truycap(int i) {
    return a[i];
}

// 2. chèn vào vị trí i bất kì
void chenvaoi(int x, int i) {
    for (int j = n; j > i; j--)
        a[j] = a[j - 1];
    a[i] = x;
    n++;
}

// 3. chèn đầu
void chendau(int x) {
    chenvaoi(x, 0);
}

// 4. chèn cuối
void chencuoi(int x) {
    chenvaoi(x, n);
}  

// 5. đếm số phần tử
int demsophantu() {
    return n;
}

// 6. xoá phần tử tại i
void xoaphantui(int i) {
    for (int j = i; j < n - 1; j++)
        a[j] = a[j + 1];
    n--;
}

// 7. xoá đầu
void xoadau() {
    xoaphantui(0);
}

// 8. xoá cuối
void xoacuoi() {
    xoaphantui(n - 1);
}

// 9. duyệt xuôi
void duyetxuoi() {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}

// 10. duyệt ngược
void duyetnguoc() {
    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << " ";
    cout << '\n';
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Ban dau: ";
    duyetxuoi();

    chenvaoi(5, min(2, n));
    cout << "Sau khi chen 5 vao vi tri 2: ";
    duyetxuoi();

    chendau(1);
    cout << "Sau khi chen 1 vao dau: ";
    duyetxuoi();

    chencuoi(10);
    cout << "Sau khi chen 10 vao cuoi: ";
    duyetxuoi();

    if (n > 3)
        xoaphantui(3);
    xoadau();
    xoacuoi();

    cout << "Mang sau khi xoa:\n";
    duyetxuoi();
    duyetnguoc();
}