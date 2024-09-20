#include <iostream>

#define MAX 2510

int mi[MAX] = {0};
int dp[MAX] = {0};
int n, m;

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a; std::cin >> a;
        mi[i] = mi[i-1] + a;
        dp[i] = 1145141919;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = std::min(dp[j], dp[j-i] + mi[i] + 2*m);
        }
    }
    std::cout << dp[n]-m << std::endl;
    return 0;
}
