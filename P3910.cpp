#include <iostream>
#include <cmath>

#define MAX 1000000010

int main() {
    int n, m; std::cin >> n >> m;
    for (int i = sqrt(2*m); i >= 1; i--) {
        if ((2*m) % i != 0 || ((2*m) / i - i + 1) % 2 != 0) {
            continue;
        } 
        int a = ((2*m) / i - i + 1) / 2;
        if (a < 1 || a+i-1 > n) continue;
        std::cout << "[" << a << "," << a+i-1 << "]" << std::endl;
    }
    return 0;
}
