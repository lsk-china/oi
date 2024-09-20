#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

#define pii std::pair<int, int>
#define mkpii(a, b) std::make_pair(a, b) 
/*
struct pair_hash {

    inline size_t fn(size_t x) {
        x ^= x >> 32;
        x *= 0xe9846af9b1a615d;
        x ^= x >> 32;
        x *= 0xe9846af9b1a615d;
        x ^= x >> 28;
        return x;
    }

    std::size_t operator() (const std::pair<int, int> &pairIn) const {
        std::size_t x = 114514 + 0x9e3779b9 + pairIn.first;
        //result = fn(result + 0x9e3779b9 + pairIn.first);
        //result = fn(result + 0x9e3779b9 + pairIn.second);
        x ^= x >> 32;
        x *= 0xe9846af9b1a615d;
        x ^= x >> 32;
        x *= 0xe9846af9b1a615d;
        x ^= x >> 28;
        x += 0x9e3779b9 + pairIn.second;
        x ^= x >> 32;
        x *= 0xe9846af9b1a615d;
        x ^= x >> 32;
        x *= 0xe9846af9b1a615d;
        x ^= x >> 28;
        return x;
    }
};
*/
std::set<pii> dedupe;
pii sPos[100010] = {mkpii(0,0)};
int sCnt = 1;
pii kPos = mkpii(0, 0);

int main() {
    int n, m; std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch; std::cin >> ch;
            if (ch == 'S') {
                sPos[sCnt] = mkpii(i, j);
                sCnt ++;
            } else if (ch = 'K') {
                kPos = mkpii(i, j);
            }
        }
    }
    for (int i = 1; i <= sCnt; i++) {
        pii s = sPos[i];
        int newX = s.first - kPos.first;
        int newY = s.second - kPos.second;
        int gcd = std::abs(std::__gcd(newX, newY));
        pii newPos = mkpii(newX / gcd, newY / gcd);
        dedupe.insert(newPos);
    }
    std::cout << dedupe.size() << std::endl;
    return 0;
}
