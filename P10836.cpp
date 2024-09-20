#include <iostream>

char whichChar(int i) {
    return 'a' + (i % 26);
}

int main() {
    int n, m; std::cin >> n >> m;
    std::string a, b; std::cin >> a >> b;
    for (int i = 0; i < m; i++) {
        if (a.find("#") != -1) {
            a[a.find("#")] = whichChar(i);
        } else {
            break;
        }
    }
    std::cout << a << std::endl;
    return 0;
}
