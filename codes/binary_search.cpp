#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int bs(int t, std::vector<long int>::iterator b, std::vector<long int>::iterator e) {
    int size = e - b;
    if (size >= 2) {
        if (t < *(b+(size/2))) {
            return bs(t, b, b+(size/2));
        } else {
            return bs(t, b+(size/2), e);
        }
    } else {
        if (*b == t) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int n, q, C = 0;
    std::vector<long int> S;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long int a;
        std::cin >> a;
        S.push_back(a);
    }
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        long int t;
        std::cin >> t;
        C += bs(t, S.begin(), S.end());
    }

    std::cout << C << std::endl;

    return 0;
}
