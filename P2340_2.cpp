#include <iostream>
#include <cstring>

#define N 8000100
using namespace std;
int n;
int a[500], b[500], dp[N];

signed main() {
    int ans = -2147483647;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[400000] = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= 0) {
            for (int j = 800000; j >= a[i]; --j) {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        } else {
            for (int j = 0; j <= 800000 + a[i]; ++j) {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
    }
    for (int i = 400000; i <= 800000; ++i) {
        if (dp[i] >= 0)
            ans = max(ans, a[i] + i - 400000);
    }
    cout << ans;
    return 0;
}
