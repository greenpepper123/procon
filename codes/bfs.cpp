#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, u, k, vi;
    std::cin >> n;
    std::vector<std::vector<int>> v(n+1);
    std::queue<int> ex;
    ex.push(1);
    int distance[101]={};
    for (int i=2; i<101; i++) {
        distance[i] = -1;
    }
    for (int i=0; i<n; i++) {
        std::cin >> u >> k;
        for (int j=0; j<k; j++) {
            std::cin >> vi;
            v[u].push_back(vi);
        }
    }

    while (not ex.empty()) {
        int a = ex.front();
        ex.pop();
        for (int i=0; i<v[a].size(); i++) {
            if (distance[v[a][i]] == -1) {
                ex.push(v[a][i]);
                distance[v[a][i]] = distance[a] + 1;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        std::cout << i << " " << distance[i] << "\n";
    }

    return 0;
}
