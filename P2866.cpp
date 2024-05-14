//
// Created by lsk on 5/14/24.
//
#include <iostream>
#include <cstdlib>
#include <stack>

int main() {
    int n; std::cin >> n;
    int *inp = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) std::cin >> inp[i];
    int ans = 0;
    std::stack<int> stack;
    for (int i = 0; i < n; i++) {
        while ((!stack.empty()) && (stack.top() <= inp[i])) stack.pop();
        ans += stack.size();
        stack.push(inp[i]);
    }
    printf("%d\n", ans);
    free(inp);
    return 0;
}
