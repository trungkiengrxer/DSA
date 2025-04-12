/*
Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số M, N, K; dòng tiếp theo đưa vào M số của mảng A[];dòng tiếp theo đưa vào N số của mảng B[];các số được viết cách nhau một vài khoảng trống.
• T, M,N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N, A[i], B[i]≤10^6; 1≤ K≤N+M.

Output:
• Đưa ra giá trị phần tử thứ K của mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

void merge(std::vector<int> &a, std::vector<int> &b, std::vector<int> &merged) {
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            merged.push_back(a[i]);
            ++i;
        } else {
            merged.push_back(b[j]);
            ++j;
        }
    }

    while (i < a.size()) {
        merged.push_back(a[i]);
        ++i;
    }

    while (j < b.size()) {
        merged.push_back(b[j]);
        ++j;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<int> a(n), b(m), merged;

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < m; ++i) std::cin >> b[i];

        merge(a, b, merged);

        std::cout << merged[k - 1] << "\n";
    }
}