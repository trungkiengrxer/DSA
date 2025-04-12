/*
Cho một tổ hợp chập K của N số nguyên dương đầu tiên (2 < K < N < 15).

Hãy xác định xem đó là tổ hợp thứ bao nhiêu nếu liệt kê tất cả các tổ hợp theo thứ tự tăng dần (tính từ 1).

Input
• Dòng đầu ghi số T là số bộ test (T < 10)
• Mỗi bộ test gồm 2 dòng
• Dòng đầu ghi 2 số nguyên dương N và K (2 < K < N < 15)
• Dòng tiếp theo ghi một tổ hợp chập K của các số nguyên dương từ 1 đến N.

Output
• Với mỗi bộ test, ghi ra trên một dòng số thứ tự của tổ hợp (tính từ 1, theo thứ tự liệt kê tăng dần).
*/

#include <iostream>
#include <vector>

void make_combination(int n, int k, std::vector<std::vector<int>> &combination) {
    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) a[i] = i + 1;

    while (true) {
        combination.push_back(a);

        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1) --i;

        if (i < 0) return;
        ++a[i];
        for (int j = i + 1; j < k; ++j) a[j] = a[j - 1] + 1;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, result;
        std::cin >> n >> k;

        std::vector<int> a(k);
        std::vector<std::vector<int>> combination;

        for (int i = 0; i < k; ++i) std::cin >> a[i];

        make_combination(n, k, combination);
        for (int i = 0; i < combination.size(); ++i) {
            if (combination[i] == a) {
                result = i + 1;
                break;
            }
        }

        std::cout << result << "\n";
    }
}