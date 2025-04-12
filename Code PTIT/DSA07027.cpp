/*
Cho dãy số A[] gồm N phần tử. Với mỗi A[i], bạn cần tìm phần tử bên phải đầu tiên lớn hơn nó. Nếu không tồn tại, in ra -1.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100000).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng N số R[i], với R[i] là giá trị phần tử đầu tiên lớn hơn A[i].
*/

#include <iostream>
#include <stack>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> result(n, -1);
        std::stack<int> stack;

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && a[i] >= stack.top()) stack.pop();
            if (!stack.empty()) result[i] = stack.top();
            stack.push(a[i]);
        }

        for (int i = 0; i < n; ++i) std::cout << result[i] << " ";
        std::cout << "\n";
    }
}
