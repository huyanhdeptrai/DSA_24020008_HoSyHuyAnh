#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* makeNode(int val) {
    Node* p = new Node();
    p->data = val;
    p->prev = NULL;
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
void chendau(Node* &head, Node* &tail, int val) {
    Node* p = makeNode(val);
    if (head == NULL) {
        head = tail = p;
        return;
    }
    p->next = head;
    head->prev = p;
    head = p;
}

// Chèn cuối
void chencuoi(Node* &head, Node* &tail, int val) {
    if (head == NULL) {
        chendau(head, tail, val);
        return;
    }
    Node* p = makeNode(val);
    tail->next = p;
    p->prev = tail;
    tail = p;
}

// Chèn vào vị trí i
void chenvaoi(Node* &head, Node* &tail, int val, int i) {
    if (i == 0) {
        chendau(head, tail, val);
        return;
    }
    Node* cur = head;
    for (int j = 0; j < i && cur != NULL; j++) {
        cur = cur->next;
    }
    if (cur == NULL) {
        chencuoi(head, tail, val);
        return;
    }

    Node* p = makeNode(val);
    p->next = cur;
    p->prev = cur->prev;
    cur->prev->next = p;
    cur->prev = p;
}

// Xoá đầu
void xoadau(Node* &head, Node* &tail) {
    if (head == NULL) return;
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

// Xoá cuối
void xoacuoi(Node* &head, Node* &tail) {
    if (tail == NULL) return;
    if (head == tail) {
        xoadau(head, tail);
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}

// Xoá phần tử tại vị trí i
void xoaphantui(Node* &head, Node* &tail, int i) {
    if (head == NULL) return;
    if (i == 0) {
        xoadau(head, tail);
        return;
    }
    Node* cur = head;
    for (int j = 0; j < i && cur != NULL; j++) {
        cur = cur->next;
    }
    if (cur == NULL) return;
    if (cur == tail) {
        xoacuoi(head, tail);
        return;
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
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
void duyetnguoc(Node* tail) {
    Node* cur = tail;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << "\n";
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    chencuoi(head, tail, 10);
    chencuoi(head, tail, 20);
    chendau(head, tail, 5);
    chenvaoi(head, tail, 15, 2);

    cout << demsophantu(head) << "\n";
    cout << truycap(head, 2) << "\n";

    duyetxuoi(head);
    duyetnguoc(tail);

    xoadau(head, tail);
    xoacuoi(head, tail);
    xoaphantui(head, tail, 0);

    duyetxuoi(head);
    return 0;
}