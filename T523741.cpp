#include <cstdio>

int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                if (i+j+k != 100) continue;
                if (i%3 != 0)     continue;
                if (i/3 + 3*j + 5*k != 100) continue;
                printf("%d %d %d\n", k, j, i);
            }
        }
    }
    return 0;
}
