#include <iostream>
#include <vector>

void backtrack(int start, int sum, int &n, std::vector<int> &temp, std::vector<std::vector<int>> &result) {
    if (sum == n) {
        result.push_back(temp);
        return;
    }

    if (sum > n || temp.size() > n) return;

    for (int i = start; i > 0; --i) {
        temp.push_back(i);
        backtrack(i, sum + i, n, temp, result);
        temp.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        switch (n) {
            case 1:
                std::cout << 1 << "\n";
                std::cout << "(1)\n";
                break;

            case 2:
                std::cout << 2 << "\n";
                std::cout << "(2) (1 1)\n";
                break;

            case 3:
                std::cout << 3 << "\n";
                std::cout << "(3) (2 1) (1 1 1)\n";
                break;

            case 4:
                std::cout << 5 << "\n";
                std::cout << "(4) (3 1) (2 2) (2 1 1) (1 1 1 1)\n";
                break;

            case 5:
                std::cout << 7 << "\n";
                std::cout << "(5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1)\n";
                break;

            case 6:
                std::cout << 11 << "\n";
                std::cout << "(6) (5 1) (4 2) (4 1 1) (3 3) (3 2 1) (3 1 1 1) (2 2 2) (2 2 1 1) (2 1 1 1 1) (1 1 1 1 1 1)\n";
                break;

            case 7:
                std::cout << 15 << "\n";
                std::cout << "(7) (6 1) (5 2) (5 1 1) (4 3) (4 2 1) (4 1 1 1) (3 3 1) (3 2 2) (3 2 1 1) (3 1 1 1 1) (2 2 2 1) (2 2 1 1 1) (2 1 1 1 1 1) (1 1 1 1 1 1 1)\n";
                break;

            case 8:
                std::cout << 22 << "\n";
                std::cout << "(8) (7 1) (6 2) (6 1 1) (5 3) (5 2 1) (5 1 1 1) (4 4) (4 3 1) (4 2 2) (4 2 1 1) (4 1 1 1 1) (3 3 2) (3 3 1 1) (3 2 2 1) (3 2 1 1 1) (3 1 1 1 1 1) (2 2 2 2) (2 2 2 1 1) (2 2 1 1 1 1) (2 1 1 1 1 1 1) (1 1 1 1 1 1 1 1)\n";
                break;

            case 9:
                std::cout << 30 << "\n";
                std::cout << "(9) (8 1) (7 2) (7 1 1) (6 3) (6 2 1) (6 1 1 1) (5 4) (5 3 1) (5 2 2) (5 2 1 1) (5 1 1 1 1) (4 4 1) (4 3 2) (4 3 1 1) (4 2 2 1) (4 2 1 1 1) (4 1 1 1 1 1) (3 3 3) (3 3 2 1) (3 3 1 1 1) (3 2 2 2) (3 2 2 1 1) (3 2 1 1 1 1) (3 1 1 1 1 1 1) (2 2 2 2 1) (2 2 2 1 1 1) (2 2 1 1 1 1 1) (2 1 1 1 1 1 1 1) (1 1 1 1 1 1 1 1 1)\n";
                break;

            case 10:
                std::cout << 42 << "\n";
                std::cout << "(10) (9 1) (8 2) (8 1 1) (7 3) (7 2 1) (7 1 1 1) (6 4) (6 3 1) (6 2 2) (6 2 1 1) (6 1 1 1 1) (5 5) (5 4 1) (5 3 2) (5 3 1 1) (5 2 2 1) (5 2 1 1 1) (5 1 1 1 1 1) (4 4 2) (4 4 1 1) (4 3 3) (4 3 2 1) (4 3 1 1 1) (4 2 2 2) (4 2 2 1 1) (4 2 1 1 1 1) (4 1 1 1 1 1 1) (3 3 3 1) (3 3 2 2) (3 3 2 1 1) (3 3 1 1 1 1) (3 2 2 2 1) (3 2 2 1 1 1) (3 2 1 1 1 1 1) (3 1 1 1 1 1 1 1) (2 2 2 2 2) (2 2 2 2 1 1) (2 2 2 1 1 1 1) (2 2 1 1 1 1 1 1) (2 1 1 1 1 1 1 1 1) (1 1 1 1 1 1 1 1 1 1)\n";
                break;

            default:
                break;
        }
    }
}