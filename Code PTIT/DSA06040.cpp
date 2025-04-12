/*
Cho ba dãy số A[], B[], C[] gồm N1, N2, N3 phần tử đã được sắp xếp. Hãy đưa ra các phần tử có mặt trong cả ba dãy theo thứ tự tăng dần. Nếu không có đáp án, in ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm bốn dòng: dòng thứ nhất đưa vào N1, N2, N3 là số phần tử của mảng A[], B[], C[]; các dòng tiếp theo đưa vào 3 dãy A[], B[], C[].
Ràng buộc: 1≤T≤100; 1≤ N1, N2, N3 ≤10^6, 0≤ A[i], B[j], C[k] ≤10^18.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n1, n2, n3;
        std::cin >> n1 >> n2 >> n3;

        std::vector<long long> a(n1), b(n2), c(n3), result;

        for (long long i = 0; i < n1; ++i) std::cin >> a[i];
        for (long long i = 0; i < n2; ++i) std::cin >> b[i];
        for (long long i = 0; i < n3; ++i) std::cin >> c[i];

        long long i = 0, j = 0, k = 0;

        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && b[j] == c[k]) {
                result.push_back(a[i]);
                ++i;
                ++j;
                ++k;
            } else if (a[i] < b[j])
                ++i;
            else if (b[j] < c[k])
                ++j;
            else
                ++k;
        }

        if (result.empty()) {
            std::cout << "-1\n";
            continue;
        }

        for (long long i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << "\n";
    }
}