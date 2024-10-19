#include <iostream>

int n, m;
bool occupied[1010][7] = {0};

bool check_valid() {
	for (int i = 1; i <= n; i++) {
		if (!(
			occupied[1] == occupied[6] &&
			occupied[2] == occupied[5] &&
			occupied[3] == occupied[4]
		     ))
		       return false;	
	}
	return true;
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (occupied[i][j])
				std::cout << "X";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::cin >> n >> m;
	int occupied_count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			char ch; std::cin >> ch;
			occupied[i][j] = ch == 'X';
			if (ch == 'X') occupied_count++;	
		}
	}
	if (6*n - occupied_count < m || (6*n-occupied_count + m) % 2 != 0) {
		std::cout << "Impossible" << std::endl;
        return 0;
	}
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (occupied[i][j] ^ occupied[i][7-j]) {
                occupied[i][j] = true;
                occupied[i][7-j] = true;
                m--;
            }
        }
    }
    if (m < 0 || m % 2 == 1) {
        std::cout << "Impossible" << std::endl;
        return 0;
    } 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3 && m > 0; j++) {
            if (occupied[i][j]) continue;
            if (m > 0) {
                occupied[i][j] = true; occupied[i][7-j] = true;
                m -= 2; 
            } else {
                break;
            }
        }
    }
    print();
	return 0;
	
}
