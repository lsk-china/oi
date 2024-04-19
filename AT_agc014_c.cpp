//
// Created by lsk on 4/18/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>

int height, width, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct point {
    int x, y;
    int distance;
};

int min(int a, int b, int c, int d) {
    return std::min(std::min(std::min(a, b), c), d);
}

int distance(struct point p) {
    return min(p.x, p.y, height - p.x, width - p.y);
}

int main() {
    scanf("%d %d %d", &height, &width, &k);
    fflush(stdin);
    struct point beginPoint = {0};
    char* map = (char *) malloc(sizeof(char) * height * width);
    bool *visited = (bool*) malloc(sizeof (bool) * height * width);
    memset(visited, false, sizeof(bool) * height * width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char ch;
            std::cin >> ch;
            map[i*height+j] = ch;
            if (ch == 'S') {
                beginPoint = {i, j, 0};
                visited[i*height+j] = true;
            }
        }
    }
    std::queue<struct point> bfsQueue;
    bfsQueue.push(beginPoint);
    struct point nearestPoint = beginPoint;
    do {
        struct point currentPoint = bfsQueue.front(); bfsQueue.pop();
        nearestPoint = distance(currentPoint) < distance(nearestPoint) ? currentPoint : nearestPoint;
        if (currentPoint.distance == k) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int newX = currentPoint.x + dx[i];
            int newY = currentPoint.y + dy[i];
            if (map[newX*height+newY] != '.') { continue; }
            if (newX < 0 || newX > height || newY < 0 || newY > width) { continue; }
            if (visited[newX*height+newY]) { continue; }
            struct point newPoint = {newX, newY, currentPoint.distance + 1};
            bfsQueue.push(newPoint);
        }
    } while (!bfsQueue.empty());
    int rounds = 1;
    int d = distance(nearestPoint);
    rounds += d % k == 0 ? d / k : (d / k) + 1;
    printf("%d\n", rounds);
    free(visited);
    free(map);
    return 0;
}