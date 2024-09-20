#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>

struct period {
    int start;
    int end;
    int duration;
};

int f[1000010] = {0};
struct period periods[1010] = {0};
int m, n, r;

int main() {
    std::cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        int startIn, endIn, durationIn; std::cin >> startIn >> endIn >> durationIn;
        periods[i].start = startIn;
        periods[i].end = endIn + r;
        periods[i].duration = durationIn;
    }
    std::sort(periods+1, periods+1+n, [](struct period p1, struct period p2) {
              return p1.start < p2.start; 
    });
    for (int i = 1; i <= m; i++) {
        period p = periods[i];
        if (p.start == 0) continue;
        f[i] = p.duration;
        for (int j = 1; j < i; j++) {
            if (periods[i].start >= periods[j].end) {
                f[i] = f[i] > (f[j] + periods[j].duration) ? f[i] : (f[j] + periods[i].duration);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = ans > f[i] ? ans : f[i];
    }
    std::cout << ans << std::endl;
}
