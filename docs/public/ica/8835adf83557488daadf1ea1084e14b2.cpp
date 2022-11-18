#include <iostream>
#include <cmath>

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void sort(double* a, double* b, double* c) {
    if (*a > *b) {
        swap(a, b);
    }
    if (*b > *c) {
        swap(b, c);
    }
    if (*a > *b) {
        swap(a, b);
    }
}

void print(double x) {
    if (x == std::floor(x)) {
        std::cout << int(x);
    } else {
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << x;
    }
}

int main() {
    double a, b, c;
    char comma;
    std::cin >> a >> comma >> b >> comma >> c;
    sort(&a, &b, &c);
    
    std::cout.precision(2);
    print(a);
    std::cout << ',';
    print(b);
    std::cout << ',';
    print(c);
    std::cout << std::endl;
}