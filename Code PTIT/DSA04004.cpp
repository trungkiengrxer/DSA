/*
Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:
Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].

Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 50, 1 ≤ K ≤ 2N - 1).

Output:
Với mỗi test, in ra đáp án trên một dòng.
*/

#include <cmath>
#include <iostream>
#include <vector>

long long find(long long n, long long k) {
    if (n == 1) return 1;

    long long len = std::pow(2, n - 1);

    if (k == len)
        return n;
    else if (k < len)
        return find(n - 1, k);
    else
        return find(n - 1, k - len);
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        std::cout << find(n, k) << "\n";
    }
}