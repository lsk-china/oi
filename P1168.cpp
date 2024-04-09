#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>

int main() {
    std::priority_queue<int, std::vector<int>, std::less<int>> ql;
    int n, v, leftSize=1, rightSize=0, rightSmallest = 2147483647;
    scanf("%d", &v);
    scanf("%d", &n);
    ql.push(v);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &v);
        if (v < rightSmallest && (leftSize - rightSmallest) == 1) {
            ql.push(v);
            leftSize ++;
        } else {
            rightSmallest = v;
            rightSize ++;
        }
        if (i % 2 == 1) {
            printf("%d\n", ql.top());
        }
    }
    return 0;
}