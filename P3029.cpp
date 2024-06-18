//
// Created by lsk on 6/13/24.
//
#include <iostream>
#include <map>
#include <algorithm>
#define MAX 50010

struct cow {
    int id, pos;
    bool operator<(const cow &cow1) {
        return this->pos < cow1.pos;
    }
};

std::map<int, int> idHash;
struct cow cows[MAX] = {0};

int main() {
    int n, brands = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> cows[i].pos >> cows[i].id;
        if (!idHash.contains(cows[i].id)) {
            brands ++;
            idHash[cows[i].id] = 1;
        }
    }
    std::sort(cows+1, cows+1+n);
    idHash.clear();
    int right = 1, brandsInRegion = 1, ans = 2147483647;
    idHash[cows[1].id] = 1;
    for (int i = 1; i <= n; i++) {
        while (brandsInRegion < brands && right < n) {
            right++;
            idHash[cows[right].id] ++;
            if (idHash[cows[right].id] == 1) {
                brandsInRegion++;
            }
        }
        if (brandsInRegion == brands) {
            int newAns = cows[right].pos - cows[i].pos;
            ans = newAns < ans ? newAns : ans;
        }
        idHash[cows[i].id] --;
        if (idHash[cows[i].id] == 0) brandsInRegion--;
    }
    printf("%d\n", ans);
    return 0;
}