#include <iostream>

int states[10][10][10][10][10] = {0};

int main() {
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d, e; std::cin >> a >> b >> c >> d >> e;
        for (int j = 0; j <= 9; j++) states[j][b][c][d][e]++;
        for (int j = 0; j <= 9; j++) states[a][j][c][d][e]++;
        for (int j = 0; j <= 9; j++) states[a][b][j][d][e]++;
        for (int j = 0; j <= 9; j++) states[a][b][c][j][e]++;
        for (int j = 0; j <= 9; j++) states[a][b][c][d][j]++;
        for (int j = 1; j <= 9; j++) states[(a+j)%10][(b+j)%10][c][d][e]++;
        for (int j = 1; j <= 9; j++) states[a][(b+j)%10][(c+j)%10][d][e]++;
        for (int j = 1; j <= 9; j++) states[a][b][(c+j)%10][(d+j)%10][e]++;
        for (int j = 1; j <= 9; j++) states[a][b][c][(d+j)%10][(e+j)%10]++;
    }
    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    for (int m = 0; m <= 9; m++) {
                        if (states[i][j][k][l][m] == n) {
                            ans++;
                        } 
                    }
                }
            } 
        }
    }
    std::cout << ans;
    return 0;
}
