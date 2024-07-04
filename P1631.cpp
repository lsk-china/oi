////
//// Created by lsk on 3/20/24.
////
//#include <cstdio>
//#include <cstdlib>
//#include <queue>
//#include <vector>
//
//#define pair_t std::pair<int, int>
//
//int main () {
//    int n;
//    scanf("%d", &n);
//    int *seq1 = (int *) malloc(sizeof(int)*n);
//    int *seq2 = (int *) malloc(sizeof(int)*n);
//    std::priority_queue<pair_t, std::vector<pair_t>, std::greater<pair_t>> resultQueue;
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &seq1[i]);
//    }
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &seq2[i]);
//    }
//    for (int i = 0; i < n; i++) {
//        resultQueue.push(std::make_pair(seq1[i] + seq2[0], 0));
//    }
//    for (int i = 0; i < n; i++) {
//        pair_t head = resultQueue.top();
//        resultQueue.pop();
//        printf("%d ", head.first);
//        head.first;
//    }
//    free(seq1);
//    free(seq2);
//    printf("\n");
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define mkpii(a, b) std::make_pair(a, b)
#define pii std::pair<int, int>
#define MAX 100010

int seq1[MAX] = {0};
int seq2[MAX] = {0};

int main() {
    int n; std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> seq1[i];
    for (int i = 1; i <= n; i++) std::cin >> seq2[i];
    std::priority_queue<int, std::vector<int>, std::greater<>> queue;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = seq1[i] + seq2[j];
            queue.push(sum);
            if (i*j >= n) break;
        }
    }
    for (int i = 0; i < n; i++) {
        int e = queue.top();
        std::cout << e << std::endl;
    }
    printf("\n");
}
