//
// Created by lsk on 4/11/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

#define pii std::pair<int, int>
#define mkpii(a, b) std::make_pair(a-1, b-1)
#define out(point) !(point.first < 0 || point.first > n || point.second < 0 || point.second > m)
#define index(point) (point.first * n + point.second)

/*
 *  * 8 * 1 *
 *  7 * * * 2
 *  * * p * *
 *  6 * * * 3
 *  * 5 * 4 *
 */
#define position1(x, y) mkpii(x+1, y-2)
#define position2(x, y) mkpii(x+2, y-1)
#define position3(x, y) mkpii(x+2, y+1)
#define position4(x, y) mkpii(x+1, y+2)
#define position5(x, y) mkpii(x-1, y+2)
#define position6(x, y) mkpii(x-2, y+1)
#define position7(x, y) mkpii(x-2, y-1)
#define position8(x, y) mkpii(x-1, y-2)

int main () {
    int n, m, initialX, initialY;
    scanf("%d %d %d %d", &n, &m, &initialX, &initialY);
    std::queue<pii> points;
    int *distances = (int *) malloc(sizeof (int) * n * m);
    memset(distances, -1, sizeof(int) * n * m);
    distances[index(mkpii(initialX, initialY))] = 0;
    points.push(mkpii(initialX, initialY));
    while (!points.empty()) {
        pii top = points.front(); points.pop();
        int x = top.first, y = top.second;
        if (distances[index(position1(x, y))] == -1 && out(position1(x, y))) { // 1
            distances[index(position1(x, y))] = distances[index(top)] + 1;
            points.push(position1(x, y));
        }
        if (distances[index(position2(x, y))] == -1 && out(position2(x, y))) { // 2
            distances[index(position2(x, y))] = distances[index(top)] + 1;
            points.push(position2(x, y));
        }
        if (distances[index(position3(x, y))] == -1 && out(position3(x, y))) { // 3
            std::cout << position3(x,y).first <<  " " << position3(x,y).second << " " << index(position3(x, y)) << std::endl;

            distances[index(position3(x, y))] = distances[index(top)] + 1;
            points.push(position3(x, y));
        }
        if (distances[index(position4(x, y))] == -1 && out(position4(x, y))) { // 4
            distances[index(position4(x, y))] = distances[index(top)] + 1;
            points.push(position4(x, y));
        }
        if (distances[index(position5(x, y))] == -1 && out(position5(x, y))) { // 5
            distances[index(position5(x, y))] = distances[index(top)] + 1;
            points.push(position5(x, y));
        }
        if (distances[index(position6(x, y))] == -1 && out(position6(x, y))) { // 6
            distances[index(position6(x, y))] = distances[index(top)] + 1;
            points.push(position6(x, y));
        }
        if (distances[index(position7(x, y))] == -1 && out(position7(x, y))) { // 7
            distances[index(position7(x, y))] = distances[index(top)] + 1;
            points.push(position7(x, y));
        }
        if (distances[index(position8(x, y))] == -1 && out(position8(x, y))) { // 8
            distances[index(position8(x, y))] = distances[index(top)] + 1;
            points.push(position8(x, y));
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", distances[i*n+j]);
        }
        printf("\n");
    }
    free(distances);
    return 0;
}