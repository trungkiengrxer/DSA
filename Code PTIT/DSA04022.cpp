/*
Xâu ký tự S được tạo ra bằng cách bổ sung dần các ký tự chữ cái Tiếng Anh in hoa như sau.

Bước 1: Chỉ có chữ cái A
Bước 2: Thêm chữ cái B vào giữa 2 chữ A => S = "ABA"
Bước 3: Thêm chữ cái C vào giữa 2 xâu đã có ở bước 2: S = "ABACABA"
Cứ như vậy cho đến bước thứ N (0 < N < 26)

Hãy xác định ký tự thứ K trong bước biến đổi thứ N là chữ cái gì?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 25, 1 ≤ K ≤ 2^N - 1).

Output:
Với mỗi test, in ra đáp án trên một dòng.
*/

#include <cmath>
#include <iostream>
#include <vector>

char find(int n, int k) {
    if (n == 1) return 'A';

    int len = pow(2, n - 1);

    if (k == len)
        return 'A' + n - 1;
    else if (k < len)
        return find(n - 1, k);
    else
        return find(n - 1, k - len);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << find(n, k) << "\n";
    }
}