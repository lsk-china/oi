#include <iostream>
#include <funtional>
#include <algorithm>
#include <utility>

#define MAX 400005

int l[MAX] = {0}, r[MAX] = {0}, con[MAX] = {0}, a[MAX] = {0};
int n, m;

int main() {
    std::cin >> n >> m;
    long long ans, totalContribute = 0;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        l[i] = i == 1 ? a[i] : std::max(a[i - 1] + m, a[i]);
        r[i] = i == n ? a[i] + m - 1: std::min(a[i] + m - 1, a[i + 1] - 1);
        con[i] = r[i] - l[i] + 1;
        con[i] = con[i] > 0 ? con[i] : 0;
        totalContribute += con[i];
    }
    /*
     *AAAAAAA
     *   
     *    AAAAAA  
     *
     */
    for (int i = 1; i <= n; i++) {
        long long newAns = totalContribute - con[i] + m;
        if (i == 1) {
            newAns -= con[i+1];
            int newLeft2 = a[i + 1];
            int newCon = r[i+1] - newLeft2 + 1;
            newAns += newCon > 0 ? newCon : 0;
        } else if (i == n) {
            newAns -= con[i - 1];
            int newRight1 = a[i - 1] + m - 1;
            int newCon = newRight1 - l[i - 1] + 1; 
            newAns += newCon > 0 ? newCon : 0;
        } else {
            newAns -= con[i+1];
            newAns -= con[i-1];
            int newLeft1 = i == 2 ? l[1] : std::max(a[i-1] + ,)
        }
    }
}
