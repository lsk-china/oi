//
// Created by lsk on 4/12/24.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

struct step {
    std::string status;
    int zeroPos;
    int distance;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    std::string goal = "123804765";
    std::string initState;
    std::cin >> initState;
    std::deque<struct step> queue;
    struct step initialStep = {
            initState,
            static_cast<int>(initState.find('0')),
            0
    };
    std::set<std::string> set;
    queue.push_back(initialStep);
    set.insert(initialStep.status);
    int ans = 0;
    while(!queue.empty()) {
        struct step thisStep = queue.front(); queue.pop_front();
        if (thisStep.status == goal) {
            ans = thisStep.distance;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = thisStep.zeroPos % 3 + dx[i];
            int y = thisStep.zeroPos / 3 + dy[i];
            if (x > 2 || x < 0 || y > 2 || y < 0) {
                continue;
            }
            int zeroPos = y*3+x;
            std::string state = thisStep.status;
            std::swap(state[thisStep.zeroPos], state[zeroPos]);
            if (set.contains(state)) { continue; }
            set.insert(state);
            struct step newStep = {
                    state,
                    zeroPos,
                    thisStep.distance+1
            };
            queue.push_back(newStep);
        }
    }
    printf("%d\n", ans);
    return 0;
}