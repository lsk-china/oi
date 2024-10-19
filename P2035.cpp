#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>

int n, t;
int priorities[10010] = {0};

int main() {
    std::cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        std::cin >> priorities[i]; 
    }
    while (t--) {
        int max = -114514; int max_index = 0;
        for (int i = 1; i <= n; i++) {
            if (priorities[i] > max) {
                max = priorities[i];
                max_index = i;
            }
        }
        std::cout << max_index << std::endl;
        priorities[max_index] = 0;
        if (max % (n-1) == 0) {
            int t = max / (n-1);
            for (int i = 1; i <= n; i++) {
                if (i == max_index) continue;
                priorities[i] += t;
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (i == max_index) continue;
                priorities[i] += 1;
                max -= 1;
                if ((max % (n-1)) == 0) break;
            }
            int t = max / (n-1);
            for (int i = 1; i <= n; i++) {
                if (i == max_index) continue;
                priorities[i] += t;
            }
        }
    }
    return 0;
}
