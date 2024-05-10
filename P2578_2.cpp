//
// Created by lsk on 5/10/24.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <map>

struct node {
    long long state;
    int distance;
};

void move1(int a[4][4]) {
    int tmp=a[1][1];
    a[1][1]=a[2][1],a[2][1]=a[3][1],a[3][1]=a[3][2];
    a[3][2]=a[3][3],a[3][3]=a[2][3],a[2][3]=a[1][3],a[1][3]=a[1][2],a[1][2]=tmp;
}

void move2(int a[4][4]) {
    int tmp=a[2][3];
    a[2][3]=a[2][2],a[2][2]=a[2][1],a[2][1]=tmp;
}

long long getDec(int a[4][4]){
    long long s=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            s=s*10+a[i][j];
    return s;
}

void updateArr(long long s,int a[4][4]){
    for(int i=3;i>=1;i--){
        for(int j=3;j>=1;j--){
            a[i][j]=s%10;
            s/=10;
        }
    }
}

int main() {
    int initState[4][4] = {0};
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            std::cin >> initState[i][j];
        }
    }
    std::map<struct node, int> path;
    std::queue<struct node> bfsQueue;

}