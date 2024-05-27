//
// Created by lsk on 5/23/24.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include<algorithm>

#define HASH1 212370440130137957ll
#define HASH2 1610612741
#define BASE 26
#define PRIME 233317

unsigned long long hash1(const char * s) {
    int len = strlen(s);
    unsigned long long result = 0;
    for (int i = 0; i < len; i++) {
        result = (result * BASE + (unsigned long long) s[i]) % HASH1 + PRIME;
    }
    return result;
}

unsigned long long hash2(char * s) {
    int len = strlen(s);
    unsigned long long result = 0;
    for (int i = 0; i < len; i++) {
        result = (result * BASE + (unsigned long long) s[i]) % HASH2 + PRIME;
    }
    return result;
}

int main() {
    int n; std::cin >> n;
    unsigned long long hashes1[10010] = {0};
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        hashes1[n] = hash1(s.c_str());
    }
    std::sort(hashes1+1, hashes1+n+1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (hashes1[i] == hashes1[i+1]) ans++;
    }
    printf("%d\n", ans);
}