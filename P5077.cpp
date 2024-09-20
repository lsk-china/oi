#include <iostream>
#include <cmath>

int main() {
    long long n; std::cin >> n;
    for (int i = sqrt(2*n); i >= 1; i --) {
        if ((2*n)%i != 0 || ((2*n)/i-i+1) % 2 != 0) continue;
        int a = ((2*n) / i - i + 1) / 2;
//if (a<1) continue;
        std::cout << a << " " << a+i-1 << std::endl;
        return 0;
        //if ((-l*l + l - 2*n) % (2*l) == 0) {
        //    long long a = (-l*l + l -2*n)/(2*l);
        //    if (a<1) continue;
        //    std::cout << a << " " << l-a << std::endl;
        //}
    }
    return 0;
} 
