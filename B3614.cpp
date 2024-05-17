//
// Created by lsk on 5/13/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void solve() {
    int opts; scanf("%d", &opts);
    unsigned long long *rbp = (unsigned long long *) malloc(sizeof(unsigned long long) * opts);
    int rsp = 0;
    for (int i = 0; i < opts; i++) {
        char *line; size_t len; getline(&line, &len, stdin);
        if (line[0] == 'p' && line[1] == 'u') {
            int datIndex = str;
        }
    }
    free(rbp);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) solve();
    return 0;
}