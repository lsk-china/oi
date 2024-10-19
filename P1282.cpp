#include <iostream>
#include <cstring>

int n, sum = 0;
int a[1001] = {0}, b[1001] = {0}, f[6006];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i];
        sum += a[i] + b[i];
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 6 * i; j >= i; j--) {
            if (j >= a[i]) {
                f[j] = std::min(f[j], f[j - a[i]]);
            }
            if (j >= b[i]) {
                f[j] = std::min(f[j], f[j - b[i]]);
            }
        }
    }
    int ans1 = 0x3f3f3f3f, ans2 = 0;
    for (int i = n; i <= 6*n; i++) {
        if (f[i] != 0x3f3f3f3f) {
            if (std::abs(sum - 2*i) < ans1) {
                ans1 = std::abs(sum - 2*i);
                ans2 = f[i];
            } else if (std::abs(sum - 2*i) == ans1) {
                ans2 = std::min(ans2, f[i]);
            }
        }
    }
    std::cout << ans2 << std::endl;
    return 0;
}
