/*
Khu vui chơi trẻ em thiết kế một cầu thang có N bậc để di chuyển lên đỉnh tháp. Sinh viên PTIT cũng được phép leo lên cầu thang này nhưng nhìn chung chân sinh viên PTIT khá là dài nên có thể đi từ 1 đến K bậc mỗi bước (chứ không chỉ là 1 bậc như trẻ em).

Hãy tính xem sinh viên PTIT có bao nhiêu cách để leo lên đến đỉnh.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm hai số nguyên dương N và K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).

Output:
Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 10^9+7.
*/

#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::vector<long long> dp(n + 1, 0);

        dp[0] = dp[1] = 1;
        for (long long i = 2; i <= n; ++i) {
            for (long long j = 1; j <= k; ++j) {
                if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }

        std::cout << dp[n] << "\n";
    }
}