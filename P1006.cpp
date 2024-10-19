#include <iostream>

int values[51][51] = {0};
bool visited[51][51] = {0};
int memory[51][51] = {0};
int startX = 0, startY = 0, endX = 0, endY = 0;
int n, m;

int dfs(int x, int y, int destX, int destY) {
    if (visited[x][y]) return 0;
    if (x == destX && y == destY) return 0;
    int ans = 0;
    if (x - 1 > 0) {
        visited[x-1][y] = true;
        memory[x-1][y] = ans+values[x-1][y]+dfs(x-1, y);
        ans = std::max(ans, memory[x-1][y]);
    }
    if (y - 1 > 0) {
        visited[x][y-1] = true;
        memory[x][y-1] = ans+values[x][y-1]+dfs(x, y-1);
        ans = std::max(ans, memory[x][y-1]);
    }
    if (x + 1 <= n) {
        visited[x+1][y] =  true;
        memory[x+1][y] = ans+values[x+1][y]+dfs(x+1, y);
        ans = std::max(ans, memory[x+1][y]);
    }
    if (y + 1 <= m) {
        visited[x][y+1] = true;
        memory[x][y+1] = ans+values[x][y+1]+dfs(x, y+1);
        ans = std::max(ans, memory[x][y+1]);
    }
    return ans;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> values[n][m];
            if (values[n][m] == 0 && startX == 0) 
                startX = n, startY = m;
            else 
                endX = n, endY = m;
        }
    }
    
}
