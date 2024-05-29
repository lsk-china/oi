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

int main() {
    int n; std::cin >> n;
    struct num *vals = (struct num*) malloc(sizeof(struct num) * n);
    for (int i = 0; i < n; i++) {
        std::cin >> vals[i].val;
        vals[i].i = i;
    }
    std::sort(vals+1, vals+n+1, [](struct num n1, struct num n2) {
        return n1.val == n2.val ? n1.i < n2.i : n1.val < n2.val;
    });
    for (int i = 0; i < n; i++) {
    }
    free(vals);
    return 0;
}
