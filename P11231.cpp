#include <iostream>
#include <algorithm>

int n;
int r[100010] = {0};

int main() {
    std::cin >> n;
    for (int i = 1; i <= n;  i++) {
        std::cin >> r[i];
    }
    std::sort(r+1, r+1+n);
    int l = 1;
    for (int i = 1; i <= n; i++) {
        if (r[i] <= r[l]) continue;
        l++;
    }
    std::cout << n-l+1 << std::endl;
    return 0;
}
