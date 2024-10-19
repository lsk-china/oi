#include <iostream>
#include <algorithm>

#define MAX 1010

int square(int a) {
    return a*a;
}

int heights[MAX] = {0};
int n;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> heights[i];
    std::sort(heights+1, heights+1+n);
    long long ans = 1145141919810;
    for (int j = 0; j <= heights[n]; j++) {
        long long cost = 0;
        for (int i = 1; i <= n; i++) {
            if (heights[i]-j > 17) cost += square(heights[i]-j-17);
            if (heights[i] < j) cost += square(heights[i]-j);
        }
        ans = std::min(ans, cost);
    }
    std::cout << ans << std::endl;
    return 0;
}
