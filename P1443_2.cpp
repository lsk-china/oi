//
// Created by lsk on 4/17/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1 ,-2};

struct point {
    int x, y;
    int distance;
};

int main() {
    int n, m, initialX, initialY;
    scanf("%d %d %d %d", &n, &m, &initialX, &initialY);
    initialX -= 1; initialY -= 1;
    int*  distances = (int *) malloc(sizeof(int) * m * n);
    memset(distances, -1, sizeof(int) * m * n);
    std::queue<struct point> bfsQueue;
    bfsQueue.push({initialX, initialY, 0});
    distances[initialY*n+initialY] = 0;
    while (!bfsQueue.empty()) {
        struct point currentPoint = bfsQueue.front(); bfsQueue.pop();
        for (int i = 0; i < 8; i++) {
            int newX = currentPoint.x + dx[i];
            int newY = currentPoint.y + dy[i];
            if (distances[newX * n + newY] != -1) { continue; }
            if (newX < 0 || newX > n || newY < 0 || newY > m) { continue; }
            distances[newX * n + newY] = currentPoint.distance + 1;
            bfsQueue.push({newX, newY, currentPoint.distance + 1});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", distances[i*n+j]);
        }
        printf("\n");
    }
    free(distances);
    return 0;
}