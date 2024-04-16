//
// Created by lsk on 4/16/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

struct point {
    int x, y, s;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool operator==(struct point point1, struct point point2) { return point1.x == point2.x && point1.y == point2.y; }


int main () {
    int m, n, factories;
    scanf("%d %d %d", &m, &n, &factories);
    fflush(stdin);
    char* map = (char *) malloc(sizeof(char) * m * n);
    bool* visited = (bool *) malloc(sizeof(bool) * m * n);
    struct point* specialPoints = (struct point*) malloc(sizeof(struct point) * (factories + 1));
    std::queue<struct point> bfsQueue;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            scanf("%c", &ch);
            map[i*m+j] = ch;
            if (ch == 'S') {
                specialPoints[0] = {i, j, 0};
            }
            if (ch > '0' && ch <= '9') {
                specialPoints[ch-'\0'] = {i, j, 0};
            }
        }
    }
    int index = 0;
    int ans = 0;
    do {
        memset(visited, 0, sizeof(bool) * m * n);
        while(!bfsQueue.empty()) {
            bfsQueue.pop();
        }
        struct point beginPoint = specialPoints[index];
        struct point targetPoint = specialPoints[index + 1];
        visited[beginPoint.x * m + beginPoint.y] = true;
        bfsQueue.push(beginPoint);
        while (!bfsQueue.empty()) {
            struct point currentPoint = bfsQueue.front(); bfsQueue.pop();
            if (currentPoint == targetPoint) {
                ans += currentPoint.s;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int newX = currentPoint.x + dx[i];
                int newY = currentPoint.y + dy[i];
                if (newX > m || newX < 0 || newY > n || newY < 0) { continue; }
                if (visited[newX * m + newY]) { continue; }
                if (map[newX * m + newY] == 'X') { continue; }
                visited[newX * m + newY] = true;
                struct point newPoint = {newX, newY, currentPoint.s + 1};
                bfsQueue.push(newPoint);
            }
        }
    } while ((++index) < factories);
    printf("%d\n", ans);
    free(specialPoints);
    free(visited);
    free(map);
    return 0;
}