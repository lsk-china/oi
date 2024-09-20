#include <iostream>
#include <algorithm>
#include <map>

#define MAX 200002

std::map<int, long long> input;

int main() {
    int n; std::cin >> n;
    long long ans = 0, max = 0, k = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        int a; std::cin >> a;
        input[a]++;
        max = max < a ? a : max;
    }
    for (int i = 1; i <= m; i++) {
        for(; l < i*2 && l <= m; l++) k += input[l];
        ans += (input[i]-1) * input[i]
    }
}
