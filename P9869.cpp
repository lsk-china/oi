#include <iostream>
#define MAX 3010

int maxs[MAX] = {0}, mins[MAX] = {0};

int main() {
    int n, m; std::cin >> n >> m;
    std::string s;
    for (int i = 1; i <= n; i++) {
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            int c = (int) (s[j] - 'a');
            if (j == 0 || c < mins[i]) {
                mins[i] = c;
            }
            if (c > maxs[i]) {
                maxs[i] = c;
            }
        }     
    }

    return 0;
}
