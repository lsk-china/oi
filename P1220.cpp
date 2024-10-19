#include <iostream>
#include <cstring>

int n, c;
int distance[105] = {0}, power[105] = {0}, sum[105] = {0}, f[105][105][2] = {0};

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    std::cin >> n >> c;
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) {
        std::cin >> distance[i] >> power[i];
        sum[i] = power[i] + sum[i-1];
    }
    f[c][c][0] = 0;
    f[c][c][1] = 0;
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i+l-1 <=n ; i++) {
            int j = i+l-1;
            f[i][j][1] = min(
                f[i+1][j][1] + (distance[i+1] - distance[i]) * (sum[n] - sum[j] + sum[i]),
                f[i+1][j][0] + (distance[j] - distance[i]) * (sum[n] - sum[j] + sum[i])
                            );
            f[i][j][0] = min(
                f[i][j-1][0] + (distance[j] - distance[j-1]) * (sum[i-1] + sum[n] - sum[j-1]),
                f[i][j-1][1] + (distance[j] - distance[i]) * (sum[i-1] + sum[n] - sum[j-1])
                            );
        }
    }
    std::cout << min(f[1][n][1], f[1][n][0]) << std::endl;
    return 0;
}
