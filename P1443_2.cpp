////
//// Created by lsk on 4/17/24.
////
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//
//int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dy[8] = {-2, -1, 1, 2, 2, 1, -1 ,-2};
//
//struct point {
//    int x, y;
//    int distance;
//};
//
//int main() {
//    int n, m, initialX, initialY;
//    scanf("%d %d %d %d", &n, &m, &initialX, &initialY);
//    int*  distances = (int *) malloc(sizeof(int) * (m+1) * (n+1));
//    memset(distances, -1, sizeof(int) * (m+1) * (n+1));
//    std::queue<struct point> bfsQueue;
//    bfsQueue.push({initialX, initialY, 0});
//    distances[initialY*n+initialY] = 0;
//    while (!bfsQueue.empty()) {
//        struct point currentPoint = bfsQueue.front(); bfsQueue.pop();
//        for (int i = 0; i < 8; i++) {
//            int newX = currentPoint.x + dx[i];
//            int newY = currentPoint.y + dy[i];
//            if (distances[newX * n + newY] != -1) { continue; }
//            if (newX < 0 || newX > n || newY < 0 || newY > m) { continue; }
//            distances[newX * n + newY] = currentPoint.distance + 1;
//            bfsQueue.push({newX, newY, currentPoint.distance + 1});
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            printf("%d ", distances[i*n+j]);
//        }
//        printf("\n");
//    }
//    free(distances);
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 505
#define pii(a, b) std::make_pair(a, b)

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1 ,-2};
int map[MAX][MAX] = {-1};
int visited[MAX][MAX] = {0};

int main() {
    int n, m, x, y; std::cin >> n >> m >> x >> y;
    memset(map, -1, MAX * MAX * sizeof (int));
    map[x][y] = 0;
    visited[x][y] = true;
    std::queue<std::pair<int, int>> bfsQueue;
    bfsQueue.push(pii(x, y));
    while (!bfsQueue.empty()) {
        std::pair<int, int> currentNode = bfsQueue.front();
        bfsQueue.pop();
        for (int i = 0; i < 8; i++) {
            std::pair newNode = pii(currentNode.first + dx[i], currentNode.second + dy[i]);
            if (newNode.first < 1 || newNode.second < 1 || newNode.first > n || newNode.second > m) continue;
            if (visited[newNode.first][newNode.second]) continue;
            visited[newNode.first][newNode.second] = true;
            map[newNode.first][newNode.second] = map[currentNode.first][currentNode.second] + 1;
            bfsQueue.push(newNode);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}