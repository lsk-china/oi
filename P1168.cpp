//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//#include <vector>
//#include <utility>
//
//int main() {
//    std::priority_queue<int, std::vector<int>, std::less<int>> ql;
//    int n, v, leftSize=1, rightSize=0, rightSmallest = 2147483647;
//    scanf("%d", &v);
//    scanf("%d", &n);
//    ql.push(v);
//    for (int i = 2; i <= n; i++) {
//        scanf("%d", &v);
//        if (v < rightSmallest && (leftSize - rightSmallest) == 1) {
//            ql.push(v);
//            leftSize ++;
//        } else {
//            rightSmallest = v;
//            rightSize ++;
//        }
//        if (i % 2 == 1) {
//            printf("%d\n", ql.top());
//        }
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

#define MAX 100010

void solution1() {
    int n; std::cin >> n;
    std::vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int a; std::cin >> a;
        vec.insert(std::upper_bound(vec.begin(), vec.end(), a), a);
        if (i % 2 == 1) std::cout << vec[(vec.size() - 1)/2] << std::endl;
    }
}

void solution2() {
       int n; std::cin >> n;
       std::priority_queue<int, std::vector<int>, std::less<int>> frontHalf;
       std::priority_queue<int, std::vector<int>, std::greater<int>> backHalf;
       int cnt = 0;
       for (int i = 1; i <= n; i++) {
           int a; std::cin >> a;
           if (frontHalf.empty()) {
               frontHalf.push(a);
           } else {
               if (frontHalf.top() < a) {
                   backHalf.push(a);
               } else {
                   frontHalf.push(a);
               }
               int k = i % 2 == 0 ? i / 2 : (i+1) / 2;
               if (frontHalf.size() < k) {
                   frontHalf.push(backHalf.top());
                   backHalf.pop();
               }
               if (frontHalf.size() > k) {
                   backHalf.push(frontHalf.top());
                   frontHalf.pop();
               }
           }
           if (i % 2 == 1) printf("%d\n", frontHalf.top());
       }
}

int main() {
    solution2();
}


