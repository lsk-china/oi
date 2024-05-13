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
    int *result = (int *) malloc(sizeof(int) * n);
    int *input = (int *) malloc(sizeof(int) * n);
    memset(result, 0, sizeof(int) * n);
    int *stack = (int *) malloc(sizeof(int) * n);
    int rsp = 0;
    for (int i = 0; i < n; i++) std::cin >> input[i];
    for (int i = n - 1; i >= 0; i--) {
        int a = input[i];
        while (rsp > 0 && a > input[stack[rsp]]) rsp--;
        result[i] = stack[rsp];
        rsp ++;
        stack[rsp] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i] == 0 ? 0 : result[i] + 1);
    }
    printf("\n");
    free(result);
    free(stack);
    free(input);
    return 0;
}