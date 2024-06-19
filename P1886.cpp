//
// Created by lsk on 6/19/24.
//
#include <iostream>
#include <queue>

#define MAX 1000010

int input[MAX] = {0};

int main() {
    std::ios::sync_with_stdio(false);
    int len, k; std::cin >> len >> k;
    for (int i = 1; i <= len; i++) std::cin >> input[i];
    std::deque<int> queue;
    for (int i = 1; i <= len; i++) {
        while ((!queue.empty()) && (queue.front() + k <= i))
            queue.pop_front();
        while ((!queue.empty()) && (input[queue.back()] > input[i]))
            queue.pop_back();
        queue.push_back(i);
        if (i >= k)
            printf("%d ", input[queue.front()]);
    }
    queue.clear();
    printf("\n");
    for (int i = 1; i <= len; i++) {
        while ((!queue.empty()) && (queue.front() + k <= i))
            queue.pop_front();
        while ((!queue.empty()) && (input[queue.back()] < input[i]))
            queue.pop_back();
        queue.push_back(i);
        if (i >= k)
            printf("%d ", input[queue.front()]);
    }
    printf("\n");
    return 0;
}