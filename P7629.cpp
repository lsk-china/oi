//
// Created by lsk on 6/3/24.
//
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define lowbit(a) (a & (-a))

void update(int *treearr, int len, int index, int d) {
    while (index <= len) {
        treearr[index] += d;
        index += lowbit(index);
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
    int len; std::cin >> len;
    int *sequence = (int *) malloc(sizeof(int) * len + 1);
    for (int i = 1; i <= len; i++) std::cin >> sequence[i];
    int l = 1, r = 1;
    long long ans = 0;
    while (l <= len) {
        r++;
        if (r == len + 1 || sequence[r-1] < sequence[r]) {
            if (r - 1 -l > 0) {
                std::reverse(sequence+l, sequence+r);
                ans++;
            }
            l = r;
        }
    }
    int *treearr = (int *) malloc(sizeof(int) * len + 1);
    memset(treearr, 0, sizeof(int) * len + 1);
    for (int i = len; i >= 1; i--) {
        ans += query(treearr, sequence[i]);
        update(treearr, len, sequence[i], 1);
    }
    printf("%lld\n", ans);
    free(treearr);
    free(sequence);
    return 0;
}