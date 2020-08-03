#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

constexpr int INF = 10000001;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, u, k, vv, cc;
    std::cin >> n;
    std::vector<std::vector<int>> v(n), c(n);
    std::vector<int> d(n), p(n);
    std::set<int> v_s, s;
    for (int i=0; i<n; i++) {
        std::cin >> u >> k;
        for (int j=0; j<k; j++) {
            std::cin >> vv >> cc;
            v[u].push_back(vv);
            c[u].push_back(cc);
        }
        d[i] = INF;
        v_s.insert(i);
    }
    d[0] = 0;
    //v_s.erase(0);

    while (not v_s.empty()) {
        int mind=INF+1;
        int minnode;
        auto iter = v_s.begin();
        for (int i=0; i<v_s.size(); i++,iter++) {
            if (d[*iter] < mind) {
                mind = d[*iter];
                minnode = *iter;
            }
        }
        v_s.erase(minnode);
        s.insert(minnode);
        for (int i=0; i<v[minnode].size(); i++) {
            if (v_s.find(v[minnode][i]) != v_s.end() and mind + c[minnode][i] < d[v[minnode][i]]) {
                d[v[minnode][i]] = mind + c[minnode][i];
                p[v[minnode][i]] = minnode;
            }
        }
    }

    for (int i=0; i<n; i++) {
        std::cout << i << " " << d[i] << "\n";
    }

    return 0;
}
