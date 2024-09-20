#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    for (int i = 0; i < 3; i++) {
        int res1 = a;
        int res2 = 0
        if (i == 0) {
            res2 = res1 + b;
        } else if (i == 1) {
            res2 = res1 - b;
        } else if (i == 2) {
            res2 = res1 * b;
        } else if (i == 3) {
            res2 = res1 / b;
        }
        for (int j = 0; j < 3; j++) {
            int res3 = 0;
            if (j == 0) {
                res3 = res2 + c;
            } else if (j == 1) {
                res3 = res2 - c;
            } else if (j == 2) {
                res3 = res2 * c;
            } else {
                res3 = res2 / c;
            }
            if (res3 == d) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}

