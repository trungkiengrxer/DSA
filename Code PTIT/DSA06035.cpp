/*
Cho dãy số A[] gồm có N phần tử.

Một dãy con liên tiếp được gọi là dãy tam giác nếu như dãy đó tăng dần rồi lại giảm dần, hay tồn tại i, j, k sao cho A[i] ≤ A[i+1] ≤ … ≤ A[k] >= A[k+1] >= … >= A[j].
Nhiệm vụ của bạn là hãy tìm dãy con liên tiếp là dãy tam giác có độ dài lớn nhất.
Lưu ý: Dãy đơn điệu không giảm hoặc không tăng cũng là dãy tam giác.
Ví dụ A[] = {10, 20, 30, 40} là một dãy tam giác.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N(1≤ N ≤ 100 000).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^6).

Output: 
Với mỗi test, in ra trên một dòng là độ dài của dãy con tìm được
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, max = 0;
        std::cin >> n;

        std::vector<int> a(n), increase(n, 1), decrease(n, 1);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) increase[i] = increase[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > a[i + 1]) decrease[i] = decrease[i + 1] + 1;
        }

        for (int i = 0; i < n; ++i) max = std::max(max, decrease[i] + increase[i] - 1);

        std::cout << max << "\n";
    }
}