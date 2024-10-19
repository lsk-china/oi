#include <iostream>
#include <cstring>

int n;
char string[710] = {0};

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> string[i];
        string[n+i] = string[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmpAns = 0;
        char thisColor = string[i];
        int ptr = i;
        if (thisColor == 'w') {
            while (ptr<i+n && (string[ptr] == thisColor || string[ptr] == 'w')) {
                ptr++;
                tmpAns ++;
            }
            thisColor = string[ptr];
            while (ptr<i+n && (string[ptr] == thisColor || string[ptr] == 'w')) {
                ptr++;
                tmpAns ++;
            }
            thisColor = string[ptr];
            while (ptr<i+n && (string[ptr] == thisColor || string[ptr] == 'w')) {
                ptr++;
                tmpAns ++;
            }

        } else {
            while (ptr<i+n && (string[ptr] == thisColor || string[ptr] == 'w')) {
                ptr++;
                tmpAns ++;
            }
            thisColor = string[ptr];
            while (ptr<i+n && (string[ptr] == thisColor || string[ptr] == 'w')) {
                ptr++;
                tmpAns ++;
            }

        }
        ans = std::max(ans, tmpAns);
    }
    std::cout << ans << std::endl; 
}
