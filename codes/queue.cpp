#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int main() {
    int n, q, time=0;
    typedef std::pair<std::string, int> process;
    std::queue<process> p;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        process pi;
        std::cin >> pi.first >> pi.second;
        p.push(pi);
    }

    while (not p.empty()) {
        if (p.front().second > q) {
            p.push({p.front().first, p.front().second-q});
            time+=q;
        } else {
            time+=p.front().second;
            std::cout << p.front().first << " " << time << std::endl;
        }
        p.pop();
    }
    


    return 0;
}
