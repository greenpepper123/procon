#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int n, u, k, v;
    std::cin >> n;
    for (int i=0; i<n; i++) {
        std::cin >> u >> k;
        int vv[100]={};
        for (int j=0; j<k; j++) {
            std::cin >> v;
            vv[v-1]=1;
        }
        for (int j=0; j<n; j++) {
            /*if (vv[j] != 1) {
                vv[j] = 0;
            }*/
            std::cout << vv[j];
            if (j == n-1) {
                std::cout << "\n";
            } else {
                std::cout << " ";
            }
        }
    }

    return 0;
}
