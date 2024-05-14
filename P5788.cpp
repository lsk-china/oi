//
// Created by lsk on 5/13/24.
//
#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::stack<int> stack;
    int *input = (int *) malloc(sizeof(int) * n);
    int *ans = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }
    for (int i = n-1; i >= 0; i--) {
        while (!stack.empty() && input[stack.top()] <= input[i]) stack.pop();
        ans[i] = stack.empty() ? 0 : stack.top() + 1;
        stack.push(i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    free(input);
    free(ans);
    return 0;
}