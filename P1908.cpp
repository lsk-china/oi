//
// Created by lsk on 5/29/24.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define lowbit(a) (a & -a)

struct num {
    int val;
    int i;
};

void update(int *treearr, int len, int i, int d) {
    while (i <= len) {
        treearr[i] += d;
        i += lowbit(i);
    }
}

int query(int *treearr, int i) {
    int result = 0;
    while (i > 0) {
        result += treearr[i];
        i -= lowbit(i);
    }
    return result;
}

int main() {
    int n; std::cin >> n;
//    struct num *vals = (struct num*) malloc(sizeof(struct num) * (n+1));
//    int *indexes = (int *) malloc(sizeof(int) * (n+1));
//    int *treearr = (int *) malloc(sizeof(int) * (n+1));
    struct num vals[7] = {0};
    int indexes[7] = {0};
    int treearr[7] = {0};
    // memset(treearr, 0, sizeof(int) * n);
    for (int i = 1; i <= n; i++) {
        std::cin >> vals[i].val;
        vals[i].i = i;
    }
    std::sort(vals+2, vals+n+2, [](struct num n1, struct num n2) {
        return n1.val == n2.val ? n1.i < n2.i : n1.val < n2.val;
    });
    for (int i = 1; i <= n; i++) {
        indexes[i] = vals[i].i;
    }
    long long ans = 0;
    for (int i = 1; i < n+1; i++) {
        update(treearr, n, indexes[i], 1);
        ans += query(treearr, indexes[i]);
    }
    printf("%lld", ans);
//    free(vals);
//    free(treearr);
//    free(indexes);
    return 0;
}
