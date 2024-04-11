//
// Created by lsk on 4/10/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

#define pii std::pair<int, int>
#define mkpii(a, b) std::make_pair(a, b)

struct wheel {
    int x, y, radius;
    bool direction;
    pii vel;
    int id;
};

pii simplify(pii frac) {
    int a = frac.first;
    int b = frac.second;
    int gcd = std::__gcd(a, b);
    return mkpii(a / gcd, b / gcd);
}

pii speed(struct wheel master, struct wheel slave) {
    int a = master.vel.first * master.radius;
    int b = master.vel.second * slave.radius;
    return simplify(mkpii(a, b));
}

int square(int a) {
    return a*a;
}

bool intersect(struct wheel wheel1, struct wheel wheel2) {
    int a = square(wheel1.radius + wheel2.radius);
    int b = square(wheel1.x - wheel2.x) + square(wheel1.y - wheel2.y);
    return a == b;
}

void solve() {
    int wheelAmount;
    scanf("%d", &wheelAmount);
    bool* visited = (bool*) malloc(sizeof (bool) * wheelAmount);
    memset(visited, false, sizeof (bool ) * wheelAmount);
    struct wheel* wheels = (struct wheel *) malloc(sizeof (struct wheel) * wheelAmount);
    for (int i = 0; i < wheelAmount; i++) {
        scanf("%d %d %d", &wheels[i].x, &wheels[i].y, &wheels[i].radius);
        wheels[i].id = i;
    }
    wheels[0].vel = mkpii(1, 1);
    wheels[0].direction = true; // clockwise
    std::queue<struct wheel> queue;
    queue.push(wheels[0]); visited[0] = true;
    while(!queue.empty()) {
        struct wheel top = queue.front(); queue.pop();
        for (int i = 0; i < wheelAmount; i++) {
            struct wheel &thisWheel = wheels[i];
            if (!visited[i] && intersect(top, thisWheel)) {
                visited[i] = true;
                thisWheel.vel = speed(  top, thisWheel);
                thisWheel.direction = ! top.direction;
                queue.push(thisWheel);
            }
        }
    }
    for (int i = 0; i < wheelAmount; i++) {
        if (visited[i]) {
            if (wheels[i].vel.second == 1) {
                printf("%d %s\n", wheels[i].vel.first, wheels[i].direction ? "clockwise" : "counterclockwise");
            } else {
                printf("%d/%d %s\n", wheels[i].vel.first, wheels[i].vel.second, wheels[i].direction ? "clockwise" : "counterclockwise");
            }
        } else {
            printf("not moving\n");
        }
    }
    free(visited);
    free(wheels);
}

int main() {
    int tasks;
    scanf("%d", &tasks);
    for (int i = 0; i < tasks; i++) {
        solve();
    }
    return 0;
}