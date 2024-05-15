//
// Created by lsk on 5/15/24.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>

int main() {
    int n; std::cin >> n;
    int *inp = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) std::cin >> inp[i];
    std::stack<int> stack;
    int ans;
    for (int i = 0; i < n; i++) {
        if (!stack.empty() && stack.top() <= inp[i]) {
            ans = ans > stack.size() ? ans : stack.size();
            stack = std::stack<int>();
            if (ans > (n/2)) break;
        }
        stack.push(inp[i]);
    }
    free(inp);
    return 0;
}