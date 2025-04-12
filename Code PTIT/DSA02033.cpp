/*
Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn:

• K không chứa chữ số 0
• Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần
• Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1.

Hãy liệt kê tất cả các số thỏa mãn theo thứ tự tăng dần.

Input
• Dòng đầu ghi số bộ test (không quá 10)
• Mỗi bộ test là 1 số nguyên dương N (2 < N < 10)

Output
Liệt kê tất cả các số thỏa mãn, mỗi số trên một dòng.
Sau mỗi test in ra một khoảng trống.
*/

#include <iostream>
#include <vector>

void backtrack(int n, std::vector<int> &a, std::vector<bool> &used) {
    if (a.size() == n) {
        for (auto num : a) std::cout << num;
        std::cout << "\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        if (!a.empty() && std::abs(i - a.back()) == 1) continue;
        used[i] = true;
        a.push_back(i);
        backtrack(n, a, used);
        a.pop_back();
        used[i] = false;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<bool> used(10, false);
        std::vector<int> a;

        backtrack(n, a, used);
    }
}