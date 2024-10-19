#include <iostream>

int n, m;
bool map[2010][2010] = {0};
int sum[2010][2010] = {0};

bool shouldHereBeTrue(int x, int y, int size) {
    if (x == 0 || x == size - 1) {
        if (y == size / 2) {
            return true;
        }
    }
    x += 1; y += 1;
    int mid = size / 2 +1;
    if (y <= mid) {
        return (x == mid + y || x == mid - y);
    } else {
        int off = size - y;
        return (x == mid - off || x == mid + off); 
    }
}

bool check2(int topX, int topY) {
    // 1. find bottom
    int bottomY = -1;
    for (int i = topY+1; i <= m; i++) {
        if (map[topX][i]) {
            bottomY = i;
            break;
        }
    }
    if (bottomY == -1)
        return false;
    int height = bottomY - topY + 1;
    if (height % 2 == 0) return false;
    int startX = topX; int startY = topY - height / 2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            if (!shouldHereBeTrue(i, j, height)) return false;  
        }
    }
    return true;
}

bool check(int topX, int topY) {
    // 1. find bottom
    int bottomY = -1;
    for (int i = topY+1; i <= m; i++) {
        if (map[topX][i]) {
            bottomY = i;
            break;
        }
    }
    if (bottomY == -1)
        return false;
    int height = bottomY - topY + 1;
    if (height % 2 == 0) return false;
    height -= 2;
    // 2. check border
    for (int i = 1; i <= height / 2 + 1; i++) {
        if (!(map[topX - i][topY + i] && map[topX + i][topY + i]))
            return false;
    }
    for (int i = height / 2 + 2; i <= height; i++) {
        int offset = height + 1 - i;
        if (!(map[topX - offset][topY + i] && map[topX + offset][topY + i])) 
            return false;
    }
    // 3. check inside
    for (int i = 1; i <= height / 2 + 1; i++) {
        if (sum[topY + i][topX + i] - sum[topY + i][topX - i] != 1) return false;
    }
    for (int i = height / 2 + 2; i <= height; i++) {
        int offset = height + 1 - i;
        if (sum[topY + i][topX + offset] - sum[topY + i][topX - offset] != 1) return false;
    }
    return true;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch; std::cin >> ch;
            map[j][i] = ch == '#';
            if (ch == '#') {
                sum[i][j] = sum[i][j-1] + 1;
            } else {
                sum[i][j] = sum[i][j-1];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[j][i] && check2(j, i)) ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

