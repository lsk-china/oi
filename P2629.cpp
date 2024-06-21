//
// Created by lsk on 6/21/24.
//
#include <iostream>
#include <queue>
#include <cstring>

#define MAX 2000020

int input[MAX] = {0};
int sum[MAX] = {0};

int main() {
    int n; std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> input[n];
    memcpy(input, input+n, sizeof(int) * (n-1));
    for (int i = 1; i <= n * 2 - 1; i++)
        sum[i] = sum[i-1] + input[i];
    std::deque<int> queue;
    long long ans = 0;
    queue.push_back(0);
    for (int i = 1; i <= n; i++) {
        while((!queue.empty()) && (sum[queue.back()] < sum[i])) queue.pop_back();
        queue.push_back(i);
    }
    return 0;
}