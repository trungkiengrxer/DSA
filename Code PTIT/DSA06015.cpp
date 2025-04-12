/*
Cho mảng A[] gồm N phần tử chưa được sắp xếp. Nhiệm vụ của bạn là sắp xếp các phần tử của mảng A[] theo thứ tự tăng dần bằng thuật toán Merge Sort.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N tương ứng với số phần tử của mảng A[]; phần thứ 2 là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N, A[i]≤10^6.

Output:
Đưa ra kết quả các test theo từng dòng.
*/

#include <iostream>
#include <vector>

void merge(std::vector<int> &a, int left, int mid, int right) {
    std::vector<int> l, r;

    for (int i = left; i <= mid; ++i) l.push_back(a[i]);
    for (int i = mid + 1; i <= right; ++i) r.push_back(a[i]);

    int i = 0, j = 0, k = left;

    while (i < l.size() && j < r.size()) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            ++i;
        } else {
            a[k] = r[j];
            ++j;
        }
        ++k;
    }

    while (i < l.size()) {
        a[k] = l[i];
        ++i;
        ++k;
    }

    while (j < r.size()) {
        a[k] = r[j];
        ++j;
        ++k;
    }
}

void merge_sort(std::vector<int> &a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        merge_sort(a, 0, n - 1);

        for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << "\n";
    }
}