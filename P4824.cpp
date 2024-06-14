//
// Created by lsk on 5/22/24.
//
#include <iostream>
#include <stack>
#include <vector>

#define int long long
#define MAX 1000001
int p=1e9+7,mod=998244353;
int q[MAX] = {0}, stackHash[MAX] = {0}, rsp = 0;
char stack[MAX] = {0};

signed main() {
    std::string source; std::cin >> source;
    std::string remove; std::cin >> remove;
    int lenSource = source.length();
    int lenRemove = remove.length();
    q[0] = 1;
    for (int i = 1; i <= lenSource; i++)
        q[i] = q[i-1]*p%mod;
    int hashRemove = 0;
    for (int i = lenRemove - 1; i >= 0; i--) hashRemove = (hashRemove + remove[i] * q[i] % mod) % mod;
    for (int i = lenSource - 1; i >= 0; i--) {
        stack[++rsp] = source[i];
        stackHash[rsp] = (stackHash[rsp-1] + stack[rsp] * q[rsp] % mod) % mod;
        if (rsp > lenRemove) {
            int check = (stackHash[rsp] - stackHash[rsp - lenRemove] + mod) % mod;
            if (check == q[rsp - lenRemove] * hashRemove % mod)
                rsp -= lenRemove;
        }
    }
    while (rsp > 0) {
        std::cout << stack[rsp]; rsp--;
    }
    return 0;
}