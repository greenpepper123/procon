#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int tl(char c) {
    if (c == 'A') {
        return 1;
    } else if (c == 'C') {
        return 2;
    } else if (c == 'G') {
        return 3;
    } else if (c == 'T') {
        return 4;
    }
}

long int hash(std::string s) {
    long int ret = 0;
    for (int i=0; i<s.size(); i++) {
        ret += tl(s[i]) * std::pow(5,i);
    }
    return ret;
}

int main() {
    int n;
    std::cin >> n;
    static bool dict[1<<28] = {};
    for (int i=0; i<n; i++) {
        std::string operation, operand;
        std::cin >> operation >> operand;
        if (operation == std::string("insert")) {
            dict[hash(operand)]=true;
        } else {
            if (dict[hash(operand)]) {
                std::cout << "yes" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        }
    }

    return 0;
}
