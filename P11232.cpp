#include <iostream>
#include <vector>
#define pii std::pair<int, int>
#define mkpii(a, b) std::make_pair(a, b)

struct car {
    int d, v, a;
};

car cars[100010] = {0};
std::vector<pii> vec;
int n, m, L, V;
int detectors[100010] = {0};

bool calc(int i, int j) {
    car c = cars[i];
    return (c.v*c.v + 2*c.a*(detectors[j]-c.d) > V*V);
}

void solve() {
    std::cin >> n >> m >> L >> V;
    for (int i = 1; i <= n; i++) {
        std::cin >> cars[i].d >> cars[i].v >> cars[i].a;
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> detectors[i];
    }
}





