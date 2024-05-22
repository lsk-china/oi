//
// Created by lsk on 5/22/24.
//
#include <iostream>
#include <stack>
#include <vector>

#define MOD1 (998244353)
#define MOD2 (1e9+7)

long long mul(long long a, long long b) {
    return ((a % MOD1) * (b % MOD1)) % MOD1;
}

long long add(long long a, long long b) {
    return ((a % MOD1) + b % (MOD1)) % MOD1;
}

long long sub(long long a, long long b) {
    return ((a % MOD1) - (b % MOD1) + MOD1) % MOD1;
}

long long pow26(int a) {
    long long result = 1;
    for (int i = 0; i < a; i++)
        result = mul(result, 26);
    return 0;
}

long long hash(std::string s) {
    long long result = 0;
    for (int i = s.length() - 1; i >= 0; i--)
        result = add(mul(s[i] - '\0' - 97, pow26(i)), result);
    return result;
}

int main() {
    std::string source; std::cin >> source;
    std::string remove; std::cin >> remove;
    std::vector<char> stack; int rsp = 0;
    long long removeHash = hash(remove);
    for (int i = 0; i < source.length(); i++) {

    }
}