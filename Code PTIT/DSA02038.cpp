/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một và một số K < N.
Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], mỗi dãy đều được sắp xếp theo thứ tự tăng dần.
Các dãy con được liệt kê lần lượt theo thứ tự từ điển.

Input
Dòng đầu ghi số bộ test, mỗi test có 2 dòng:
Dòng đầu ghi hai số N và K (2 < K < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.

Output
Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, mỗi dãy con trên một dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(int start, int &n, int &k, std::vector<int> &a, std::vector<int> &temp, std::vector<std::vector<int>> &result) {
    if (temp.size() == k) {
        result.push_back(temp);
        return;
    }

    for (int i = start; i < n; ++i) {
        temp.push_back(a[i]);
        backtrack(i + 1, n, k, a, temp, result);
        temp.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        std::vector<int> temp;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());
        backtrack(0, n, k, a, temp, result);

        for (const auto &vector : result) {
            for (const int &num : vector) std::cout << num << " ";
            std::cout << "\n";
        }
    }
}