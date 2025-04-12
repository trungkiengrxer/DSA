/*
Cho dãy số A[] gồm có N phần tử. Một bộ 3 số (a, b, c) được gọi là bộ ba số Pytago nếu như a^2 + b^2 = c^2.
Nhiệm vụ của bạn là kiểm tra xem có tồn tại bộ ba số Pytago trong dãy số A[] hay không?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N (1≤ N ≤5000).
Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng “YES” nếu tìm được, và “NO” trong trường hợp ngược lại.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        bool found = false;
        std::cin >> n;

        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.rbegin(), a.rend());

        for (long long i = 0; i < n; ++i) {
            long long l = i + 1, r = n - 1;

            while (l < r) {
                if (a[l] * a[l] + a[r] * a[r] == a[i] * a[i]) {
                    found = true;
                    break;
                } else if (a[l] * a[l] + a[r] * a[r] < a[i] * a[i])
                    --r;
                else
                    ++l;
            }
        }

        if (found)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}