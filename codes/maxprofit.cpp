#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<long long> prices, max_cand;
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long long in;
        std::cin >> in;
        prices.push_back(in);
    }
    long long min = 1e9+1;
    for (int i = 0; i < n - 1; i++) {
        if (min > prices[i]) {
            min = prices[i];
            long long max = prices[i+1];
            for (int j = i+2; j < n; j++) {
                if (prices[j] > max) {
                    max = prices[j];
                }
            }
            max_cand.push_back(max-prices[i]);
        }
    }
    std::cout << *std::max_element(max_cand.begin(), max_cand.end()) << std::endl;

    return 0;
}
