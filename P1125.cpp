#include <iostream>
#include <algorithm>

int cnt[27] = {0};
const int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main() {
    int n; std::cin >> n;
    for (int i = 1; i <= n; i++) {
        char ch; std::cin >> ch;
        cnt[ch-'\a'] ++;
    }
    //std::sort(cnt+1, cnt+1+26);
    int maxn = 0; int minn = 114514;
    for (int i = 1; i <= 26; i++) {
        if (cnt[i] > maxn) maxn = cnt[i];
        if (cnt[i] > 0 && cnt[i] < minn) minn = cnt[i];
    }
    for (int i = 0; i < 25; i++) {
        if (maxn-minn == prime[i]) {
            std::cout << "Lucky Word" << std::endl << maxn-minn << std::endl;
            return 0;
        }
    }
    std::cout << "No Answer\n0" << std::endl;
    return 0;
}
