bool less(int a, int b) {
    return a < b;
}
bool greater(int a, int b) {
    return a > b;
}
using CompareFunc = bool(int, int);
 
void sort(int* begin, int* end, CompareFunc* comp) {
    for (int* i = begin; i < end; i++) {
        for (int* j = begin; j < end - 1; j++) {
            if (!(*comp)(*j, *(j + 1))) {
                int temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}
 
#include <iostream>
 
int main() {
    int a[100];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    sort(a, a + n, &less);
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
    sort(&a[0], &a[n], &greater);
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << ' ';
    }
}
