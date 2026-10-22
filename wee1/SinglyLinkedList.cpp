#include <bits/stdc++.h>,*
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int val) {
    Node* p = new Node();
    p->data = val;
    p->next = NULL;
    return p;
}

// Đếm số phần tử
int demsophantu(Node* head) {
    int count = 0;
    Node* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

// Truy cập phần tử vị trí i
int truycap(Node* head, int i) {
    Node* cur = head;
    for (int j = 0; j < i && cur != NULL; j++) {
        cur = cur->next;
    }
    if (cur == NULL) return -1;
    return cur->data;
}

// Chèn đầu
void chendau(Node* &head, int val) {
    Node* p = makeNode(val);
    p->next = head;
    head = p;
}

// Chèn cuối
void chencuoi(Node* &head, int val) {
    if (head == NULL) {
        chendau(head, val);
        return;
    }
    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = makeNode(val);
}

// Chèn vào vị trí i
void chenvaoi(Node* &head, int val, int i) {
    if (i == 0) {
        chendau(head, val);
        return;
    }
    Node* cur = head;
    for (int j = 0; j < i - 1 && cur != NULL; j++) {
        cur = cur->next;
    }
    if (cur == NULL) return;

    Node* p = makeNode(val);
    p->next = cur->next;
    cur->next = p;
}

// Xoá đầu
void xoadau(Node* &head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Xoá cuối
void xoacuoi(Node* &head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* cur = head;
    while (cur->next->next != NULL) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = NULL;
}

// Xoá phần tử tại vị trí i
void xoaphantui(Node* &head, int i) {
    if (head == NULL) return;
    if (i == 0) {
        xoadau(head);
        return;
    }
    Node* cur = head;
    for (int j = 0; j < i - 1 && cur->next != NULL; j++) {
        cur = cur->next;
    }
    if (cur->next == NULL) return;

    Node* toDelete = cur->next;
    cur->next = toDelete->next;
    delete toDelete;
}

// Duyệt xuôi
void duyetxuoi(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

// Duyệt ngược
void duyetnguoc(Node* cur) {
    if (cur == NULL) return;
    duyetnguoc(cur->next);
    cout << cur->data << " ";
}

int main() {
    Node* head = NULL;

    chencuoi(head, 10);
    chencuoi(head, 20);
    chendau(head, 5);
    chenvaoi(head, 15, 2);

    cout << demsophantu(head) << "\n";
    cout << truycap(head, 2) << "\n";

    duyetxuoi(head);
    duyetnguoc(head);
    cout << "\n";

    xoadau(head);
    xoacuoi(head);
    xoaphantui(head, 0);

    duyetxuoi(head);
    return 0;
}