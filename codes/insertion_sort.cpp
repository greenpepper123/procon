#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

void print_state(int* A, int N) {
    for (int i=0; i<N-1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[N-1] << std::endl;
};

void swap(int* a, int* b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
};

int main() {
    int N;
    int A[1000];
    std::cin >> N;
    for (int i=0; i<N; i++) {
        std::cin >> A[i];
    }

    print_state(A,N);
    if (N > 1) {
        for (int i=1; i<N; i++) {
            // ideal: bisect
            for (int j=0; j<i; j++) {
                if (A[i] < A[j]) {
                    for (int k=j; k<i; k++) {
                        swap(&A[k],&A[i]);
                    }
                }
            }
            print_state(A,N);
        }
    }
    return 0;
}
