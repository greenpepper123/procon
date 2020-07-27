#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int count = 0;

void swap(long int* a, long int* b) {
    auto tmp = *b;
    *b = *a;
    *a = tmp;
}

void inssort(long int* A, int n, int g) {
    for (int i=g; i<n; i++) {
        long int v = A[i];
        int j = i - g;
        while (j>=0 and A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            count++;
        }
        A[j+g] = v;
    }
}

int g(int i) {
    return (std::pow(3, i) - 1)/2;
}

int main() {
    int N, m;
    long int A[1000000];
    std::vector<long int> G;

    std::cin >> N;
    for (int i=0; i<N; i++) {
        std::cin >> A[i];
    }
    for (m = 1; g(m) < N; m++) {
        G.push_back(g(m));
    }
    m--;
    std::reverse(G.begin(), G.end());
    if (m==0) {
        m=1;
        G.push_back(1);
    }

    for (int i=0; i<m; i++) {
        inssort(A, N, G[i]);
    }

    std::cout << m << std::endl;
    for (int i=0; i<G.size(); i++) {
        std::cout << G[i];
        if (not (i == G.size()-1)) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << count << std::endl;
    for (int i=0; i<N; i++) {
        std::cout << A[i] << std::endl;
    }

    return 0;
}
