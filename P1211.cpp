#include <iostream>

bool avail[10] = {0};
int n;

bool check(int a) {
    while (a > 0) {
        int x = a % 10;
        if (!avail[x]) return false;
        a /= 10;
    }
    return true;
}

int main () {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        avail[a] = true;
    }
    int ans = 0;
    for (int i = 100; i <= 999; i++) {
        if (!check(i)) continue;
        for (int j = 10; j <= 99; j++) {
            if (!check(j)) continue;
            int prod1 = i * (j % 10);
            if (!(100 <= prod1 && prod1 <= 999)) continue;
            if (!check(prod1)) continue;
            int prod2 = i * (j / 10);
            if (!(100 <= prod2 && prod2 <= 999)) continue;
            if (!check(prod2)) continue;
            int prod = i*j;
            if (!(1000 <= prod && prod <= 9999)) continue;
            if (!check(prod)) continue;
            ans ++;
        } 
    }
    std::cout << ans << std::endl;
    return 0;
}
