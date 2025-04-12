/*
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N. Ví dụ với N = 3 ta có kết quả: 123, 132, 213, 231, 312, 321.

Input:
• Dòng đầu tiên đưa vào số lượng test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
• T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

void permutation(int n) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i + 1;

    while (true) {
        for (int i = 0; i < n; ++i) std::cout << a[i];
        std::cout << " ";

        int i = n - 2;
        while (i >= 0 && a[i] > a[i + 1]) --i;

        if (i < 0) return;

        int k = n - 1;
        while (a[k] < a[i]) --k;

        std::swap(a[i], a[k]);
        int left = i + 1, right = n - 1;
        while (left < right) std::swap(a[left++], a[right--]);

    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        permutation(n);
        std::cout << "\n";
    }
}