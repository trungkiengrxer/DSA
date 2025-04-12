/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là hoán vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng giảm dần từ trái qua phải.

Input
Dòng đầu ghi số N (1 < N < 9)
Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)

Output
Ghi mỗi hoán vị của dãy số trên một dòng
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

void backtrack(int n, std::vector<int> &a, std::vector<int> result, std::unordered_map<int, bool> used) {
    if (result.size() == n) {
        for (int num : result) std::cout << num << " ";
        std::cout << "\n";
        return;
    }

    for (auto num : a) {
        if (used[num]) continue;
        used[num] = true;
        result.push_back(num);
        backtrack(n, a, result, used);
        result.pop_back();
        used[num] = false;  
    }
}

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, bool> used;
    std::vector<int> a(n);
    std::vector<int> result;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        used[a[i]] = false;
    }

    std::sort(a.begin(), a.end());

    backtrack(n, a, result, used);
}