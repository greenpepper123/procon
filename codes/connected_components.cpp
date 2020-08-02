#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

void dfs(int node, std::vector<std::vector<int>>& v, std::vector<int>& colors, int color) {
    colors[node] = color;
    for (int i=0; i<v[node].size(); i++) {
        if (node != v[node][i] and colors[v[node][i]] == 0) {
            dfs(v[node][i], v, colors, color);
        }
    }
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, q, s, t, color=1;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n);
    std::vector<int> colors(n);
    for (int i=0; i<m; i++) {
        std::cin >> s >> t;
        v[s].push_back(t);
        v[t].push_back(s);
    }
    for (int i=0; i<n; i++) {
        if (colors[i] == 0) {
            dfs(i, v, colors, color++);
        }
    }
    std::cin >> q;
    for (int i=0; i<q; i++) {
        std::cin >> s >> t;
        if (colors[s] == colors[t] and colors[s] != 0) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }

    return 0;
}
