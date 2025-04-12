/*
Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.

Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.

Output:  Với mỗi test, ghi ra thứ tự bộ test và giá trị điểm lớn nhất đạt được trên một dòng.
*/

#include <iostream>
#include <vector>

std::vector<bool> columns, main_diag, second_diag;

void backtrack(int row, int &max_score, int score, std::vector<std::vector<int>> &board) {
    if (row == 8) {
        max_score = std::max(max_score, score);
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if (columns[col] || main_diag[row - col + 8 - 1] || second_diag[row + col]) continue;

        columns[col] = main_diag[row - col + 8 - 1] = second_diag[row + col] = true;
        backtrack(row + 1, max_score, score + board[row][col], board);
        columns[col] = main_diag[row - col + 8 - 1] = second_diag[row + col] = false;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        main_diag.resize(15, false);
        second_diag.resize(15, false);
        columns.resize(8, false);

        int max_score = -1e9;

        std::vector<std::vector<int>> board(8, std::vector<int>(8));

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) std::cin >> board[i][j];
        }

        backtrack(0, max_score, 0, board);

        std::cout << max_score << "\n";
    }
}