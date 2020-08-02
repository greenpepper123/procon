#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

void dfs(int node, std::vector<std::vector<int>>& v, int& time, std::vector<std::vector<int>>& log) {
    log[node].push_back(++time);
    for (int i=0; i<v[node].size(); i++) {
        if (node != v[node][i] and log[v[node][i]].size() == 0) {
            dfs(v[node][i], v, time, log);
        }
    }
    log[node].push_back(++time);
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, u, k, vi, time=0;
    std::cin >> n;
    std::vector<std::vector<int>> v(n+1), log(n+1);
    for (int i=0; i<n; i++) {
        std::cin >> u >> k;
        for (int j=0; j<k; j++) {
            std::cin >> vi;
            v[u].push_back(vi);
        }
    }
    for (int i=1; i<=n; i++) {
        if (log[i].size() == 0) {
            dfs(i, v, time, log);
        }
    }
    for (int i=1; i<=n; i++) {
        std::cout << i << " " << log[i][0] << " " << log[i][1] << "\n";
    }

    return 0;
}
