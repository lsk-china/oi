//
// Created by lsk on 6/11/24.
//
#include <iostream>
#include <cstdlib>

#define MAX 50010

int left[7] = {0}, right[7] = {0}, sum[MAX] = {0};

int main() {
    int n = 0; std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> sum[i];
        sum[i] = (sum[i] + sum[i-1]) % 7;
    }
    for (int i = n; i >= 1; i--) {
        left[sum[i]] = i;
    }
    left[0] = 0;
    for (int i = 1; i <= n; i++) {
        right[sum[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        int len = right[i] - left[i];
        ans = len > ans ? len : ans;
    }
    printf("%d\n", ans);
    return 0;
}