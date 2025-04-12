/*
Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ 1 là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i-1 (2≤i≤n). Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:
[1, 2, 3, 4, 5 ]
[3, 5, 7, 9 ]
[8, 12, 16]
[20, 28]
[48]

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N số của mảng A[].
• T, N, A[i] thỏa mãn ràng buộc: 1 ≤ T ≤ 100; 1 ≤ N ≤ 10, 0 ≤ A[i] ≤ 10;

• Output:
Đưa ra tam giác tổng của mỗi test theo từng dòng. Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].
*/

#include <iostream>
#include <vector>

void backtrack(std::vector<int> &a, std::vector<std::vector<int>> &result) {
    result.push_back(a);

    if (a.size() == 1) return;

    std::vector<int> temp;
    for (int i = 0; i < a.size() - 1; ++i) temp.push_back(a[i] + a[i + 1]);
    backtrack(temp, result);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        backtrack(a, result);

        for (auto &element : result) {
            std::cout << "[";
            for (int i = 0; i < element.size(); ++i) {
                std::cout << element[i];
                if (i < element.size() - 1) std::cout << " ";
            }
            std::cout << "]\n";
        }
    }
}