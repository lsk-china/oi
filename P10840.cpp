#include <iostream>
#include <vector>
#define MAX 100000

int seq[MAX] = {0};
int n;

//bool opt() {
//    for (int i = 0; i < seq.size() - 1; i++) {
//        int thisVal = seq[i];
//        int nextVal = seq[i+1];
//        if (thisVal == nextVal) continue;
//        seq.erase(seq.begin() + i);
//        if (i+2 >= seq.size()) return true;
//        seq[i+1] = seq[i+2] + 1;
//        return true;    
//    }
//    return false;
//}

//int main() {
//    std::cin >> n;
//    for (int i = 0; i < n; i++) {
//        int a; std::cin >> a;
//        seq.push_back(a);
//    }
//    long long ans = 0;
//    while (opt()) {
//        ans ++;
//    }
//    printf("%lld\n", ans);
//    return 0;
//}
//
int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> seq[i];
    for (int i = 0; i < n-1; i++) {
        if (seq[i] != seq[i+1]) {
            std::cout << n-1 << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}
