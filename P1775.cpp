#include <iostream>
#include <cstring>

int dp[310][310] = {0};
int sum[310] = {0};
int n;

int main() {
    std::cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int a; std::cin >> a;
        sum[i] = a + sum[i-1];
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int begin = 1; begin + len - 1 <= n; begin++) {
            int end = begin + len - 1;
            for (int cut = begin; cut < end; cut++) {
                dp[begin][end] = std::min(
                    dp[begin][end],
                    dp[begin][cut] + dp[cut+1][end] + sum[end] - sum[begin - 1]
                                         );
            }
        }
    }
    std::cout << dp[1][n] << std::endl;
}


