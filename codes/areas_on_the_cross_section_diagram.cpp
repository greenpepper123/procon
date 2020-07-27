#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>

int main() {
    int sum=0, height=0;
    std::string map;
    std::stack<long int> backslash;
    std::stack<std::pair<int, int>> water, reversed_water;
    std::cin >> map;
    for (int i=0; i<map.size(); i++) {
        if (map.at(i) == '\\') {
            backslash.push(i);
            height--;
        } else if (map.at(i) == '/') {
            height++;
            if (not backslash.empty()) {
                auto new_water = std::make_pair(i-backslash.top(), backslash.top());
                sum+=(i-backslash.top());
                while (not water.empty()) {
                    if (new_water.second < water.top().second) {
                        new_water.first += water.top().first;
                        water.pop();
                    } else {
                        break;
                    }
                }
                water.push(new_water);
                backslash.pop();
            }
        } else if (map.at(i) == '_') {
            //nothing to do?
        } else {
            std::cout << "invalid input" << std::endl;
        }
    }

    std::cout << sum << std::endl << water.size();
    
    while (not water.empty()) {
        reversed_water.push(water.top());
        water.pop();
    }

    while (not reversed_water.empty()) {
        std::cout << " " << reversed_water.top().first;
        reversed_water.pop();
    }
    std::cout << std::endl;

    return 0;
}
