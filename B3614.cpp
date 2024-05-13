//
// Created by lsk on 5/13/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int opts; scanf("%d", &opts);
    int *rbp = (int *) malloc(sizeof(int) * opts);
    int rsp = 0;
    for (int i = 0; i < opts; i++) {
        char c;
        do { c = getchar(); } while (c != 0);
    }
    free(rbp);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) solve();
    return 0;
}