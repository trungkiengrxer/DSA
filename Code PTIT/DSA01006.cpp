/*
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N theo thứ tự ngược. Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.

Input:
• Dòng đầu tiên đưa vào số lượng test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
• T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <string>
#include <vector>

void permutation(int n, std::vector<std::string> &a) {
    std::string s;
    for (int i = 0; i < n; ++i) s.push_back((i + 1) + '0');

    while (true) {
        a.push_back(s);

        int i = n - 2;
        while (i >= 0 && s[i] > s[i + 1]) --i;

        if (i < 0) return;

        int k = n - 1;
        while (s[k] < s[i]) --k;

        std::swap(s[i], s[k]);
        int left = i + 1, right = n - 1;
        while (left < right) std::swap(s[left++], s[right--]);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::string> a;
        permutation(n, a);

        for (int i = a.size() - 1; i >= 0; --i) std::cout << a[i] << " ";
        std::cout << "\n";
    }
}