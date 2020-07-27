#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, q, sum=0;
    int A[2001]={}, m[2001]={};
    std::cin >> n;
    for (int i=0; i<n; i++) {
        std::cin >> A[i];
        sum+=A[i];
    }
    std::cin >> q;
    for (int i=0; i<q; i++) {
        std::cin >> m[i];
    }

    for (int j=0; j<q; j++) {
        int C;
        bool no=true;
        if (m[j]>sum) {
            std::cout << "no" << std::endl;
            continue;
        }
        for (int i=0; i < std::pow(2,n); i++) {
            C=0;
            for (int j=0; j<n; j++) {
                if ((i >> j) & 1) {
                    C+= A[j];
                }
            }
            if(C==m[j]) {
                std::cout << "yes" << std::endl;
                no=false;
                break;
            }
        }
        if (no) {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}
