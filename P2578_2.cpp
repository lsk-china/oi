#include <iostream>
#include <unordered_map>
#include <queue>

struct node {
    char a[10];
    int step;

    int calc() {
        int s = 0;
        for (int i = 1; i <= 9; ++i)
            s = s * 10 + a[i] - '0';
        return s;
    }
};

node op1(node x) {
    node y = x;
    y.a[0] = y.a[3];
    y.a[3] = y.a[2];
    y.a[2] = y.a[1];
    y.a[1] = y.a[4];
    y.a[4] = y.a[7];
    y.a[7] = y.a[8];
    y.a[8] = y.a[9];
    y.a[9] = y.a[6];
    y.a[6] = y.a[0];
    return y;
}

node op2(node x) {
    node y = x;
    y.a[0] = y.a[6];
    y.a[6] = y.a[5];
    y.a[5] = y.a[4];
    y.a[4] = y.a[0];
    return y;
}

void printPath(int i) {
    // TODO
}

int parent[500010] = {0};
struct node nodes[500010] = {0};

int main() {
    struct node initState = {0};
    for (int i = 0; i < 9; i++) {
        std::cin >> initState.a[i];
    }
    nodes[1] = initState;
    initState.step = 0;
    parent[1] = 0;
    std::unordered_map<int, bool> visited;
    std::queue<struct node> bfsQueue;
    visited[initState.calc()] = true;
    bfsQueue.push(initState);
    while (!bfsQueue.empty()) {
        struct node currentNode = bfsQueue.front();
        if (currentNode.calc() == 123456789) {
            printPath(currentNode.calc());
        }
    }

}