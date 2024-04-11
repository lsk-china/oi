//
// Created by lsk on 4/11/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define pii std::pair<int, int>
#define mkpii(a, b) std::make_pair(a, b)

int main () {
    int n, m, initialX, initialY;
    scanf("%d %d %d %d", &n, &m, &initialX, &initialY);
    std::queue<pii> points;
    int *distances = (int *) malloc(sizeof (int) * n * m);
    distances[initialY*n+initialY] = 0;
    points.push(mkpii(initialY, initialY));
    while (!points.empty()) {
        pii top = points.front(); points.pop();


    }
    free(distances);
    return 0;
}