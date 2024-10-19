#include <iostream>

int dp[40][40][40][40] = {0};
int cards[5] = {0}, values[355] = {0};
int n, m;

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> values[i];
    }
    for (int i = 0; i < m; i++) {
        int a; std::cin >> a;
        cards[a] ++;
    }
    dp[0][0][0][0] = values[1];
    for (int i = 0; i <= cards[1]; i++) {
        for (int j = 0; j <= cards[2]; j++) {
            for (int k = 0; k <= cards[3]; k++) {
                for (int l = 0; l <= cards[4]; l++) {
                    int distance = 1+ i + 2*j + 3*k + 4*l;
                    if (i != 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i-1][j][k][l] + values[distance]);
                    }
                    if (j != 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j-1][k][l] + values[distance]);
                    }
                    if (k != 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k-1][l] + values[distance]);
                    }
                    if (l != 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k][l-1] + values[distance]);
                    } 
                }
            }
        }
    }
    std::cout << dp[cards[1]][cards[2]][cards[3]][cards[4]] << std::endl;
    return 0;
}

