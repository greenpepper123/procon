#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

void print_state(std::vector<std::string>& A, int N) {
    for (int i=0; i<N-1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[N-1] << std::endl;
};

void swap(std::string * a, std::string * b) {
    auto tmp = *b;
    *b = *a;
    *a = tmp;
};

int val(std::string s) {
    return s[1] - '0';
}

int main() {
    int N, minj;
    std::vector<std::string> B, S;
    std::cin >> N;
    for (int i=0; i<N; i++) {
        std::string a;
        std::cin >> a;
        B.push_back(a);
    }
    S = B;

    // bubble sort
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > i; j--) {
            if (val(B[j]) < val(B[j-1])) {
                swap(&B[j], &B[j-1]);
            }
        } 
    }

    // selective sort
    for (int i=0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (val(S[j]) < val(S[minj])) {
                minj = j;
            }
        }
        swap(&S[i], &S[minj]);
    }

    print_state(B,N);
    std::cout << "Stable" << std::endl;
    print_state(S,N);
    if (B == S) {
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }

    return 0;
}