//
// Created by lsk on 5/8/24.
//
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <cstdlib>

int main() {
    std::string s;
    std::cin >> s;
    int len = s.length();

    std::stack<char> stack;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (stack.empty()) {
            if (c == ')') ans++;
            stack.push('(');
        } else {
            if (c == '(') stack.push('(');
            else {
                stack.pop();
            }
        }
    }
    printf("%d\n", ans+((int)stack.size() / 2));
    return 0;
}