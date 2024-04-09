//
// Created by lsk on 3/25/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <queue>
#include <utility>
#include <vector>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *primes = (int *) malloc(n*sizeof(int));
    std::vector<int> humble; std::set<int> humbleSet;
    for (int i = 0; i < n; i++) {
        scanf("%d", &primes[i]);
        humble.push_back(primes[i]);
    }
    int m = 0, last = 0;
//    std::set<int> products; products.insert(1);
//    std::priority_queue<int, std::vector<int>, std::greater<int>> result; result.push(1);
//    for (int a = 0; a < k; a++) {
//        for (int i = 0; i < n; i++) {
//            int humble = result.top();
//            humble *= primes[i];
//            if (products.count(humble)) {
//                continue;
//            }
//            printf("%d\n", humble);
//            products.insert(humble);
//            result.push(humble);
//            if (result.size() == k) {
//                printf("%d\n", result.top());
//                free(primes);
//                return 0;
//            }
//        }
//    }
    while(m < n) {
        int top = humble.
    }
    free(primes);
    return 0;
}
