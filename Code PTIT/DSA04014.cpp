/*
Cho mảng A[] gồm N phần tử. Ta gọi cặp nghịch thế của mảng A[] là số các cặp i, j sao cho i<j và A[i]>A[j]. Đối với mảng đã được sắp xếp thì số cặp nghịch thế bằng 0. Mảng đã sắp theo thứ tự giảm dần có số đảo ngược cực đại. Nhiệm vụ của bạn là hãy đưa ra số cặp nghịch thế của mảng A[] gồm N phần tử.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N tương ứng với số phần tử của mảng A[]; phần thứ 2 là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10^6; 1≤A[i]≤10^18.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

long long count;

void merge(std::vector<long long> &a, long long l, long long mid, long long r) {
    std::vector<long long> left, right;

    for (long long i = l; i <= mid; ++i) left.push_back(a[i]);
    for (long long i = mid + 1; i <= r; ++i) right.push_back(a[i]);

    long long i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            ++i;
        } else {
            a[k] = right[j];
            ++j;
            count += left.size() - i;
        }
        ++k;
    }

    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
}

void merge_sort(std::vector<long long> &a, long long l, long long r) {
    long long mid = l + (r - l) / 2;

    if (l < r) {
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;

        std::cin >> n;
        count = 0;

        std::vector<long long> a(n);

        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        merge_sort(a, 0, n - 1);

        std::cout << count << "\n";
    }
}