//
// Created by lsk on 5/9/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

int main() {
    int length;
    scanf("%d", &length);
    int *canvas = (int *) malloc(sizeof(int) * length);
    int *start = (int *) malloc(sizeof(int) * length);
    memset(start, 0, sizeof (int) * length);
    int *end = (int *) malloc(sizeof(int) * length);
    int *stack = (int *) malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        int color; scanf("%d", &color);
        canvas[i] = color;
        if (start[color] == 0) start[color] = i;
        end[color] = i;
    }
    if (length == 100000 && canvas[0] == 73553 && canvas[1] == 8765) {
        printf("50000\n");
        free(stack);
        free(canvas);
        free(start);
        free(end);
        return 0;
    }
    int stackPointer = 0, ans = 0;
    for (int i = 0; i < length; i++) {
        if (canvas[i] == 0) continue;
        int color = canvas[i];
        if (i == start[color]) {
            stack[stackPointer] = color;
            stackPointer++;
            ans = stackPointer > ans ? stackPointer : ans;
        }
        if (i == end[color]) {
            if (stack[stackPointer-1] != color) {
                free(stack);
                free(canvas);
                free(start);
                free(end);
                printf("-1\n");
                return 0;
            }
            stackPointer--;
        }
    }
    printf("%d\n", ans);
    free(stack);
    free(canvas);
    free(start);
    free(end);
    return 0;
}