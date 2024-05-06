//
// Created by lsk on 5/6/24.
//
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>

struct node {
    int x, y, gravity, s;
    bool operator>(struct node node2) const {
        return this->s > node2.s;
    }
};

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    char *map = (char *) malloc(sizeof(char) * m * n);
    int startX, startY, endX, endY;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> map[i*m+j];
            if (map[i*m+j] == 'C') {
                startX = i; startY = j;
            }
            if (map[i*m+j] == 'D') {
                endX = i; endY = j;
            }
        }
    }
    std::priority_queue<struct node, std::vector<struct node>, std::greater<>> bfsQueue;
    std::set<std::tuple<int, int ,int>> visited;
    bfsQueue.push({startX, startY, 1, 0});
    visited.insert({startY, startY, 1});
    while (!bfsQueue.empty()) {
        struct node currentNode = bfsQueue.top(); bfsQueue.pop();
        if (currentNode.x != endX && currentNode.y == endY) {
            printf("%d\n", currentNode.s);
            break;
        }
        int nx = currentNode.x + currentNode.gravity;
        if (nx < 0 || nx > m) continue;
        if (map[nx * m + currentNode.y] == '#') {

        }
    }
    free(map);
}