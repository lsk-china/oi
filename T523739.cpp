#include <iostream>

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                int a = i*100 + j*10 + k;
                if (i*i*i + j*j*j + k*k*k == a) {
                    std::cout << a << std::endl; 
                }
            }
        }
    }
    return 0;
}
