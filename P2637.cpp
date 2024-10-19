#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>

#define MAX 1010

int n, m;
int prices[MAX] = {0};

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> prices[i];
    }
    std::sort(prices+1, prices+1+m);
    int price = 0, ans = 0;
    for (int i = m; i >= 1; i--) {
        int newAns = prices[i] * (m-i+1);
        if (newAns > ans && (m-i+1) <= n) {
            price  = prices[i];
            ans = newAns;
        }
    }
    std::cout << price << " " << ans << std::endl;
}
