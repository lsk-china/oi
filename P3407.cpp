#include <iostream>

#define MAX 100010

struct person {
    long long homePos;
    long long finalPos;
    bool direction;
};

long long n, t, q;
person persons[MAX] = {0};
int importants[MAX] = {0};

int main() {
    std::cin >> n >> t >> q;
    for (int i = 1; i <= n; i++) {
        long long homePosIn = 0; int directionIn = 0;
        std::cin >> homePosIn >> directionIn;
        persons[i].homePos = homePosIn;
        persons[i].direction = directionIn == 1;
    }
    for (int i = 1; i <= q; i++) {
        std::cin >> importants[i];
    }
    for (int i = 1; i <= n; i++) {
        person person = persons[i];
        if (person.direction) continue;
        if (i == 1) person.finalPos = person.homePos - t;
        else if (persons[i-1].direction) person.finalPos = std::max(person.homePos - t, (person.homePos + persons[i-1].homePos) / 2);
        else person.finalPos = std::max(person.homePos - t, persons[i-1].finalPos);
        persons[i] = person;
    }
    for (int i = n; i >= 1; i--) {
        person person = persons[i];
        if (!person.direction) continue;
        if (i == n) person.finalPos = person.homePos + t;
        else if (!persons[i+1].direction) person.finalPos = std::min(person.homePos + t, (person.homePos + persons[i+1].homePos) / 2);
        else person.finalPos = std::min(person.homePos + t, persons[i+1].finalPos);
        persons[i] = person;
    }
    for (int i = 1; i <= q; i++) {
        std::cout << persons[importants[i]].finalPos << std::endl;
    }
    return 0;
    
}
