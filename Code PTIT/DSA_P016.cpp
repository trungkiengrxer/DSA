/*
Cho một bàn cờ 8 x 8, mỗi ô có một giá trị board[i][j] nhất định (0 ≤ board[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.

Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.

Output:  Với mỗi test, ghi ra thứ tự bộ test và giá trị điểm lớn nhất đạt được trên một dòng.
*/

#include <iostream>
#include <vector>

std::vector<bool> columns(8, false), main_diag(15, false), second_diag(15, false);

void backtrack(int row, int scores, int &max_scores, std::vector<std::vector<int>> &board) {
    if (row == 8) {
        max_scores = std::max(max_scores, scores);
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if (columns[col] || main_diag[row - col + 7] || second_diag[row + col]) continue;
        columns[col] = main_diag[row - col + 7] = second_diag[row + col] = true;
        backtrack(row + 1, scores + board[row][col], max_scores, board);
        columns[col] = main_diag[row - col + 7] = second_diag[row + col] = false;
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int k = 1; k <= t; ++k) {
        int max_scores = -1e9;
        std::vector<std::vector<int>> board(8, std::vector<int>(8));

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) std::cin >> board[i][j];
        }

        backtrack(0, 0, max_scores, board);

        std::cout << "Test " << k << ": " << max_scores << "\n";
    }
}