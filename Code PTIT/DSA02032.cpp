/*
Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:
{2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

Input: Dòng đầu tiên đưa vào số lượng bộ test T. Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống. T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.

Output: Đưa ra kết quả mỗi test theo từng dòng. Đầu tiên là số lượng  tổ hợp thỏa mãn. Mỗi tổ hợp được bao bởi cặp ký tự { } và cách nhau một dấu cách. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.
*/

#include <iostream>
#include <vector>

void backtrack(int start, int sum, int &x, int &n, std::vector<int> &a, std::vector<int> &temp, std::vector<std::vector<int>> &result) {
    if (sum == x) {
        result.push_back(temp);
        return;
    }

    if (sum > x) return;

    for (int i = start; i < n; ++i) {
        temp.push_back(a[i]);
        backtrack(i, sum + a[i], x, n, a, temp, result);
        temp.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> a(n);
        std::vector<int> temp;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        backtrack(0, 0, x, n, a, temp, result);

        if (result.empty()) {
            std::cout << "-1\n";
            continue;
        }

        std::cout << result.size() << " ";

        for (const auto &vector : result) {
            std::cout << "{";
            for (int i = 0; i < vector.size(); ++i) {
                std::cout << vector[i];
                if (i < vector.size() - 1) std::cout << " ";
            }
            std::cout << "} ";
        }
        std::cout << "\n";
    }
}