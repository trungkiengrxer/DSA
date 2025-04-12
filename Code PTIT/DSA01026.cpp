/*
Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” nếu thỏa mãn các điều kiện sau:

• Độ dài xâu ít nhất là 6
• Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6
• Không có 2 chữ số 8 nào ở cạnh nhau
• Không có nhiều hơn 3 chữ số 6 ở cạnh nhau.

Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

Input
Chỉ có 1 dòng ghi số N (5 < N < 16).

Output
Ghi ra các xâu ký tự phát lộc độ dài N, mỗi xâu trên một dòng.
*/

#include <iostream>
#include <vector>

bool is_valid(int n, std::vector<int> &a) {
    int count = 0;

    if (a[0] != 8 || a[n - 1] != 6) return false;

    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && a[i] == 8 && a[i + 1] == 8) return false;
        if (a[i] == 6) {
            ++count;
            if (count > 3) return false;
        } else
            count = 0;
    }

    return true;
}

void backtrack(int i, int n, std::vector<int> &a) {
    if (i == n) {
        if (is_valid(n, a)) {
            for (int j = 0; j < n; ++j) std::cout << a[j];
            std::cout << "\n";
        }
        return;
    }

    a[i] = 6;
    backtrack(i + 1, n, a);
    a[i] = 8;
    backtrack(i + 1, n, a);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    backtrack(0, n, a);
}