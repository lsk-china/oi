//
// Created by lsk on 6/18/24.
//
#include <iostream>
#include <map>
#include <algorithm>
#define MAX 100010

long long cows[MAX] = {0};

int main() {
    int n, k; std::cin >> n >> k;
    std::map<long long, int> idHash;
    int brandCount = 0;
    for (int i = 1; i <= n; i++) {
        long long id; std::cin >> id;
        if (idHash[id] == 0) idHash[id] = brandCount++;
        cows[i] = idHash[id];
    }
    idHash.clear();
    int left = 1, right = 0, ans = 0, opts = k, brandsIn = 0;
//    for (int i = 1; i <= n; i++) {
//        long long beginBrandId = cows[i];
//        while () {
//            long long thisBrandId = cows[right];
//            if (thisBrandId != beginBrandId) opts--;
//            right++;
//        }
//        ans = ans > (right - i) ? (right - i) : ans;
//        if (i != n-1 && cows[i+1] != beginBrandId) opts++;
//    }
    while (right <= n) {
        right++;
        if (idHash[cows[right]] == 0) brandsIn++;
        while (brandsIn == k+2) {
            idHash[cows[left]] --;
            if (idHash[cows[left]] == 0) brandsIn--;
            left++;
        }
        ans = idHash[cows[right]] > ans ? idHash[cows[right]] : ans;
    }
    printf("%d\n", ans);
    return 0;
}