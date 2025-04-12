/*
Cho dãy số A[] gồm có N phần tử.
Nhiệm vụ của bạn là hãy kiểm tra tồn tại bộ ba (i, j, k) mà A[i] + A[j] + A[k] = K cho trước hay không.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N và K (1≤ N ≤5000, 0 ≤ K ≤ 10^9).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng là “YES” nếu tìm được bộ ba thỏa mãn, “NO” trong trường hợp ngược lại.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, num;
        bool found = false;

        std::cin >> n >> num;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                if (a[i] + a[j] + a[k] == num) {
                    found = true;
                    break;
                } else if (a[i] + a[j] + a[k] < num)
                    ++j;
                else
                    --k;
            }
        }

        if (found)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}