#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int h(std::vector<short> p, int g) {
    int ret = g;
    for (int i=0; i<16; i++) {
        if (p[i]>0) {
            ret += (std::abs((p[i]-1)/4 - i/4) + std::abs((p[i]-1)%4 - i%4)); 
        }
    }
    return ret-2;
}

bool dfs(std::vector<short> p, int d, int limit, int pre_dir) {
    int z;
    int depth = d+1;
    if (d > limit) {
        return false;
    }
    bool ok = true;
    for (int i=0; i<16; i++) {
        if (p[i] == 0) {
            z = i;
        }
        if (p[i] != (i+1)%16) {
            ok = false;
        }
    }
    if (ok) {
        return true;
    }

    if (z>3) {
        auto pp = p;
        pp[z] = pp[z-4];
        pp[z-4] = 0;
        if (pre_dir != 2 and h(pp, depth) < limit and dfs(pp, depth, limit, 0)) {
            return true;
        }
    }
    if (z%4 != 3) {
        auto pp = p;
        pp[z] = pp[z+1];
        pp[z+1] = 0;
        if (pre_dir != 3 and h(pp, depth) < limit and dfs(pp, depth, limit, 1)) {
            return true;
        }
    }
    if (z<12) {
        auto pp = p;
        pp[z] = pp[z+4];
        pp[z+4] = 0;
        if (pre_dir != 0 and h(pp, depth) < limit and dfs(pp, depth, limit, 2)) {
            return true;
        }
    }
    if (z%4 != 0) {
        auto pp = p;
        pp[z] = pp[z-1];
        pp[z-1] = 0;
        if (pre_dir != 1 and h(pp, depth) < limit and dfs(pp, depth, limit, 3)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    bool ini = true;

    std::vector<short> p(16);
    for (int i=0; i<16; i++) {
        std::cin >> p[i];
        if (p[i] != (i+1)%16) {
            ini = false;
        }
    }
    if (ini) {
        std::cout << 0 << "\n";
        return 0;
    }

    for (int limit=1; limit<45; limit++) {
        if (dfs(p, 0, limit, 4)) {
            std::cout << limit << "\n";
            return 0;
        }
    }

    std::cout << 45 << "\n";
    return 0;
}
