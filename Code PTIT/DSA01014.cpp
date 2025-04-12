/*
Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s?

Các tập hợp là hoán vị của nhau chỉ được tính là một.

Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

Input:  Gồm nhiều bộ test (không quá 100 test).
Mỗi bộ test gồm 3 số nguyên n, k, s với 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155. Input kết thúc bởi 3 số 0.

Output:  Với mỗi test in ra số lượng các tập hợp thỏa mãn điều kiện đề bài.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void backtrack(int start, int sum, int &n, int &k, int &s, int &count, std::vector<int> &temp) {
    if (sum == s && temp.size() == k) {
        ++count;
        return;
    }
    if (sum > s || temp.size() > k) return;

    for (int i = start; i <= n; ++i) {
        temp.push_back(i);
        backtrack(i + 1, sum + i, n, k, s, count, temp);
        temp.pop_back();
    }
}

int main() {
    std::string string;

    while (std::getline(std::cin, string)) {
        std::stringstream ss(string);
        int n, k, s, count = 0;
        std::vector<int> temp;

        ss >> n >> k >> s;

        if (n == 0 && k == 0 && s == 0) break;
        backtrack(1, 0, n, k, s, count, temp);
        std::cout << count << "\n";
    }
}