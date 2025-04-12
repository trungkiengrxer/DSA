/*
Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử. Nhiệm vụ của bạn là hợp nhất hai mảng A[] và B[] để được một mảng mới đã được sắp xếp. Ví dụ A[] = {5, 7, 112, 9, 3, 6, 2 }, B[] = {1, 2, 6, -1, 0, 9} ta có kết quả là C[] = {-1, 1, 0, 2, 3, 5, 6, 6, 7, .

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m tương ứng với số phần tử của mảng A[] và B[]; dòng tiếp theo là n số A[i] ; dòng cuối cùng là m số B[i]; các số được viết cách nhau một vài khoảng trống.
T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤10^6; -10^8≤ A[i] ≤10^8.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
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
        int n, m;
        std::cin >> n >> m;

        std::vector<int> a(m + n);

        for (int i = 0; i < m + n; ++i) std::cin >> a[i];

        merge_sort(a, 0, m + n - 1);

        for (int i = 0; i < m + n; ++i) std::cout << a[i] << " ";
        std::cout << "\n";
    }
}