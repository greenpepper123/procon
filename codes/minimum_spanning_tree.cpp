#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

constexpr int INF = 3000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, aij, mincost, minu, sum=0;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    std::vector<int> d(n), p(n), color(n); // white:0, gray:1, black:2
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cin >> aij;
            a[i].push_back(aij);
        }
        d[i] = INF;
    }
    d[0]=0;
    p[0]=-1;
    while (true) {
        mincost = INF;
        for (int i=0; i<n; i++) {
            if (color[i] < 2 and d[i] < mincost) {
                mincost = d[i];
                minu = i;
            }
        }
        if (mincost == INF) {
            break;
        }
        color[minu] = 2;
        for (int v=0; v<n; v++) {
            if (color[v] < 2 and a[minu][v] >= 0 and d[v] > a[minu][v]) {
                d[v] = a[minu][v];
                p[v] = minu;
                color[v] = 1;
            }
        }
    }

    for (int i=0; i<n; i++) {
        sum += d[i];
    }
    std::cout << sum << "\n";

    return 0;
}
