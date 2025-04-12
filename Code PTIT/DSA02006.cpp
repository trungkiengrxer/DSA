/*
Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K. Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho tổng các phần tử của dãy con đó đúng bằng K. Các phần tử của dãy số A[] được giả thuyết là nguyên dương và không có các phần tử giống nhau. Ví dụ với dãy con A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[] và số K; dòng tiếp theo đưa vào N phần tử của dãy số A[].
• T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤10; 1≤ K, A[i] ≤100.

Output:
• Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn yêu cầu bài toán theo thứ tự từ điển, trong đó mỗi dãy con được bao bởi các ký tự [, ]. Nếu không có dãy con nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(int start, int sum, int n, int k, std::vector<std::vector<int>> &result, std::vector<int> &a, std::vector<int> &current) {
    if (sum == k) {
        result.push_back(current);
        return;
    }

    if (sum > k || start == n) return;

    current.push_back(a[start]);
    backtrack(start + 1, sum + a[start], n, k, result, a, current);
    current.pop_back();

    backtrack(start + 1, sum, n, k, result, a, current);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        std::vector<int> current;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());

        backtrack(0, 0, n, k, result, a, current);

        if (result.empty()) {
            std::cout << "-1\n";
            continue;
        }

        for (auto &vector : result) {
            std::cout << "[";
            for (int i = 0; i < vector.size(); ++i) {
                std::cout << vector[i];
                if (i < vector.size() - 1) std::cout << " ";
            }
            std::cout << "] ";
        }

        std::cout << "\n";
    }
}