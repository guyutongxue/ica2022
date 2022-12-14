#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void sort(Node* head) {
    for (Node* i = head; i; i = i->next) {
        for (Node* j = head; j->next; j = j->next) {
            if (j->value > j->next->value) {
                int temp = j->value;
                j->value = j->next->value;
                j->next->value = temp;
            }
        }
    }
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
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        Node head{};
        Node* current = &head;
        do {
            int x;
            cin >> x;
            current->next = new Node{x, nullptr};
            current = current->next;
        } while (cin.get() != '\n');
        sort(head.next);
        print(head.next);
        deleteList(head.next);
    }
}