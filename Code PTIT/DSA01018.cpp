/*
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử trước đó của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 5} thì tập con trước đó của X[] là {2, 3, 4}. Chú ý nếu tập con trong input là đầu tiên thì trước đó là tập con cuối cùng.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(k);

        std::vector<bool> permutation(n, true);

        for (int i = 0; i < k; ++i) {
            std::cin >> a[i];
            permutation[a[i] - 1] = false;
        }

        std::prev_permutation(permutation.begin(), permutation.end());

        for (int i = 0; i < n; ++i)
            if (!permutation[i]) std::cout << i + 1 << " ";
        std::cout << "\n";
    }
}