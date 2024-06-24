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
    for (int i = 1; i <= n; i++) std::cin >> input[i];
    for (int i = n+1; i <= 2*n-1; i++) input[i] = input[i-n];
    for (int i = 1; i <= n * 2 - 1; i++) sum[i] = sum[i-1] + input[i];
    std::deque<int> queue;
    long long ans = 0;
    for (int k = 1; k <= 2*n-1; k++) {
        while((!queue.empty()) && (queue.front() < k-n+1)) queue.pop_front();
        while((!queue.empty()) && (sum[k] < sum[queue.back()])) queue.pop_back();
        queue.push_back(k);
        if (k-n >= 0 && sum[queue.front()] - sum[k - n] >= 0) ans++;
    }
    printf("%lld", ans);
    return 0;
}