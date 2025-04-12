/*
Người ta tạo ra một dãy xâu ký tự nhị phân X[] trong đó:

X[1] = “0”
X[2] = “1”
X[i] = X[i-2] + X[i-1] với i>2
Với phép cộng (+) là phép nối hai xâu với nhau.

Cho hai số tự nhiên N và K (1<N<93; K đảm bảo trong phạm vi của xâu X[N]).
Hãy xác định ký tự thứ K trong xâu X[N] là ký tự ‘0’ hay ký tự ‘1’.

Input: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và K.

Output: Ghi ra màn hình kết quả tương ứng với từng bộ test.
*/

#include <iostream>
#include <vector>

std::vector<long long> len(94);

void gen_len() {
    len[1] = 1;
    len[2] = 1;
    for (long long i = 3; i < 94; ++i) len[i] = len[i - 1] + len[i - 2];
}

long long find(long long n, long long k) {
    if (n == 1) return 0;
    if (n == 2) return 1;

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
        long long n, k;
        std::cin >> n >> k;
        std::cout << find(n, k) << "\n";
    }
}