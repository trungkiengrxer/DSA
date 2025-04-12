#include <iostream>
#include <vector>

std::vector<bool> column, main_diag, second_diag;
std::vector<std::vector<long long>> a(8, std::vector<long long>(8));
long long max_scores;

void backtrack(long long row, long long scores) {
    if (row == 8) {
        max_scores = std::max(max_scores, scores);
        return;
    }

    for (long long col = 0; col < 8; ++col) {
        if (column[col] || main_diag[row - col + 8 - 1] || second_diag[row + col]) continue;
        column[col] = main_diag[row - col + 8 - 1] = second_diag[row + col] = true;
        backtrack(row + 1, scores + a[row][col]);
        column[col] = main_diag[row - col + 8 - 1] = second_diag[row + col] = false;
    }
}

int main() {
    long long t;
    std::cin >> t;

    for (int k = 1; k <= t; ++k) {
        max_scores = -1e18;
        column.assign(8, false);
        main_diag.assign(100, false);
        second_diag.assign(100, false);

        for (long long i = 0; i < 8; ++i) {
            for (long long j = 0; j < 8; ++j) std::cin >> a[i][j];
        }
        backtrack(0, 0);

        std::cout << "Test " << k << ": " << max_scores << "\n";
    }
}