#include <iostream>
#define MAX 50005

int a[MAX] = {0}, b[MAX] = {0}, c[MAX] = {0};
bool contain[2002][2002] = {0};

int main() {
    int n, m; std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[j] == i) contain[b[j]][c[j]] = true;
        }
        for (int )
    }
}
