/*
Cho số nguyên dương N. Hãy đếm số bước ít nhất để đưa N về 1 bằng cách thực hiện ba thao tác dưới đây:
Nếu N chia hết cho 2 bạn có thể giảm N = N/2.
Nếu N chia hết cho 3 bạn có thể giảm N = N/3.
Giảm N đi 1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được viết trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>

void backtrack(int n, int count, int &result) {
    if (n <= 0) return;

    if (n == 1) {
        result = std::min(result, count);
        return;
    }

    if (count > result) return;

    if (n % 3 == 0) backtrack(n / 3, count + 1, result);
    if (n % 2 == 0) backtrack(n / 2, count + 1, result);
    backtrack(n - 1, count + 1, result);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, result = 1e9;
        std::cin >> n;

        backtrack(n, 0, result);

        std::cout << result << "\n";
    }
}