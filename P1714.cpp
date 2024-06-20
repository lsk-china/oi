//
// Created by lsk on 6/20/24.
//
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 500010

int input[MAX] = {0}, sum[MAX] = {0};

int main() {
    int n, m; std::cin >> n >> m;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int a; std::cin >> a;
        sum[i] = a+sum[i-1];
    }
    long long ans = 0;
    std::deque <int> queue;
    queue.push_back(0);
    for (int i = 1; i <= n; i++) {
//        for (int j = i; j >= 1; j--) {
//            if (i + 1 - j > m) break;
//            if (sum[i + 1] - sum[j] > ans) {
//                ans = sum[i + 1] - sum[j];
//            }
//        }
        while ((!queue.empty()) && (i + 1 - queue.front() > m)) queue.pop_front();
        while ((!queue.empty()) && (sum[queue.back()] >= sum[i])) queue.pop_back();
        queue.push_back(i);
        int newAns = sum[i]  - sum[queue.front()];
        ans = newAns > ans ? newAns : ans;
    }
    printf("%lld", ans);
    return 0;
}