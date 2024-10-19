#include <iostream>

int dp[800010] = {0}, iq[500] = {0}, eq[500] = {0};
int n;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> iq[i] >> eq[i];
    for (int i = 0; i < 800010; i++) dp[i] = -114514; 
    dp[400000] = 0; 
    for (int i = 1; i <= n; i++) {
        if (iq[i] > 0) {
            for (int j = 800000; j >= iq[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - iq[i]] + eq[i]);
            }
        } else {
            for (int j = 0; j <= iq[i] + 800000; j++) {
                dp[j] = std::max(dp[j], dp[j - iq[i]] + eq[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 400000; i <= 800000; i++) {
        if (dp[i] <= 0) continue;
        ans = std::max(ans, dp[i] - 400000 + i);
    }
    std::cout << ans << std::endl;
    return 0;
}
