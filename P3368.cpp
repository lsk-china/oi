//
// Created by lsk on 6/11/24.
//
#include <iostream>
#define lowbit(a) (a & (-a))
#define MAX 500010

int treearr[MAX] = {0}, input[MAX] = {0};
int len = 0;

void update(int i, int d) {
    while (i <= len) {
        treearr[i] += d;
        i += lowbit(i);
    }
}

int query(int i) {
    int result = 0;
    while (i > 0) {
        result += treearr[i];
        i -= lowbit(i);
    }
    return result;
}

int main() {
    int optCount; std::cin >> len >> optCount;
    input[0] = 0;
    for (int i = 1; i <= len; i++) std::cin >> input[i];
    for (int i = 1; i <= len; i++) {
        update(i, input[i]-input[i-1]);
    }
    for (int i = 0; i < optCount; i++) {
        int opt; std::cin >> opt;
        if (opt == 1) {
            int x, y, d; std::cin >> x >> y >> d;
            update(x, d);
            update(y+1, -d);
        } else {
            int index; std::cin >> index;
            printf("%d\n", query(index));
        }
    }
    return 0;
}