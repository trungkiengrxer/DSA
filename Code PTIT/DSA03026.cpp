/*
Cho hai số nguyên dương N và S. Hãy lựa chọn các chữ số phù hợp để tạo ra số nhỏ nhất và số lớn nhất có N chữ số sao cho tổng chữ số đúng bằng S.

Input
Chỉ có một dòng ghi hai số N và S. (0 < N <= 100; 0 <= S <= 900)

Output
Ghi ra hai số nhỏ nhất và lớn nhất tìm được, cách nhau một khoảng trống.
Nếu không thể tìm được thì ghi ra “-1 -1”
*/

#include <iostream>
#include <vector>

int main() {
    int n, s;
    std::cin >> n >> s;

    int temp = s;

    if (9 * n < s) {
        std::cout << -1 << " " << -1;
        return 0;
    }

    if (n > 1 && s == 0) {
        std::cout << -1 << " " << -1;
        return 0;
    }

    std::vector<int> num(n, 0);

    num[0] = 1;
    --temp;

    for (int i = n - 1; i >= 0; --i) {
        int digit = std::min(9, temp);
        num[i] += digit;
        temp -= digit;
    }

    if (temp > 0) {
        std::cout << -1 << " " << -1;
        return 0;
    }

    for (int i = 0; i < n; ++i) std::cout << num[i];
    std::cout << " ";

    num.assign(n, 0);
    temp = s;

    for (int i = 0; i < n; ++i) {
        int digit = std::min(9, temp);
        num[i] += digit;
        temp -= digit;
    }

    for (int i = 0; i < n; ++i) std::cout << num[i];
}