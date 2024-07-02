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

struct tree {
    int parent, value, left, right;
};

struct tree elements[MAX] = {0};
int input[MAX] = {0};
int n = 0;

void build(int rootIndex) {
    struct tree root = elements[rootIndex];
    root.parent = -1;
    root.value = input[1];
    for (int i = 2; i <= n; i++) {
        int v = input[i];
        int index = rootIndex;
find:   if (v > elements[index].value) {
            if (elements[index].right == 0) {
                elements[++index] = {
                        .parent = index - 1,
                        .value = v
                };
                elements[index - 1].right = index;
                index --;
            } else {
                index = elements[index].right;
                goto find;
            }
        } else {
            if (elements[index].left == 0) {
                elements[++index] = {
                        .parent = index - 1,
                        .value = v
                };
                elements[index - 1].left = index;
                index --;
            } else {
                index = elements[index].left;
                goto find;
            }
        }
    }
}

void solution2() {
    std::cin >> n;
}

int main() {

}


