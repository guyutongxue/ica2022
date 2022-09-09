#include <iostream>
using namespace std;

int main() {
    char a[1001] = {};
    cin.getline(a, 1000, '\n');
    int num1 = 0, num2 = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == '*')
            num1++;
        if (a[i] == '@')
            num2++;
    }
    cout << "*出现了" << num1 << "次;" << endl;
    cout << "@出现了" << num2 << "次." << endl;
}