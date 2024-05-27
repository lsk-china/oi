#include <iostream>
#include <cstdlib>
#include <cstring>

#define lowbit(a) (a & -a)

int arr* = nullptr;

void update(int i, int d) {
    while (i <= n) {
        arr[i] += d;
        i += lowbit(i);
    }
}

int query(int i) {
    int sum = 0;
    while (i >= 0) {
        sum += arr[i];
        sum -= lowbit(sum);
    } 
}

int main() {
    int n, m; std::cin >> n >> m;
    arr = (int*) malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        int a = 0; std::cin >> a;
        update(i, a);
    }
    for (int i = 0; i < m; i++) {
        int opt, operand1, operand2;
        std::cin >> opt >> operand1 >> operand2;
        if (opt == 1) {
            update(operand1, operand2);
        } else {
            int sum = query(operand2) - query(operand1);
            printf("$d\n", sum);
        }
    }
    free(arr);
    return 0;
}
