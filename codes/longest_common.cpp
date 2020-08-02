#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::string s1, s2;
    for (int q=0; q<n; q++) {
        std::cin >> s1 >> s2;
        int m1 = s1.size()+1;
        int m2 = s2.size()+1;
        int* dp = (int*)malloc(m1*m2*sizeof(int));
        for (int i=0; i<m1; i++) {
            dp[i*m2]=0;
        }
        for (int i=0; i<m2; i++) {
            dp[i]=0;
        }
        for (int i=1; i<m1; i++) {
            int leftmax=0;
            for (int j=1; j<m2; j++) {
                dp[i*m2+j] = leftmax;
                if (s1[i-1] == s2[j-1]) {
                    dp[i*m2+j]+=1;
                }
                if (dp[(i-1)*m2+j] > leftmax) {
                    leftmax = dp[(i-1)*m2+j];
                }
                if (dp[i*m2+j] < dp[(i-1)*m2+j]) {
                    dp[i*m2+j] = dp[(i-1)*m2+j];
                }
            }
        }
        int max=0;
        for (int i=0; i<m2; i++) {
            if (dp[(m1-1)*m2+i] > max) {
                max = dp[(m1-1)*m2+i];
            }
        }
        std::cout << max << "\n";
        free(dp);
    }

    return 0;
}
