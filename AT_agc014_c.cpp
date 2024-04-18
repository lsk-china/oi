//
// Created by lsk on 4/18/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>

int height, width, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct point {
    int x, y;
    int distance;
    char state;
};

int min(int a, int b, int c, int d) {
    return std::min(std::min(std::min(a, b), c), d);
}

bool operator<(struct point p1, struct point p2) {
    int distance1 = min(p1.x, p1.y, height - p1.x, width - p1.y);
    int distance2 = min(p2.x, p2.y, height - p2.x, width - p2.y);
    return distance1 < distance2;
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
            char ch = getchar();
            if (ch == '\n') { ch = getchar(); }
            map[i*height+j] = ch;
            if (ch == 'S') {
                beginPoint = {i, j, 0, ch};
                visited[i*height+j] = true;
            }
        }
    }
    std::priority_queue<struct point, std::vector<struct point>, std::less<struct point>> bfsQueue;
    bfsQueue.push(beginPoint);
    while (bfsQueue.size() > 1) {
        struct point currentPoint = bfsQueue.top();
        if (currentPoint.distance > k) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int newX = currentPoint.x + dx[i];
            int newY = currentPoint.y + dy[i];
            if (newX < 0 || newX > height || newY < 0 || newY > width) { continue; }
            if (visited[newX*height+newY]) { continue; }
            if (map[newX*height+newY] == '#') { continue; }
            struct point newPoint = {newX, newY, currentPoint.distance + 1, '.'};
            bfsQueue.push(newPoint);
        }
    }
    printf("1\n");
    struct point nearestPoint = {0};
    do {
        nearestPoint = bfsQueue.top();
        bfsQueue.pop();
    } while (nearestPoint.distance <= k);
    int rounds = 1;
    int distance = min(nearestPoint.x, nearestPoint.y, height - nearestPoint.x, width - nearestPoint.y);
    rounds += distance % k == 0 ? distance / k : (distance / k) + 1;
    printf("%d\n", rounds);
    free(visited);
    free(map);
    return 0;
}