//
// Created by lsk on 3/20/24.
//
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>

#define pair_t std::pair<int, int>

int main () {
    int n;
    scanf("%d", &n);
    int *seq1 = (int *) malloc(sizeof(int)*n);
    int *seq2 = (int *) malloc(sizeof(int)*n);
    std::priority_queue<pair_t, std::vector<pair_t>, std::greater<pair_t>> resultQueue;
    for(int i = 0; i < n; i++) {
        scanf("%d", &seq1[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &seq2[i]);
    }
    for (int i = 0; i < n; i++) {
        resultQueue.push(std::make_pair(seq1[i] + seq2[0], 0));
    }
    for (int i = 0; i < n; i++) {
        pair_t head = resultQueue.top();
        resultQueue.pop();
        printf("%d ", head.first);
        head.first;
    }
    free(seq1);
    free(seq2);
    printf("\n");
    return 0;
}
