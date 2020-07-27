#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, q, C;
    std::vector<long int> S, T;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long int a;
        std::cin >> a;
        S.push_back(a);
    }
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        long int a;
        std::cin >> a;
        T.push_back(a);
    }
    for (int j = 0; j < q; j++) {
        for (int i = 0; i < n; i++) {
            if (S[i] == T[j]) {
                C++;
                break;
            }
        }
    }

    std::cout << C << std::endl;

    return 0;
}
