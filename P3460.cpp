//
// Created by lsk on 5/16/24.
//
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cstring>

struct node {
    int v; struct node *next;
};

void freeList(struct node *head) {
    if (head->next != nullptr) freeList(head->next);
    free(head);
}

void swap(struct node *head, int index1, int index2) {
    struct node *index0Node = head;
    for (int i = 0; i < index1 - 1; i++) index0Node = index0Node->next;
    struct node *index1Node = index0Node->next;
    struct node *index2Node = head;
    for (int i = 0; i < index2; i++) index2Node = index2Node->next;
    index0Node->next = index2Node;
    index2Node->next = index1Node;
    int d = index2 - index1;
    for (int i = 0; i < d; i++) index2Node = index2Node->next;
    index2Node->next = index2Node->next->next;
}

int main() {
    int n; std::cin>>n;
//    int *input = (int *) malloc(sizeof(int) * n * 2);
//    int *vis = (int *) malloc(sizeof(int) * n);
//    memset(vis, -1, sizeof(int) * n);
//    for (int i = 0; i < 2*n; i++) std::cin >> input[i];
//    std::vector<int> ans;
//    std::stack<int> stack;
//    for (int i = 0; i < 2*n; i++) {
//        if (vis[input[i]] != -1) {
//            std::swap(input[vis[i]], input[i]);
//
//        }
//    }
//    printf("%d\n", ans.size());
//    for (int i : ans) printf("%d\n", i);
//    free(input);
//    free(vis);
    struct node *head = (struct node *) malloc(sizeof(struct node));
    struct node *end = head;
    head->next = nullptr;
    for (int i = 0; i < 2*n; i++) {
        std::cin >> end->v;
        end->next = (struct node *) malloc(sizeof(struct node));
        end = end->next;
    }
    int *vis = (int *) malloc(sizeof(int) * n);
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
    }
    freeList(head);
    free(vis);
    return 0;
}