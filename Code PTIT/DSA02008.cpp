/*
Cho ma trận vuông Ci,j cấp N (1<= i, j <= N<10) gồm N2 số tự nhiên và số tự nhiên K (các số trong ma trận không nhất thiết phải khác nhau và đều không quá 100, K không quá 10^4). Hãy viết chương trình lấy mỗi hàng, mỗi cột duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.

Dữ liệu vào: Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C.
Kết quả: dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách theo vị trí của số đó trong lần lượt từng hàng của ma trận. Xem ví dụ để hiểu rõ hơn.
*/

#include <iostream>
#include <vector>

void backtrack(int row, int sum, int &n, int &k, std::vector<int> &index, std::vector<bool> &used, std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &result) {
    if (sum == k && index.size() == n) {
        result.push_back(index);
        return;
    }

    if (sum > k || index.size() > n) return;

    for (int col = 0; col < n; ++col) {
        if (used[col]) continue;
        used[col] = true;
        index.push_back(col + 1);

        backtrack(row + 1, sum + a[row][col], n, k, index, used, a, result);

        index.pop_back();
        used[col] = false;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::vector<std::vector<int>> result;
    std::vector<int> index;
    std::vector<bool> used(n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) std::cin >> a[i][j];
    }

    backtrack(0, 0, n, k, index, used, a, result);

    std::cout << result.size() << "\n";

    for (const auto &vector : result) {
        for (const int &num : vector) std::cout << num << " ";
        std::cout << "\n";
    }
}