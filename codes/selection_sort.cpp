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
    int N, minj, count=0;
    int A[110];
    std::cin >> N;
    for (int i=0; i<N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(&A[i], &A[minj]);
            count++;
        }
    }
    print_state(A,N);
    std::cout  << count << std::endl;

    return 0;
}
