//
// Created by lsk on 4/23/24.
//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

int getCantor(long long tmp) {   //根据九位数字获取对应的康托展开值{
    int a[9]={0},i=8,ans=0;
    while(tmp!=0){
        a[i]=tmp%10;
        tmp/=10;
        i--;
    }
    for(i=0;i<9;i++)
    {
        int x=0;int c=1,m=1;
        for(int j=i+1;j<9;j++)
        {
            if(a[j]<a[i])x++;
            m*=c;c++;
        }
        ans+=x*m;
    }
    return ans;
}

void move1(int a[4][4]) {    //操作一
    int tmp=a[1][1];
    a[1][1]=a[2][1],a[2][1]=a[3][1],a[3][1]=a[3][2];
    a[3][2]=a[3][3],a[3][3]=a[2][3],a[2][3]=a[1][3],a[1][3]=a[1][2],a[1][2]=tmp;
}

void move2(int a[4][4]) {    //操作二
    int tmp=a[2][3];
    a[2][3]=a[2][2],a[2][2]=a[2][1],a[2][1]=tmp;
}

long long atoi (int a[4][4]) {

}

int main() {
    int initState[4][4] = {0};
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            char c;
            do { c = getchar(); } while (c == '\n' || c == ' ');
            initState[i][j] = c - '0';
        }
    }
    long long state[362880] = {};
    memset(state, -1, sizeof(long long) * 362880);
    std::queue<long long> bfsQueue;
    bfsQueue.push(atoi(initState));
    while(!bfsQueue.empty()) {}

}


