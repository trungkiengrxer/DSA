/*
Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu có thể di chuyển theo chiều ngang, dọc, chéo. Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.

Input: Dòng đầu ghi số bộ test T (T<5). Mỗi bộ test ghi một số nguyên dương n duy nhất (không quá 10)

Output:  Ghi kết quả mỗi bộ test trên một dòng. Số cách đặt quân hậu.
*/

#include <iostream>
#include <vector>

std::vector<bool> cols, main_diag, second_diag;

void backtrack(int row, int n, int &result) {
    if (row == n) {
        ++result;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (cols[i] || main_diag[row - i + n - 1] || second_diag[row + i]) continue;

        cols[i] = main_diag[row - i + n - 1] = second_diag[row + i] = true;
        backtrack(row + 1, n, result);
        cols[i] = main_diag[row - i + n - 1] = second_diag[row + i] = false;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, result = 0;
        std::cin >> n;

        cols.resize(n, false);
        main_diag.resize(2 * n - 1, false);
        second_diag.resize(2 * n - 1, false);

        backtrack(0, n, result);
        
        std::cout << result << "\n";
    }
}