#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void removeAll(Node* head, int val) {
    if (!head) return;
    while (head->next && head->next->value == val) {
        Node* temp = head->next;
        head->next = head->next->next;
        delete temp;
    }
    removeAll(head->next, val);
}

void print(Node* head) {
    bool isFirst = true;
    for (Node* i = head; i; i = i->next) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << ' ';
        }
        cout << i->value;
    }
    cout << endl;
}

void deleteList(Node* head) {
    if (head->next) {
        deleteList(head->next);
    }
    delete head;
}

int main() {
    Node head{};
    Node* current = &head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current->next = new Node{x, nullptr};
        current = current->next;
    }
    int k;
    cin >> k;
    removeAll(&head, k);
    print(head.next);
    deleteList(head.next);
}