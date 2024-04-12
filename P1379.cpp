//
// Created by lsk on 4/12/24.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

struct step {
    char *status;
    int zeroPos;
    int distance;
};

int main() {
    char* goal = "123804765";
    char initState[9];
    scanf("%s", initState);
    std::deque<struct step> queue;


}