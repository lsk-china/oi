//
// Created by lsk on 5/11/24.
//
#include <iostream>
#include <stack>
#include <vector>

void solve() {
    int cardCount; std::cin >> cardCount;
    std::stack<int> cards;
    for (int i = 0; i < cardCount; i++) {
        int card; std::cin >> card;
        cards.push(card);
    }
    int max = cardCount, lastMax = 1;
    std::vector<int> newCards; std::vector<int> tmp;
    for (int i = 0; i < cardCount; i++) {
        int card = cards.top(); cards.pop();
        tmp.insert(tmp.begin(), card);
        lastMax = card > lastMax ? card : lastMax;
        if (card == max) {
            newCards.insert(newCards.end(), tmp.begin(), tmp.end());
            tmp.clear();
            max = lastMax - 1; lastMax = 1;
        }
    }
    newCards.insert(newCards.end(), tmp.begin(), tmp.end());
    for (int card : newCards) {
        printf("%d ", card);
    }
    printf("\n");
}

int main() {
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}