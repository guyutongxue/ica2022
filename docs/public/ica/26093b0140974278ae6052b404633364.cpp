#include <iostream>
using namespace std;

struct Node {
    int number;
    Node* next;
};

int main() {
    int n, m;
    while (cin >> n >> m, n) {
        Node pseudo{};
        Node* current = &pseudo;
        for (int i = 1; i <= n; i++) {
            current->next = new Node{i, nullptr};
            current = current->next;
        }
        current->next = pseudo.next;

        while (true) {
            for (int i = 1; i < m; i++) {
                current = current->next;
            }
            if (current->next == current) {
                cout << current->number << endl;
                break;
            }
            Node* nextNext = current->next->next;
            delete current->next;
            current->next = nextNext;
        }
        delete current;
    }
}