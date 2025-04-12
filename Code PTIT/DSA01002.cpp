/*
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử tiếp theo của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 4} thì tập con tiếp theo của X[] là {2, 3, 5}.

Input:
• Dòng đầu tiên đưa vào số lượng test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
• T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤10^3.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

void next_combination(int n, int k, std::vector<int> &a) {
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1) --i;
    if (i < 0) {
        ++i;
        a[i] = 1;
    } else
        ++a[i];
    for (int j = i + 1; j < k; ++j) a[j] = a[j - 1] + 1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(k);
        for (int i = 0; i < k; ++i) std::cin >> a[i];
        next_combination(n, k, a);
        for (int i = 0; i < k; ++i) std::cout << a[i] << " ";
        std::cout << "\n";
    }
}
