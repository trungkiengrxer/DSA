/*
Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính chất tăng dần.

Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu.

Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê theo thứ tự từ điển.

Input
• Dòng đầu ghi số n (không quá 20)
• Dòng thứ 2 ghi n số của dãy a[]. Các số khác nhau từng đôi một và có giá trị không quá 100.

Output
• Ghi ra lần lượt các dãy con tăng dần theo thứ tự từ điển.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(int start, int n, int k, std::vector<std::vector<std::string>> &result, std::vector<std::string> &temp, std::vector<int> &a) {
    if (temp.size() == k) {
        result.push_back(temp);
        return;
    }

    for (int i = start; i < n; ++i) {
        if (!temp.empty() && a[i] <= std::stoi(temp.back())) continue;
        temp.push_back(std::to_string(a[i]));
        backtrack(i + 1, n, k, result, temp, a);
        temp.pop_back();
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::string> temp;
    std::vector<std::vector<std::string>> result;

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    for (int i = 2; i <= n; ++i) {
        backtrack(0, n, i, result, temp, a);
    }

    std::sort(result.begin(), result.end());

    for (auto &vector : result) {
        for (const auto &num : vector) std::cout << num << " ";
        std::cout << "\n";
    }
}