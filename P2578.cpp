//
// Created by lsk on 4/23/24.
//
#include <cstdio>
#include <cstring>
#include <queue>

int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int cantor_expansion(int permutation[], int n) {
    int used[n + 1];
    memset(used, n, sizeof(used));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        used[permutation[i]] = 1;
        for (int j = 1; j < permutation[i]; j++)
            if (used[j] != 1)
                temp += 1;
        ans += factorial[n - 1 - i] * temp;
    }

    return ans + 1;
}

long long reverse_cantor_expansion(int n, long long m) {
    int ans[n + 1], used[n + 1];
    memset(ans, -1, sizeof (ans));
    memset(used, 0, sizeof (used));

    m = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        long long fac = factorial[i];
        int temp = m / fac + 1;
        m = m - (temp - 1) * fac;
        for (int j = 1; j <= temp; j++)
            if (used[j] == 1)
                temp++;

        ans[n - i] = temp;
        used[temp] = 1;
    }

    int result = 0, mul = 1;
    for (int i = n+1; i >= 1; i--) {
        result += mul * ans[i];
        mul *= 10;
    }
    return result;
}

int cantor(long long tmp) {
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

void unCantor(int in, int arr[4][4]) {
    printf("%d\n", in);
    int factorials[10] = {362880, 40320, 5040, 720, 120, 24, 6, 2, 1, 1};
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            arr[i][j] = in / factorials[(i-1) * 3 + (j-1)];
            in = in % factorials[(i-1) * 3 + (j-1)];
        }
    }
}

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

void printArr(int arr[4][4]) {
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printPath(long long state[362800], int currentCantor) {
    if (state[currentCantor] != 0) {
        printPath(state, cantor(state[currentCantor]));
    }
    int stateArr[4][4];
    updateArr(state[currentCantor], stateArr);
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            printf("%d ", stateArr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
//    int initState[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
//    printf("%d\n", cantor_expansion(initState, 9));
//    printf("%lld\n", reverse_cantor_expansion(8, 1));
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
    state[cantor(getDec(initState))] = 0;
    std::queue<long long> bfsQueue;
    bfsQueue.push(getDec(initState));
    while(!bfsQueue.empty()) {
        long long currentState = bfsQueue.front(); bfsQueue.pop();
        if (currentState == 12345678L) {
            break;
        }
        int currentStateArr[4][4];
        updateArr(currentState, currentStateArr);
        move1(currentStateArr);
        int move1StateCantor = cantor(getDec(currentStateArr));
        if (state[move1StateCantor] == -1) {
            state[move1StateCantor] = currentState;
            bfsQueue.push(getDec(currentStateArr));
        }
        updateArr(currentState, currentStateArr);
        move2(currentStateArr);
        int move2StateCantor = cantor(getDec(currentStateArr));
        if (state[move2StateCantor] == -1) {
            state[move2StateCantor] = currentState;
            bfsQueue.push(getDec(currentStateArr));
        }
    }
    printPath(state, cantor(12345678L));
    return 0;
}


