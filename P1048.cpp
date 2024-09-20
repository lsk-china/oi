#include <iostream>

int val[105] = {0}, cost[105] = {0};
int mem[1010][1010] = {0};
int t = 0, m = 0;

int solve(int spaceLeft, int ans, int pos) {
//    if (spaceLeft <= 0) return ans;
//    if (pos > m) return ans;
//    return std::max(solve(spaceLeft - cost[pos], ans + val[pos], pos + 1), solve(spaceLeft, ans, pos + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; <= t; j++) {
            if (j > cost[i]) {
                mem[i][j] = std::max(mem[i-1][j-cost, mem[i-1][j]);
            } else {
                mem[i][j] = mem[i-1][j];
            }
        }
    }
    return 
}

int main() {
    std::cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> cost[i];
        std::cin >> val[i];
    }
    std::cout << solve(t, 0, 1);
    return 0;
}
