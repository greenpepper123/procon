#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int fib(int* f, int n) {
    if (f[n] == 0) {
        f[n] = fib(f, n-1) + fib(f, n-2);
    }
    return f[n];
}

int main() {
    int n;
    std::cin >> n;
    int f[50] = {1, 1};

    std::cout << fib(f, n) << "\n";
    return 0;
}
