#include <iostream>
#include <vector>

void solve() {
    int len; std::string str;
    std::cin >> len; std::cin >> str;
    long long ans = 0;
    std::string lastRemove = "";
    std::string thisRemove = "";
    while (str.size() != 0) {
        thisRemove += str[str.size() - 1];
        if (thisRemove != lastRemove) {
            ans ++;
            lastRemove = thisRemove;
            thisRemove = "";
        }
        str.pop_back();
    }
    std::cout << ans << std::endl;
}

int main() {
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}
