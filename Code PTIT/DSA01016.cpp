/*
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. Phép hoán vị vủa một cách được xem là giống nhau. Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

void backtrack(int start, int sum, int &n, std::vector<int> &a, std::vector<int> &temp, std::vector<std::vector<int>> &result) {
    if (sum == n) {
        result.push_back(temp);
        return;
    }

    if (sum > n || start > n) return;

    for (int i = start; i < n; ++i) {
        temp.push_back(a[i]);
        backtrack(i, sum + a[i], n, a, temp, result);
        temp.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> temp;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n; ++i) a[i] = n - i;
        backtrack(0, 0, n, a, temp, result);

        for (const auto &vector : result) {
            std::cout << "(";
            for (int i = 0; i < vector.size(); ++i) {
                std::cout << vector[i];
                if (i < vector.size() - 1) std::cout << " ";
            }
            std::cout << ") ";
        }
        std::cout << "\n";
    }
}