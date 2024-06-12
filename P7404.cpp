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
    int ans = 0, left = 1, right = len;
    while (left < right) {
        while (diff[left] > 0) left++;
        while (diff[right] < 0) right-- ;
        if (left < right) break;
        diff[left] += 1;
        diff[right] -= 1;
        ans ++;
    }
    printf("%d\n", ans);
    return 0;
}