#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>

int begins[100000] = {0};

int contribution(int thisBegin, int lastBegin, int nextBegin, int len) {
    int begin = lastBegin == -1 ? thisBegin     : std::min(lastBegin + m, thisBegin);
    int end =   nextBegin == -1 ? thisBegin + m : std::min(thisBegin + m, nextBegin);
    return (end - begin + 1);
}

int main() {
    int n, m; std::cin >> n >> m;
    for (int i = 0; i < n; i++) std::cin >> begins[i];
    sort(begins + 1, begins + n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += contribution(begins[i], (i == 0 ? -1 : begins[i-1]), (i == n-1 ? -1 : begins[i+1]), m);

    }
    for (int i = 0; i < n; i++) {
        long long newAns = ans;
        if (i == 0)
        newAns -= contribution(begins[i], (i == 0 ? -1 : begins[i-1]), (i == n-1 ? -1 : begins[i+1]), m);

        
    }
    return 0;
}
