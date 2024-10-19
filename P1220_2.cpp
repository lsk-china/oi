#include <iostream>

int n, c;
int distance[105] = {0}, power[105] = {0}, sum[105] = {0};
int memory[105] = {0};

int search(int curr, int lastMin) {
    if (memory[curr] != -1) return memory[curr];
    if (curr < 0 || curr > n) return 0;

}

int main() {
    std::cin >> n >> c;
    memset(memory, -1, sizeof(memory));
    for (int i = 1; i <= n; i++) {
        std::cin >> distance[i] >> power[i];
        sum[i] = sum[i-1] + power[i]; 
    }

}
