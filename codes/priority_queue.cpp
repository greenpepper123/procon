#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int left(int i, int n) {
    if (2*i <= n) {
        return 2*i;
    } else {
        return 0;
    }
}

int right(int i, int n) {
    if (2*i+1 <= n) {
        return 2*i+1;
    } else {
        return 0;
    }
}

void swap(int a, int b, std::vector<int>& S) {
    int tmp = S[a];
    S[a] = S[b];
    S[b] = tmp;
}

void maxHeapify(int i, std::vector<int>& A, int n) {
    int largest;
    int l = left(i, n);
    int r = right(i, n);
    if (A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(i, largest, A);
        maxHeapify(largest, A, n);
    }
}

void insert(std::vector<int>& S, int k) {
    /*S.push_back(k);
    for (int i=(S.size()-1)/2; i>0; i--) {
        maxHeapify(i, S, S.size()-1);
    }*/
    S.push_back(k);
    int i = S.size()-1;
    while (i>1 and S[i/2] < S[i]) {
        swap(i, i/2, S);
        i=i/2;
    }
}

void del(std::vector<int>& S, int k) {
    S[1] = S.back();
    S.pop_back();
    for (int i=(S.size()-1)/2; i>0; i--) {
        maxHeapify(i, S, S.size()-1);
    }
}

void extract(std::vector<int>& S) {
    printf("%d\n", S[1]);
    del(S, 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::string s;
    std::vector<int> S = {-1};
    while (true) {
        std::cin >> s;
        if (s == std::string("insert")) {
            int operand;
            std::cin >> operand;
            insert(S, operand);
        } else if (s == std::string("extract")) {
            extract(S);
        } else {
            break;
        }
    }

    return 0;
}
