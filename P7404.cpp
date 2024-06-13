//
// Created by lsk on 6/12/24.
//
#include <iostream>

#define MAX 200010

int len = 0;
int diff[MAX] = {0}, input[MAX] = {0};

int main() {
    std::cin >> len;
    for (int i = 1; i <= len; i++) std::cin >> input[i];
    for (int i = 1; i <= len; i++) diff[i] = input[i] - input[i-1];
    int left = 1, right = len;
    long long ans = 0;
    while (left < right) {
        while (diff[left] > 0) left++;
        while (diff[right] < 0) right-- ;
        if (left > right) break;
        int d = std::min(1 - diff[left], diff[right] + 1);
        diff[left] += d;
        diff[right] -= d;
        ans += d;
    }
    printf("%lld\n", ans);
    return 0;
}