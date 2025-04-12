/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.
Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con (đúng thứ tự trước sau) của A[] có tổng các phần tử là số lẻ.
Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

Input
Dòng đầu ghi số bộ test, mỗi test có 2 dòng:
Dòng đầu ghi số N (2 < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.

Output
Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số lẻ theo thứ tự từ điển tăng dần, mỗi dãy con trên một dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(int start, int sum, int &n, std::vector<int> &a, std::vector<int> &temp, std::vector<std::vector<int>> &result) {
    if (sum % 2) result.push_back(temp);

    for (int i = start; i < n; ++i) {
        temp.push_back(a[i]);
        backtrack(i + 1, sum + a[i], n, a, temp, result);
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

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.rbegin(), a.rend());
        backtrack(0, 0, n, a, temp, result);
        std::sort(result.begin(), result.end());

        for (const auto &vector : result) {
            for (int i = 0; i < vector.size(); ++i) std::cout << vector[i] << " ";
            std::cout << "\n";
        }
    }
}