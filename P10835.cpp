#include <iostream>

void solve() {
    int n, m; std::cin >> n >> m;
    if (n == 0 && m % 2 == 0) {
        std::cout << "Yes" << std::endl; 
    } else if (n != 0 && m % 2 == 1) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl; 
    }
}

int main() {
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) solve();
    return 0;
}

