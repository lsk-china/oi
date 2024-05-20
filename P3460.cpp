//
// Created by lsk on 5/16/24.
//
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cstring>

int main() {
    int n; std::cin>>n;
    int *vis = (int *) malloc(sizeof(int) * n);
    int *ans = (int *) malloc(sizeof(int) * n);
    int *rbp = (int *) malloc(sizeof(int) * 2 *n);
    std::stack<int> swap;
    int ansCount, rsp = 0;
    for (int i = 0; i < 2*n; i++){
        int a; std::cin >> a;
        rbp[rsp] = a; rsp++;
    }
    for (int i = 0; i < n; i++) {
        if (vis[rbp[i]]) {
            while (rbp[rsp] != rbp[i]) {
                swap.push(rbp[rsp]); rsp--;
                ans[++ansCount] = rsp;
            }
            rsp--;
            while (!swap.empty()) {
                rsp++;
                rbp[rsp] = swap.top();
                swap.pop();
            }
        } else {
            vis[rbp[i]] = 1;
        }
    }
    printf("%d\n", ansCount);
    for (int i = 0; i < ansCount; i++) printf("%d\n", ans[i]);
    free(rbp);
    free(ans);
    free(vis);
    return 0;
}