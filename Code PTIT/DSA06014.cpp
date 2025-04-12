/*
Cho số tự nhiên N. Hãy tìm cặp số nguyên tố đầu tiên có tổng là N. Nếu không tồn tại cặp số nguyên tố có tổng bằng N, hãy đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là một số N được ghi trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

std::vector<bool> is_prime(1e6 + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= 1e6; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= 1e6; j += i) is_prime[j] = false;
        }
    }
}

int main() {
    sieve();
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        bool found = false;
        std::cin >> n;
        for (long long i = 2; i <= n / 2; ++i) {
            if (is_prime[i] && is_prime[n - i]) {
                found = true;
                std::cout << i << " " << n - i << "\n";
                break;
            }
        }

        if (found) continue;
        else std::cout << "-1\n";
    }
}