#include <iostream>

int n, m;
bool map[2010][2010] = {0};
int sum[2010][2010] = {0};

bool checkDiamond(int x, int y) {
    // 1. find the bottom '#'
    int bottomY = -1;
    for (int i = y; i <= m; i++) {
        if (map[x][i]) bottomY = i;
    }
    if (bottomY == -1) return false; // bottom not found
    // 2. check the border
    int height = bottomY - y + 1;
    if (height % 2 == 0) return false; // even height is impossible
    int middleY = bottomY / 2 + 1;
    int halfHeight = height / 2;
    for (int i = 0; i < halfHeight ; i++) {
        if (i == 0) {
            if (!map[x][y+i]) return false;
        } else {
            if (!map[x-i][y+i]) return false;
            if (!map[x+i][y+i]) return false;
        }
    }
    for (int i = halfHeight; i < height; i++) {

    }
    // 3. check inside
    for (int i = 0; i < height; i++) {
        if (i == 0 || i == height - 1) continue;
        int rangeBegin = x-i;
        int rangeEnd = x+i;
        if (sum[i][rangeEnd] - sum[i][rangeBegin] != 2) return false;
    }
    return true;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch; std::cin >> ch;
            map[i][j] = ch;
            if (ch == '#') {
                sum[i][j] = sum[i][j-1] + 1;
            } else {
                sum[i][j] = sum[i][j-1];
            }
        }
    }
    
}
