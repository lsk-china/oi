//
// Created by lsk on 4/3/24.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <iostream>

struct segment {
    int begin;
    int end;
    int id;
};

bool operator<(struct segment a, struct  segment b) {
    return a.end > b.end;
}

int main() {
//    std::priority_queue<struct segment> segments;
//    int n, k, begin, end;
//    scanf("%d %d", &n, &k);
//    int * segmentIndexes = (int *) malloc(sizeof (int) * k);
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &begin, &end);
//        segments.push({begin, end, i});
//    }
//    struct segment beginSegment = segments.top();
//    segments.pop();
//    std::priority_queue<struct segment> segments2;
//    for (int i = 0; i < k; i++) {
//
//    }
//    struct segment endSegment = segments.top();
//    printf("%d\n", beginSegment.begin - endSegment.end);
//    for (int i = 0; i < k; i++) {
//        printf("%d ", segmentIndexes[i]);
//    }
//    printf("\n");
//    free(segmentIndexes);
    int n, k;
    scanf("%d %d", &n, &k);
    std::vector<struct segment> segments(n);
    struct segment beginSegment = {-1, -1 , -1};
    for (int i = 0; i < n; i++) {
        int begin, end;
        scanf("%d %d", &begin, &end);
        struct segment seg = {begin, end, i};
        beginSegment = begin > beginSegment.begin ? seg : beginSegment;
        segments[i] = seg;
    }
    sort(segments.begin(), segments.end(), [](struct segment seg1, struct segment seg2) {
        return seg1.begin < seg2.begin;
    });
    int ans = -1;
    std::priority_queue<struct segment> segments2;
    for (int i = 0; i < n; i++) {
        if (i == beginSegment.id) {
            continue;
        }
        segments2.push(segments[i]);
        while(segments2.size() > k) {
            segments2.pop();
        }
        if (segments2.size() == k) {
            struct segment top = segments2.top();
            int newAns = top.end - beginSegment.begin;
            printf("newAns: %d\n", newAns);
            ans = ans < newAns ? newAns : ans;
        }
    }
    printf("%d\n", ans);
    while(segments2.empty()) {
        printf("%d ", segments2.top().id);
    }
    return 0;
}