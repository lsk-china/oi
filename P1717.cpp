#include <cstdio>
#include <queue>
#include <cstdlib>

struct lake {
    int fishNum;
    int dec;
    int timeCost = 0;
};

bool operator<(struct lake lake1, struct lake lake2) {
    return lake1.fishNum < lake2.fishNum;
}

#define PQ std::priority_queue<struct lake>

int main() {
    int n, time; 
    scanf("%d", &n); scanf("%d", &time); time *= 12;
    struct lake * lakes = (struct lake *) malloc(sizeof(struct lake) * n);
    // PQ queue;
    for (int i = 0; i < n; i++) {
        scanf("%d", &lakes[i].fishNum);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &lakes[i].dec);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d", &lakes[i].timeCost);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        PQ lakeQueue;
        int timeAvailable = time;
        for (int j = 0; j < i; j++) {
            lakeQueue.push(lakes[j]);
            timeAvailable -= lakes[j].timeCost;
        }
        int ans2 = 0;
        for (int j = timeAvailable; j > 0; j--) {
            lake top = lakeQueue.top(); lakeQueue.pop();
            if (top.fishNum <= 0) {
                break;
            }
            ans2 += top.fishNum;
            top.fishNum -= top.dec;
            lakeQueue.push(top);
        }
        ans = ans2 > ans ? ans2 : ans;
    }
    free(lakes);
    printf("%d\n", ans);
    return 0;
}
