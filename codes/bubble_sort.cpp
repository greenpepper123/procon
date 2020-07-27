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
    int N, count=0;
    int A[110];
    std::cin >> N;
    for (int i=0; i<N; i++) {
        std::cin >> A[i];
    }

    if (N > 1) {
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i=N-1; i>0; i--) {
                if (A[i] < A[i-1]) {
                    swap(&A[i], &A[i-1]);
                    count++;
                    flag = true;
                }
            }
        }
    }
    print_state(A,N);
    std::cout  << count << std::endl;

    return 0;
}
