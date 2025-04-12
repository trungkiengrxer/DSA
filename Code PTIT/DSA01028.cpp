/*
Cho dãy số A[] có N phần tử. Hãy liệt kê tất cả các tổ hợp chập K của tập các phần tử khác nhau trong A[]. Các tổ hợp cần liệt kê theo thứ tự từ điển (tức là trong mỗi tổ hợp thì giá trị từ nhỏ đến lớn, và tổ hợp sau lớn hơn tổ hợp trước).

Input
Dòng đầu ghi hai số N và K.
Dòng thứ 2 ghi N số của mảng A[]. Các giá trị không quá 1000.
Dữ liệu đảm bảo số phần tử khác nhau của A[] không quá 20 và K không quá 10.

Output
Ghi ra lần lượt các tổ hợp tìm được, mỗi tổ hợp trên một dòng.
*/

#include <iostream>
#include <vector>
#include <set>

void backtrack(int start, int n, int k, std::vector<int> &a, std::vector<int> &result) {
    if (result.size() == k) {
        for (auto num : result) std::cout << num << " ";
        std::cout << "\n";
        return;
    }

    for (int i = start; i < n; ++i) {
        result.push_back(a[i]);
        backtrack(i + 1, n, k, a, result);
        result.pop_back();
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a;
    std::vector<int> result;
    std::set<int> set;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        set.insert(x);
    }

    for (auto element : set) a.push_back(element);
    backtrack(0, a.size(), k, a, result);
}