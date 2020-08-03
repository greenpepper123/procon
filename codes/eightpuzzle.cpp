#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

int serialize(char* c) {
    int sum=0;
    for (int i=0; i<8; i++) {
        sum+=static_cast<int>(c[i])*std::pow(10, 7-i);
    }
    return sum;
}

int manip(int dir, int p) {
    int z = 8, d, x;
    std::set<int> lack = {0,1,2,3,4,5,6,7,8};
    for (int i=7; i>=0; i--) {
        int keta = (p/int(std::pow(10, i)))%10;
        lack.erase(keta);
        if (keta == 0) {
            z=7-i;
            break;
        }
    }
    if (dir == 0) {
        if (z<3) {
            return 0;
        } 
        d = z-3;
    } else if (dir == 1) {
        if (z%3 == 2) {
            return 0;
        }
        d = z+1;
    } else if (dir == 2) {
        if (z>5) {
            return 0;
        }
        d = z+3;
    } else if (dir == 3) {
        if (z%3 == 0) {
            return 0;
        }
        d = z-1;
    }

    if (d==8) {
        x = *lack.begin();
        return p+x*std::pow(10, 7-z);
    } else if (z==8) {
        x = (p/int(std::pow(10,7-d)))%10;
        return p-x*std::pow(10, 7-d);
    } else {
        x = (p/int(std::pow(10,7-d)))%10;
        return p-x*std::pow(10, 7-d)+x*std::pow(10, 7-z);
    }
}

char cost[100000000];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::queue<int> bfs;
    char p[9], tmp[9];
    int a, cos=0;
    for (int i=0; i<100000000; i++) {
        cost[i]=120;
    }
    for (int i=0; i<9; i++) {
        std::cin >> a;
        p[i]=static_cast<char>(a);
    }
    bfs.push(serialize(p));
    cost[bfs.front()] = 0;
    while (not bfs.empty()) {
        auto now = bfs.front();
        bfs.pop();
        cos = cost[now]+1;
        int dir0 = manip(0, now);
        int dir1 = manip(1, now);
        int dir2 = manip(2, now);
        int dir3 = manip(3, now);
        //std::cout << now << " " << dir0 << " " << dir1 << " " << dir2 << " " << dir3 << "\n"; 
        if (dir0 > 0) {
            bfs.push(dir0);
            if (cost[dir0] > cos) {
                cost[dir0] = cos;
            }
        }
        if (dir1 > 0) {
            bfs.push(dir1);
            if (cost[dir1] > cos) {
                cost[dir1] = cos;
            }
        }
        if (dir2 > 0) {
            bfs.push(dir2);
            if (cost[dir2] > cos) {
                cost[dir2] = cos;
            }
        }
        if (dir3 > 0) {
            bfs.push(dir3);
            if (cost[dir3] > cos) {
                cost[dir3] = cos;
            }
        }
        if (dir0 == 12345678 or dir1 == 12345678 or dir2 == 12345678 or dir3 == 12345678) {
            break;
        }
    }
    std::cout << static_cast<int>(cost[12345678]) << "\n";

    return 0;
}
