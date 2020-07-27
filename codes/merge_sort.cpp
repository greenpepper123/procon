#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int count=0;

std::vector<long int> merge(std::vector<long int> v1, std::vector<long int> v2) {
    int c1=0, c2=0;
    std::vector<long int> sorted;
    while (true) {
        if (c1 < v1.size()) {
            count++;
            if (c2 < v2.size()) {
                if (v1[c1] < v2[c2]) {
                    sorted.push_back(v1[c1]);
                    c1++;
                } else {
                    sorted.push_back(v2[c2]);
                    c2++;
                }
            } else {
                sorted.push_back(v1[c1]);
                c1++;
            }
        } else {
            if (c2 < v2.size()) {
                count++;
                sorted.push_back(v2[c2]);
                c2++;
            } else {
                break;
            }
        }
    }
    return sorted;
}

std::vector<long int> merge_sort(std::vector<long int> v) {
    if (v.size() == 1) {
        return v;
    } else {
        std::vector<long int> half1(v.size()/2);
        std::vector<long int> half2(v.size()-v.size()/2);
        std::copy(v.begin(), v.begin()+(v.size()/2), half1.begin());
        std::copy(v.begin()+(v.size()/2), v.end(), half2.begin());
        return merge(merge_sort(half1), merge_sort(half2));
    }
}

int main() {
    int n;
    std::vector<long int> S;
    std::cin >> n;
    for (int i=0; i<n; i++) {
        long int s;
        std::cin >> s;
        S.push_back(s);
    }

    auto ans=merge_sort(S);
    for (int i=0; i<n-1; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << ans[n-1] << std::endl << count << std::endl;

    return 0;
}
