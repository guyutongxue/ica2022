#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char type[10]{};
    int num;
    cin >> type >> num;
    if (strcmp(type, "heitao") == 0 && num >= 2 && num <= 9) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}