/*
Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là dãy xâu Fibonacci nếu thỏa mãn tính chất:    G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1). Với phép cộng (+) là phép nối hai xâu với nhau.  Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1) của xâu Fibonacci thứ n.

Dữ liệu vào: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và i (1<N<93).
Số i đảm bảo trong phạm vi của xâu G(N) và không quá 18 chữ số.

Kết quả: Ghi ra màn hình kết quả tương ứng với từng bộ test.
*/

#include <iostream>
#include <vector>

std::vector<long long> len(94);

void gen_len() {
    len[1] = 1;
    len[2] = 1;
    for (long long i = 3; i < 94; ++i) len[i] = len[i - 1] + len[i - 2];
}

char find(long long n, long long k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';

    if (k <= len[n - 2])
        return find(n - 2, k);
    else
        return find(n - 1, k - len[n - 2]);
}

int main() {
    gen_len();
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, i;
        std::cin >> n >> i;
        std::cout << find(n, i) << "\n";
    }
}